#include "mazearea.h"

MazeArea::MazeArea(QWidget *parent)
    : QWidget(parent),
      maze_image_(QSize(500, 500), QImage::Format_ARGB32),
      maze_path_(QSize(500, 500), QImage::Format_ARGB32) {
    setFocusPolicy(Qt::ClickFocus);
    clearMaze();
    clearPath();
}

void MazeArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, maze_image_, dirtyRect);
    painter.drawImage(dirtyRect, maze_path_, dirtyRect);
}

inline void MazeArea::clearImage(QImage &image) { image.fill(QColor(0, 0, 0, 0)); }

inline void MazeArea::clearMaze() { clearImage(maze_image_); }

inline void MazeArea::clearPath() {
    clearImage(maze_path_);
    isBeginSet_ = false;
    isEndSet_ = false;
}

void MazeArea::drawFromFile(QString filename) {
    clearMaze();
    clearPath();
    facade_->maze()->setFromFile(filename.toStdString());
    drawMaze();
}

void MazeArea::drawGenerate(int width, int height) {
    clearMaze();
    clearPath();
    facade_->maze()->setSizes(width, height);
    facade_->maze()->generateMaze();
    drawMaze();
}

void MazeArea::drawMaze() {
    // Draw crop
    QPainter painter(&maze_image_);
    painter.setPen(QPen(Qt::white, 2));
    painter.drawLine(0, 1, 500, 1);
    painter.drawLine(1, 500, 1, 0);
    // Draw walls
    cellWidth_ = 500.0 / facade_->maze()->getColumns();
    cellHeight_ = 500.0 / facade_->maze()->getRows();
    for (int i = 0; i < facade_->maze()->getRows(); i++) {
        for (int j = 0; j < facade_->maze()->getColumns(); j++) {
            int x0 = cellWidth_ * j;
            int y0 = cellHeight_ * i;
            int x1 = cellWidth_ * (j + 1);
            int y1 = cellHeight_ * (i + 1);
            if (facade_->maze()->getVerticalWalls()(i, j)) {
                if (j + 1 == facade_->maze()->getColumns()) {
                    x0--;
                    x1--;
                }
                painter.drawLine(x1, y0, x1, y1);
            }
            if (facade_->maze()->getHorizontalWalls()(i, j)) {
                if (i + 1 == facade_->maze()->getRows()) {
                    y0--;
                    y1--;
                }
                if (j + 1 == facade_->maze()->getColumns()) {
                    x0++;
                    x1++;
                }
                painter.drawLine(x0, y1, x1, y1);
            }
        }
    }
    update();
}

inline void MazeArea::gridSnap() {
    posBegin_.x = pointBegin_.x() / cellWidth_;
    posBegin_.y = pointBegin_.y() / cellHeight_;

    posEnd_.x = pointEnd_.x() / cellWidth_;
    posEnd_.y = pointEnd_.y() / cellHeight_;
}

void MazeArea::drawCells() {
    clearImage(maze_path_);
    QPainter painter(&maze_path_);
    if (isBeginSet_) {
        painter.setPen(QPen(Qt::yellow, 2, Qt::DotLine));
        painter.drawRect(QRect(QPoint(posBegin_.x * cellWidth_, posBegin_.y * cellHeight_),
                               QSize(cellWidth_, cellHeight_)));
    }
    if (isEndSet_) {
        painter.setPen(QPen(Qt::red, 2, Qt::DotLine));
        painter.drawRect(
            QRect(QPoint(posEnd_.x * cellWidth_, posEnd_.y * cellHeight_), QSize(cellWidth_, cellHeight_)));
    }
}

inline QPoint MazeArea::positionToPoint(s21::Position pos) {
    int xpos = pos.x * cellWidth_ + cellWidth_ / 2;
    int ypos = pos.y * cellHeight_ + cellHeight_ / 2;
    return QPoint(xpos, ypos);
}

void MazeArea::drawPath() {
    QPainter painter(&maze_path_);
    painter.setPen(QPen(Qt::yellow, 2));
    std::vector<s21::Position> way = facade_->findWay(posBegin_, posEnd_);
    if (way.empty()) return;
    for (unsigned i = 0; i < way.size() - 1; i++) {
        painter.drawLine(positionToPoint(way[i]), positionToPoint(way[i + 1]));
    }
}

void MazeArea::mousePressEvent(QMouseEvent *event) {
    if (facade_->maze()->getRows() != 0) {
        if (event->button() == Qt::LeftButton) {
            pointBegin_ = event->pos();
            isBeginSet_ = true;
        } else if (event->button() == Qt::RightButton) {
            pointEnd_ = event->pos();
            isEndSet_ = true;
        }
        gridSnap();
        drawCells();
        if (isBeginSet_ && isEndSet_) {
            drawPath();
        }
        update();
    }
}

void MazeArea::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        clearPath();
        update();
    }
}
