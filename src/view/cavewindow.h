#pragma once

#include <QtCore/QTimer>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>

#include "../facade/facade.h"
#include "export.h"

namespace Ui {
class CaveWindow;
}

class CaveWindow : public QDialog {
    Q_OBJECT

 private:
    Ui::CaveWindow *ui;
    s21::Facade *facade_;
    QTimer *timer_;

 public:
    explicit CaveWindow(s21::Facade *facade, QWidget *parent = nullptr);
    ~CaveWindow();

 private slots:
    void on_btn_loadding_clicked();
    void on_slider_gen_valueChanged(int value);
    void on_btn_step_clicked();
    void on_btn_gen_clicked();
    void on_timerOverflow();
};
