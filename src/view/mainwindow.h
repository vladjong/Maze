#pragma once

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

#include "../facade/facade.h"
#include "cavewindow.h"
#include "export.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 private:
    Ui::MainWindow *ui;
    CaveWindow *caveWindow;

 public:
    explicit MainWindow(s21::Facade *facade, QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void on_btn_load_clicked();
    void on_btn_generate_clicked();
    void on_actionCave_mode_triggered();
    void on_actionMaze_mode_triggered();
};

QString truncater(QString str, int size);
void showMessageBox(QWidget *parent, QString message);
