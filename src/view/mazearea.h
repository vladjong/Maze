#pragma once

#include <QtGui/QImage>
#include <QtGui/QKeyEvent>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtWidgets/QWidget>

#include "../facade/facade.h"

class MazeArea : public QWidget {
    Q_OBJECT

 private:
    s21::Facade *facade_;
    QImage maze_image_, maze_path_;
    QPoint pointBegin_, pointEnd_;
    s21::Position posBegin_, posEnd_;
    double cellWidth_, cellHeight_;
    bool isBeginSet_, isEndSet_;

    void paintEvent(QPaintEvent *event) override;
    inline void clearMaze();
    inline void clearPath();
    inline void clearImage(QImage &image);
    inline void gridSnap();
    inline QPoint positionToPoint(s21::Position pos);
    void drawMaze();
    void drawCells();
    void drawPath();

 protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

 public:
    explicit MazeArea(QWidget *parent = nullptr);
    void setFacade(s21::Facade *facade) { facade_ = facade; }
    void drawFromFile(QString filename);
    void drawGenerate(int width, int height);
};
