#pragma once

#include <QtGui/QImage>
#include <QtGui/QPaintEvent>
#include <QtGui/QPainter>
#include <QtWidgets/QWidget>

#include "../facade/facade.h"

class CaveArea : public QWidget {
    Q_OBJECT

 private:
    s21::Facade *facade_;
    QImage cave_image_;
    double cellWidth_, cellHeight_;

    void paintEvent(QPaintEvent *event) override;
    inline void clearCave();

 public:
    explicit CaveArea(QWidget *parent = nullptr);
    void setFacade(s21::Facade *facade) { facade_ = facade; }
    void drawFromFile(QString filename);
    void drawGenerate(int width, int height, int chance);
    void drawCave();
};
