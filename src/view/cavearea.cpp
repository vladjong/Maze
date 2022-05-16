#include "cavearea.h"

CaveArea::CaveArea(QWidget *parent) : QWidget(parent), cave_image_(QSize(500, 500), QImage::Format_ARGB32) {
    setFocusPolicy(Qt::ClickFocus);
    clearCave();
}

void CaveArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, cave_image_, dirtyRect);
}

inline void CaveArea::clearCave() { cave_image_.fill(QColor(0, 0, 0, 0)); }

void CaveArea::drawFromFile(QString filename) {
    facade_->cave()->readFile(filename.toStdString());
    drawCave();
}

void CaveArea::drawGenerate(int width, int height, int chance) {
    facade_->cave()->generateMap(chance, width, height);
    drawCave();
}

void CaveArea::drawCave() {
    clearCave();
    // Draw crop
    QPainter painter(&cave_image_);
    painter.setPen(QPen(Qt::white, 1));
    painter.drawRect(0, 0, 499, 499);
    // Draw cells
    painter.setBrush(QBrush(Qt::white));
    cellWidth_ = 500.0 / facade_->cave()->getCols();
    cellHeight_ = 500.0 / facade_->cave()->getRows();
    for (int i = 0; i < facade_->cave()->getRows(); i++) {
        for (int j = 0; j < facade_->cave()->getCols(); j++) {
            if (facade_->cave()->map()(i, j)) {
                painter.drawRect(
                    QRect(QPoint(cellWidth_ * j, cellHeight_ * i), QSize(cellWidth_, cellHeight_)));
            }
        }
    }
    update();
}
