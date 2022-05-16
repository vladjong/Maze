/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#pragma once

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "mazearea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
    QAction *actionMaze_mode;
    QAction *actionCave_mode;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hl_panel;
    QVBoxLayout *vl_load;
    QLabel *label_filename;
    QVBoxLayout *vl_generate;
    QGridLayout *grid;
    QLabel *label_height;
    QSpinBox *spinBox_width;
    QLabel *label_width;
    QSpinBox *spinBox_height;
    QHBoxLayout *horizontalLayout;
    QLabel *label_loading;
    QLabel *label_generating;
    QWidget *wrapper;
    QGridLayout *gridLayout_2;
    MazeArea *render_area;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_load;
    QPushButton *btn_generate;
    QMenuBar *menuBar;
    QMenu *menuMaze;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty()) MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(530, 690);
        MainWindow->setMinimumSize(QSize(530, 690));
        MainWindow->setMaximumSize(QSize(530, 690));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #171923;"));
        actionMaze_mode = new QAction(MainWindow);
        actionMaze_mode->setObjectName(QString::fromUtf8("actionMaze_mode"));
        actionCave_mode = new QAction(MainWindow);
        actionCave_mode->setObjectName(QString::fromUtf8("actionCave_mode"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 10);
        hl_panel = new QHBoxLayout();
        hl_panel->setSpacing(5);
        hl_panel->setObjectName(QString::fromUtf8("hl_panel"));
        hl_panel->setContentsMargins(5, 0, 5, -1);
        vl_load = new QVBoxLayout();
        vl_load->setSpacing(5);
        vl_load->setObjectName(QString::fromUtf8("vl_load"));
        vl_load->setContentsMargins(5, -1, 5, -1);
        label_filename = new QLabel(centralwidget);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        vl_load->addWidget(label_filename);

        hl_panel->addLayout(vl_load);

        vl_generate = new QVBoxLayout();
        vl_generate->setSpacing(15);
        vl_generate->setObjectName(QString::fromUtf8("vl_generate"));
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));
        label_height = new QLabel(centralwidget);
        label_height->setObjectName(QString::fromUtf8("label_height"));
        label_height->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        grid->addWidget(label_height, 1, 0, 1, 1);

        spinBox_width = new QSpinBox(centralwidget);
        spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
        spinBox_width->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;"));
        spinBox_width->setMinimum(1);
        spinBox_width->setMaximum(50);
        spinBox_width->setValue(10);

        grid->addWidget(spinBox_width, 0, 1, 1, 1);

        label_width = new QLabel(centralwidget);
        label_width->setObjectName(QString::fromUtf8("label_width"));
        label_width->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        grid->addWidget(label_width, 0, 0, 1, 1);

        spinBox_height = new QSpinBox(centralwidget);
        spinBox_height->setObjectName(QString::fromUtf8("spinBox_height"));
        spinBox_height->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;\n"
                              ""));
        spinBox_height->setMinimum(1);
        spinBox_height->setMaximum(50);
        spinBox_height->setValue(10);

        grid->addWidget(spinBox_height, 1, 1, 1, 1);

        vl_generate->addLayout(grid);

        hl_panel->addLayout(vl_generate);

        gridLayout->addLayout(hl_panel, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, 5, -1);
        label_loading = new QLabel(centralwidget);
        label_loading->setObjectName(QString::fromUtf8("label_loading"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_loading->sizePolicy().hasHeightForWidth());
        label_loading->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_loading->setFont(font);
        label_loading->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));
        label_loading->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_loading);

        label_generating = new QLabel(centralwidget);
        label_generating->setObjectName(QString::fromUtf8("label_generating"));
        sizePolicy.setHeightForWidth(label_generating->sizePolicy().hasHeightForWidth());
        label_generating->setSizePolicy(sizePolicy);
        label_generating->setFont(font);
        label_generating->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));
        label_generating->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_generating);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        wrapper = new QWidget(centralwidget);
        wrapper->setObjectName(QString::fromUtf8("wrapper"));
        wrapper->setMinimumSize(QSize(520, 520));
        wrapper->setStyleSheet(QString::fromUtf8("background-color:#171923"));
        gridLayout_2 = new QGridLayout(wrapper);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(10, 10, 10, 10);
        render_area = new MazeArea(wrapper);
        render_area->setObjectName(QString::fromUtf8("render_area"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(render_area->sizePolicy().hasHeightForWidth());
        render_area->setSizePolicy(sizePolicy1);
        render_area->setMinimumSize(QSize(500, 500));

        gridLayout_2->addWidget(render_area, 0, 0, 1, 1);

        gridLayout->addWidget(wrapper, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, -1, 5, -1);
        btn_load = new QPushButton(centralwidget);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        btn_load->setMinimumSize(QSize(0, 35));
        btn_load->setMaximumSize(QSize(16777215, 30));
        btn_load->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;\n"
                              "color: #FFFFFF;\n"
                              "background-color: #AF2B36;\n"
                              "border: none;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "background: #171923;\n"
                              "color: #AF2B36;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "background: #171923;\n"
                              "color: #FCFEF1;\n"
                              "}"));

        horizontalLayout_2->addWidget(btn_load);

        btn_generate = new QPushButton(centralwidget);
        btn_generate->setObjectName(QString::fromUtf8("btn_generate"));
        btn_generate->setMinimumSize(QSize(0, 35));
        btn_generate->setMaximumSize(QSize(16777215, 30));
        btn_generate->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;\n"
                              "color: #FFFFFF;\n"
                              "background-color: #AF2B36;\n"
                              "border: none;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "background: #171923;\n"
                              "color: #AF2B36;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "background: #171923;\n"
                              "color: #FCFEF1;\n"
                              "}"));

        horizontalLayout_2->addWidget(btn_generate);

        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 530, 21));
        menuMaze = new QMenu(menuBar);
        menuMaze->setObjectName(QString::fromUtf8("menuMaze"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMaze->menuAction());
        menuMaze->addAction(actionMaze_mode);
        menuMaze->addAction(actionCave_mode);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Maze", nullptr));
        actionMaze_mode->setText(QCoreApplication::translate("MainWindow", "Maze mode", nullptr));
#if QT_CONFIG(shortcut)
        actionMaze_mode->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif  // QT_CONFIG(shortcut)
        actionCave_mode->setText(QCoreApplication::translate("MainWindow", "Cave mode", nullptr));
#if QT_CONFIG(shortcut)
        actionCave_mode->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif  // QT_CONFIG(shortcut)
        label_filename->setText(QString());
        label_height->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        label_width->setText(QCoreApplication::translate("MainWindow", "Width:", nullptr));
        label_loading->setText(QCoreApplication::translate("MainWindow", "Loading", nullptr));
        label_generating->setText(QCoreApplication::translate("MainWindow", "Generating", nullptr));
        btn_load->setText(QCoreApplication::translate("MainWindow", "Load from file", nullptr));
        btn_generate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        menuMaze->setTitle(QCoreApplication::translate("MainWindow", "Maze", nullptr));
    }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE
