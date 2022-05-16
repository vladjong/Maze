/********************************************************************************
** Form generated from reading UI file 'cavewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "cavearea.h"

QT_BEGIN_NAMESPACE

class Ui_CaveWindow {
 public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_loading;
    QLabel *label_filename;
    QPushButton *btn_loadding;
    QLabel *label_config;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_lim_death;
    QLabel *label_lim_birth;
    QSpinBox *spinBox_lim_birth;
    QLabel *label_lim_death;
    QLabel *label_gen;
    QGridLayout *gridLayout_2;
    QLabel *label_width;
    QSpinBox *spinBox_chanse;
    QLabel *label_chanse;
    QPushButton *btn_gen;
    QSpinBox *spinBox_width;
    QLabel *label_hight;
    QSpinBox *spinBox_height;
    QLabel *label_step;
    QGridLayout *gridLayout_5;
    QLabel *label_gen_num;
    QSlider *slider_gen;
    QPushButton *btn_step;
    QWidget *wrapper;
    QGridLayout *gridLayout_4;
    CaveArea *render_area;

    void setupUi(QDialog *CaveWindow) {
        if (CaveWindow->objectName().isEmpty()) CaveWindow->setObjectName(QString::fromUtf8("CaveWindow"));
        CaveWindow->resize(800, 610);
        CaveWindow->setMinimumSize(QSize(800, 610));
        CaveWindow->setMaximumSize(QSize(800, 610));
        CaveWindow->setStyleSheet(QString::fromUtf8("background-color: #171923;"));
        gridLayout_3 = new QGridLayout(CaveWindow);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 10, 5, 10);
        label_loading = new QLabel(CaveWindow);
        label_loading->setObjectName(QString::fromUtf8("label_loading"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_loading->setFont(font);
        label_loading->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));
        label_loading->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_loading);

        label_filename = new QLabel(CaveWindow);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setMinimumSize(QSize(0, 30));
        label_filename->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(14);
        label_filename->setFont(font1);
        label_filename->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        verticalLayout->addWidget(label_filename);

        btn_loadding = new QPushButton(CaveWindow);
        btn_loadding->setObjectName(QString::fromUtf8("btn_loadding"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_loadding->sizePolicy().hasHeightForWidth());
        btn_loadding->setSizePolicy(sizePolicy);
        btn_loadding->setMinimumSize(QSize(0, 40));
        btn_loadding->setMaximumSize(QSize(16777215, 40));
        btn_loadding->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;\n"
                              "color: #FFFFFF;\n"
                              "background-color: #AF2B36;\n"
                              "border: none;\n"
                              "margin-top: 5px;\n"
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

        verticalLayout->addWidget(btn_loadding);

        label_config = new QLabel(CaveWindow);
        label_config->setObjectName(QString::fromUtf8("label_config"));
        label_config->setFont(font);
        label_config->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));
        label_config->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_config);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        spinBox_lim_death = new QSpinBox(CaveWindow);
        spinBox_lim_death->setObjectName(QString::fromUtf8("spinBox_lim_death"));
        spinBox_lim_death->setMinimumSize(QSize(0, 34));
        spinBox_lim_death->setMaximumSize(QSize(16777215, 34));
        spinBox_lim_death->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;"));
        spinBox_lim_death->setMinimum(1);
        spinBox_lim_death->setMaximum(7);
        spinBox_lim_death->setValue(4);

        gridLayout->addWidget(spinBox_lim_death, 4, 1, 1, 1);

        label_lim_birth = new QLabel(CaveWindow);
        label_lim_birth->setObjectName(QString::fromUtf8("label_lim_birth"));
        label_lim_birth->setMinimumSize(QSize(0, 30));
        label_lim_birth->setMaximumSize(QSize(16777215, 30));
        label_lim_birth->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        gridLayout->addWidget(label_lim_birth, 5, 0, 1, 1);

        spinBox_lim_birth = new QSpinBox(CaveWindow);
        spinBox_lim_birth->setObjectName(QString::fromUtf8("spinBox_lim_birth"));
        spinBox_lim_birth->setMinimumSize(QSize(0, 34));
        spinBox_lim_birth->setMaximumSize(QSize(16777215, 34));
        spinBox_lim_birth->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;"));
        spinBox_lim_birth->setMinimum(1);
        spinBox_lim_birth->setMaximum(7);
        spinBox_lim_birth->setValue(4);

        gridLayout->addWidget(spinBox_lim_birth, 5, 1, 1, 1);

        label_lim_death = new QLabel(CaveWindow);
        label_lim_death->setObjectName(QString::fromUtf8("label_lim_death"));
        label_lim_death->setMinimumSize(QSize(0, 30));
        label_lim_death->setMaximumSize(QSize(16777215, 30));
        label_lim_death->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        gridLayout->addWidget(label_lim_death, 4, 0, 1, 1);

        verticalLayout->addLayout(gridLayout);

        label_gen = new QLabel(CaveWindow);
        label_gen->setObjectName(QString::fromUtf8("label_gen"));
        label_gen->setFont(font);
        label_gen->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));
        label_gen->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_gen);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_width = new QLabel(CaveWindow);
        label_width->setObjectName(QString::fromUtf8("label_width"));
        label_width->setMinimumSize(QSize(0, 30));
        label_width->setMaximumSize(QSize(16777215, 30));
        label_width->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        gridLayout_2->addWidget(label_width, 1, 0, 1, 1);

        spinBox_chanse = new QSpinBox(CaveWindow);
        spinBox_chanse->setObjectName(QString::fromUtf8("spinBox_chanse"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_chanse->sizePolicy().hasHeightForWidth());
        spinBox_chanse->setSizePolicy(sizePolicy1);
        spinBox_chanse->setMinimumSize(QSize(0, 34));
        spinBox_chanse->setMaximumSize(QSize(1000, 34));
        spinBox_chanse->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;"));
        spinBox_chanse->setMaximum(100);
        spinBox_chanse->setSingleStep(5);
        spinBox_chanse->setValue(50);

        gridLayout_2->addWidget(spinBox_chanse, 3, 1, 1, 2);

        label_chanse = new QLabel(CaveWindow);
        label_chanse->setObjectName(QString::fromUtf8("label_chanse"));
        label_chanse->setMinimumSize(QSize(120, 30));
        label_chanse->setMaximumSize(QSize(120, 30));
        label_chanse->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        gridLayout_2->addWidget(label_chanse, 3, 0, 1, 1);

        btn_gen = new QPushButton(CaveWindow);
        btn_gen->setObjectName(QString::fromUtf8("btn_gen"));
        btn_gen->setMinimumSize(QSize(0, 40));
        btn_gen->setMaximumSize(QSize(16777215, 30));
        btn_gen->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;\n"
                              "color: #FFFFFF;\n"
                              "background-color: #AF2B36;\n"
                              "border: none;\n"
                              "margin-top: 5px;\n"
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

        gridLayout_2->addWidget(btn_gen, 4, 0, 1, 3);

        spinBox_width = new QSpinBox(CaveWindow);
        spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
        spinBox_width->setMinimumSize(QSize(0, 34));
        spinBox_width->setMaximumSize(QSize(16777215, 34));
        spinBox_width->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;"));
        spinBox_width->setMinimum(1);
        spinBox_width->setMaximum(50);
        spinBox_width->setValue(50);

        gridLayout_2->addWidget(spinBox_width, 1, 1, 1, 2);

        label_hight = new QLabel(CaveWindow);
        label_hight->setObjectName(QString::fromUtf8("label_hight"));
        label_hight->setMinimumSize(QSize(0, 30));
        label_hight->setMaximumSize(QSize(16777215, 30));
        label_hight->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        gridLayout_2->addWidget(label_hight, 2, 0, 1, 1);

        spinBox_height = new QSpinBox(CaveWindow);
        spinBox_height->setObjectName(QString::fromUtf8("spinBox_height"));
        spinBox_height->setMinimumSize(QSize(0, 34));
        spinBox_height->setMaximumSize(QSize(16777215, 34));
        spinBox_height->setStyleSheet(
            QString::fromUtf8("color: #AFA3A5;\n"
                              "background-color: #20222A;"));
        spinBox_height->setMinimum(1);
        spinBox_height->setMaximum(50);
        spinBox_height->setValue(50);

        gridLayout_2->addWidget(spinBox_height, 2, 1, 1, 2);

        verticalLayout->addLayout(gridLayout_2);

        label_step = new QLabel(CaveWindow);
        label_step->setObjectName(QString::fromUtf8("label_step"));
        label_step->setFont(font);
        label_step->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));
        label_step->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_step);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_gen_num = new QLabel(CaveWindow);
        label_gen_num->setObjectName(QString::fromUtf8("label_gen_num"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_gen_num->sizePolicy().hasHeightForWidth());
        label_gen_num->setSizePolicy(sizePolicy2);
        label_gen_num->setMinimumSize(QSize(100, 30));
        label_gen_num->setMaximumSize(QSize(50, 30));
        label_gen_num->setFont(font1);
        label_gen_num->setStyleSheet(
            QString::fromUtf8("color: #FFFFFF;\n"
                              "border: none;\n"
                              "background-color: #20222A;\n"
                              "padding-left: 2px;\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;"));

        gridLayout_5->addWidget(label_gen_num, 0, 0, 1, 1);

        slider_gen = new QSlider(CaveWindow);
        slider_gen->setObjectName(QString::fromUtf8("slider_gen"));
        slider_gen->setMaximum(100);
        slider_gen->setSingleStep(1);
        slider_gen->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(slider_gen, 0, 1, 1, 1);

        verticalLayout->addLayout(gridLayout_5);

        btn_step = new QPushButton(CaveWindow);
        btn_step->setObjectName(QString::fromUtf8("btn_step"));
        btn_step->setMinimumSize(QSize(0, 40));
        btn_step->setMaximumSize(QSize(16777215, 30));
        btn_step->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "text-transform: uppercase;\n"
                              "letter-spacing: 2.5px;\n"
                              "color: #FFFFFF;\n"
                              "background-color: #AF2B36;\n"
                              "border: none;\n"
                              "margin-top: 5px;\n"
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

        verticalLayout->addWidget(btn_step);

        horizontalLayout->addLayout(verticalLayout);

        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        wrapper = new QWidget(CaveWindow);
        wrapper->setObjectName(QString::fromUtf8("wrapper"));
        gridLayout_4 = new QGridLayout(wrapper);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(10, 10, 10, 10);
        render_area = new CaveArea(wrapper);
        render_area->setObjectName(QString::fromUtf8("render_area"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(render_area->sizePolicy().hasHeightForWidth());
        render_area->setSizePolicy(sizePolicy3);
        render_area->setMinimumSize(QSize(500, 500));
        render_area->setMaximumSize(QSize(500, 500));

        gridLayout_4->addWidget(render_area, 0, 0, 1, 1);

        gridLayout_3->addWidget(wrapper, 0, 1, 1, 1);

        retranslateUi(CaveWindow);

        QMetaObject::connectSlotsByName(CaveWindow);
    }  // setupUi

    void retranslateUi(QDialog *CaveWindow) {
        CaveWindow->setWindowTitle(QCoreApplication::translate("CaveWindow", "Dialog", nullptr));
        label_loading->setText(QCoreApplication::translate("CaveWindow", "LOADING", nullptr));
        label_filename->setText(QString());
        btn_loadding->setText(QCoreApplication::translate("CaveWindow", "LOAD FROM FILE", nullptr));
        label_config->setText(QCoreApplication::translate("CaveWindow", "configuration", nullptr));
        label_lim_birth->setText(QCoreApplication::translate("CaveWindow", "birth limit", nullptr));
        label_lim_death->setText(QCoreApplication::translate("CaveWindow", "Death limit", nullptr));
        label_gen->setText(QCoreApplication::translate("CaveWindow", "Generation", nullptr));
        label_width->setText(QCoreApplication::translate("CaveWindow", "WIDTH", nullptr));
        label_chanse->setText(QCoreApplication::translate("CaveWindow", "CHANCE", nullptr));
        btn_gen->setText(QCoreApplication::translate("CaveWindow", "GENERATE", nullptr));
        label_hight->setText(QCoreApplication::translate("CaveWindow", "HEIGHT", nullptr));
        label_step->setText(QCoreApplication::translate("CaveWindow", "UPDATE", nullptr));
        label_gen_num->setText(QCoreApplication::translate("CaveWindow", "0", nullptr));
        btn_step->setText(QCoreApplication::translate("CaveWindow", "NEXT STEP", nullptr));
    }  // retranslateUi
};

namespace Ui {
class CaveWindow : public Ui_CaveWindow {};
}  // namespace Ui

QT_END_NAMESPACE
