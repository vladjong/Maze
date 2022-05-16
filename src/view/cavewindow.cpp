#include "cavewindow.h"

#include "mainwindow.h"
#include "ui_cavewindow.h"

CaveWindow::CaveWindow(s21::Facade *facade, QWidget *parent)
    : QDialog(parent), ui(new Ui::CaveWindow), facade_(facade), timer_(new QTimer(this)) {
    ui->setupUi(this);
    ui->render_area->setFacade(facade);
    connect(timer_, SIGNAL(timeout()), this, SLOT(on_timerOverflow()));
}

CaveWindow::~CaveWindow() {
    delete ui;
    delete timer_;
}

void CaveWindow::on_btn_loadding_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, ("Open file"), USER_APP "datasets/", "*.txt");
    if (filename.isEmpty()) return;
    try {
        ui->render_area->drawFromFile(filename);
    } catch (std::exception &ex) {
        showMessageBox(this, "Wrong file format");
    }
    ui->label_filename->setText(truncater(filename, 14));
}

void CaveWindow::on_slider_gen_valueChanged(int value) {
    ui->label_gen_num->setText(QString::number(value));
    if (value) {
        int ms = (101 - value) * 10;
        timer_->start(ms);
    } else {
        timer_->stop();
    }
}

void CaveWindow::on_btn_step_clicked() {
    facade_->cave()->setLimits(ui->spinBox_lim_birth->value(), ui->spinBox_lim_death->value());
    facade_->cave()->updateMap();
    ui->render_area->drawCave();
}

void CaveWindow::on_btn_gen_clicked() {
    facade_->cave()->generateMap(ui->spinBox_chanse->value(), ui->spinBox_height->value(),
                                 ui->spinBox_width->value());
    ui->render_area->drawCave();
}

void CaveWindow::on_timerOverflow() { emit ui->btn_step->clicked(); }
