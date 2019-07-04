//
// Created by angel on 19-2-2.
//

#ifndef MINE_SWEEPING_MAINWINDOW_H
#define MINE_SWEEPING_MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QtCore/QTimer>
#include "Button.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(int row, int column, int mnumber, QWidget *parent = nullptr);
    ~MainWindow() override;

public:
    Button **mines;
private:
    int row, column;
    int mine_number;
    int active_block;
    bool is_mine_set = false;
    QTimer *qTimer;
private:
    void set_mines(int x, int y);
private slots:
    void update(int x, int y);
    void showResult(bool isWin);
    void game_over();
    void victory();

    void showSurround(int x, int y, bool flg);
    void updateSurround(int x, int y);
signals:
    void quited(bool isWin);
    void success();
    void failed();
};


#endif //MINE_SWEEPING_MAINWINDOW_H
