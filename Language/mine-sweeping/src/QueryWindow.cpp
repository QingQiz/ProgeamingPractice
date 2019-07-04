//
// Created by angel on 19-2-5.
//

#include "QueryWindow.h"
#include "MainWindow.h"
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QLayout>
#include <QPushButton>
#include <iostream>
#include <fstream>


QueryWindow::QueryWindow() {
    auto row_label = new QLabel("row:");
    auto column_label = new QLabel("column:");
    auto mineNumber_label = new QLabel("mine:");
    auto row_spinBox = new QSpinBox;
    auto column_spinBox = new QSpinBox;
    auto mineNumber_spinBox = new QSpinBox;

    row_label->setStyleSheet("QLabel{font-weight:bold;font-size:25px}");
    column_label->setStyleSheet("QLabel{font-weight:bold;font-size:25px}");
    mineNumber_label->setStyleSheet("QLabel{font-weight:bold;font-size:25px}");

    row_spinBox->setRange(1, 71);
    column_spinBox->setRange(1, 115);
    mineNumber_spinBox->setMinimum(0);



    QObject::connect(row_spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](){
        mineNumber_spinBox->setMaximum(row_spinBox->value() * column_spinBox->value() - 1);
    });
    QObject::connect(column_spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](){
        mineNumber_spinBox->setMaximum(row_spinBox->value() * column_spinBox->value() - 1);
    });

    std::ifstream last("/tmp/mine_sweep_last");
    int _row, _column, _mineN;
    if (!last) {
        _row = _column = 20, _mineN = 60;
    } else {
        last >> _row >> _column >> _mineN;
    }
    row_spinBox->setValue(_row);
    column_spinBox->setValue(_column);
    mineNumber_spinBox->setValue(_mineN);


    auto yes_pushButton = new QPushButton("Next");
    auto no_pushButton = new QPushButton("Cancel");

    QObject::connect(yes_pushButton, &QPushButton::clicked, [=](){
        row = row_spinBox->value();
        column = column_spinBox->value();
        mineNumber = mineNumber_spinBox->value();

        std::ofstream o;
        o.open("/tmp/mine_sweep_last");
        o << row << ' ' << column << ' ' << mineNumber;
        o.close();

        this->close();
        new MainWindow(row, column, mineNumber, nullptr);
        delete this;
    });
    QObject::connect(no_pushButton, &QPushButton::clicked, [=](){
        exit(0);
    });

    auto qhb1 = new QHBoxLayout;
    auto qhb2 = new QHBoxLayout;
    auto qvb1 = new QVBoxLayout;
    auto qvb2 = new QVBoxLayout;

    qvb1->addWidget(row_label);
    qvb1->addWidget(column_label);
    qvb1->addWidget(mineNumber_label);

    qvb2->addWidget(row_spinBox);
    qvb2->addWidget(column_spinBox);
    qvb2->addWidget(mineNumber_spinBox);

    qhb1->addLayout(qvb1);
    qhb1->addLayout(qvb2);

    qhb2->addStretch();
    qhb2->addWidget(yes_pushButton);
    qhb2->addStretch();
    qhb2->addWidget(no_pushButton);
    qhb2->addStretch();

    auto qLayout = new QVBoxLayout;

    qLayout->addLayout(qhb1);
    qLayout->addLayout(qhb2);

    this->setLayout(qLayout);
    this->show();
}

QueryWindow::~QueryWindow() {;}
