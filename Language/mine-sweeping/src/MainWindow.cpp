//
// Created by angel on 19-2-2.
//

#include "MainWindow.h"
#include "QueryWindow.h"
#include <QLayout>
#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QTime>
#include <iostream>
#include <random>
#include <string>
#include <queue>
#include <map>
#include <QLCDNumber>

static int mv[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1} };

MainWindow::MainWindow(int row, int column, int mnumber, QWidget *parent) :
    QMainWindow(parent),
    row(row), column(column), mine_number(mnumber),
    active_block(row * column),
    is_mine_set(false)
{
    // Disable zoom
    setFixedSize(column * Button::LENGTH + 20, row * Button::LENGTH + 80);

    // TODO make Labels beautiful
    // Time Label
    qTimer = new QTimer(this);
    auto timeLabel = new QLCDNumber;
    timeLabel->display(current_time);
    //timeLabel->setStyleSheet("QLabel{font-weight:bold;font-size:35px}");
    connect(qTimer, &QTimer::timeout, [=](){
        QTime qTime = QTime::fromString(current_time, "hh:mm:ss");
        qTime = qTime.addSecs(1);

        timeLabel->display(qTime.toString("hh:mm:ss"));
        current_time = qTime.toString("hh:mm:ss");
        //timeLabel->setStyleSheet("QLabel{font-weight:bold;font-size:35px}");
        this->repaint();
    });

    // Mine Number Label
    auto mineN = new QLabel(std::to_string(mine_number).c_str());
    mineN->setStyleSheet("QLabel{font-weight:bold;font-size:35px}");

    auto qhBoxLayout = new QHBoxLayout;
    qhBoxLayout->addStretch();
    qhBoxLayout->addWidget(timeLabel);
    qhBoxLayout->addStretch();
    qhBoxLayout->addWidget(mineN);
    qhBoxLayout->addStretch();

    // assign memory for mines
    mines = new Button*[row];
    for (int i = 0; i < row; ++i) {
        mines[i] = new Button[column];
        for (int j = 0; j < column; ++j) {
            mines[i][j].set_pos(i, j);
        }
    }

    // add mine buttons
    auto *qvBoxLayout = new QVBoxLayout;
    qvBoxLayout->setSpacing(0);

    qvBoxLayout->addLayout(qhBoxLayout);
    for (int i = 0; i < row; ++i) {
        qhBoxLayout = new QHBoxLayout;
        qhBoxLayout->setSpacing(0);
        for (int j = 0; j < column; ++j) {
            connect(&mines[i][j], SIGNAL(leftClicked(int, int)), this, SLOT(update(int, int)));
            connect(&mines[i][j], SIGNAL(rightClicked()), &mines[i][j], SLOT(update_flag()));

            connect(&mines[i][j], SIGNAL(showSurround(int, int, bool)), this, SLOT(showSurround(int, int, bool)));
            connect(&mines[i][j], SIGNAL(updateSurround(int, int)), this, SLOT(updateSurround(int, int)));

            connect(&mines[i][j], &Button::flagSet, [=](){
                auto __n = mineN->text().toInt();
                mineN->setText(std::to_string(__n - 1).c_str());
            });
            connect(&mines[i][j], &Button::flagUnSet, [=](){
                auto __n = mineN->text().toInt();
                mineN->setText(std::to_string(__n + 1).c_str());
            });
            qhBoxLayout->addWidget(&mines[i][j]);
        }
        qvBoxLayout->addLayout(qhBoxLayout);
    }
    auto widget = new QWidget;
    widget->setLayout(qvBoxLayout);
    setCentralWidget(widget);


    // game result
    connect(this, SIGNAL(success()), this, SLOT(victory()));
    connect(this, SIGNAL(failed()), this, SLOT(game_over()));
    connect(this, SIGNAL(quited(bool)), this, SLOT(showResult(bool)));

    this->show();
}

MainWindow::~MainWindow() {
    for (int i = 0; i < row; ++i) {
        delete [] mines[i];
    }
    delete [] mines;
    delete qTimer;
}

void MainWindow::update(int x, int y) {
    if (!is_mine_set) {
        set_mines(x, y);
        is_mine_set = true;
    }
    if (mines[x][y].has_mine) {
        emit failed();
        return;
    }
    auto check_pos = [&](int x, int y)->bool {
        if (x < 0 || x >= row || y < 0 || y >= column) return false;
        return !mines[x][y].disabled;
    };
    std::queue<int> qx, qy, level;
    int last_level = -1;
    std::map<int, bool> vis;

    qx.push(x), qy.push(y), level.push(0);
    vis[x * column + y] = true;
    while (!qx.empty()) {
        int now_x = qx.front(), now_y = qy.front(), now_level = level.front();
        qx.pop(), qy.pop(), level.pop();

        if (now_level - last_level > 3) {
            this->repaint();
            last_level = now_level;
        }

        int count = 0;
        //int sum = 0;
        for (auto &move_action : mv) {
            int next_x = now_x + move_action[0], next_y = now_y + move_action[1];
            if (check_pos(next_x, next_y)) {
                if (mines[next_x][next_y].has_mine) count++;
                //if (!mines[next_x][next_y].disabled) sum++;
            }
        }
        if (count == 0) {
            for (auto &move_action : mv) {
                int next_x = now_x + move_action[0], next_y = now_y + move_action[1];
                if (check_pos(next_x, next_y)) {
                    if (!vis[next_x * column + next_y]) {
                        vis[next_x * column + next_y] = true;
                        qx.push(next_x), qy.push(next_y), level.push(now_level + 1);
                    }
                }
            }
            mines[now_x][now_y].setText("");
            mines[now_x][now_y].setStyleSheet("background-color: rgb(255, 255, 255)");
        } else {
            static std::string color_select[8] = {
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(0,0,255);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(102,205,0);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(255,0,0);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(25,25,112);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(178,34,34);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(100,149,237);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(0,0,0);background-color:rgb(255,255,255)}",
                    "QPushButton{font-size:25px;font-weight:bold;color:rgb(139,126,102);background-color:rgb(255,255,255)}"
            };
            mines[now_x][now_y].setText(std::to_string(count).c_str());
            mines[now_x][now_y].setStyleSheet(color_select[count - 1].c_str());
            //updateSurround(now_x, now_y);
        }
        mines[now_x][now_y].setDisable(true);
        active_block--;
    }
    if (active_block == mine_number) emit success();
}

void MainWindow::game_over() {
    qTimer->stop();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (mines[i][j].has_mine) {
                if (mines[i][j].flag == 0)
                    mines[i][j].setStyleSheet("background-color:rgb(255,0,0)");
                else
                    mines[i][j].setStyleSheet("background-color:rgb(0,255,0)");
            } else {
                if (mines[i][j].flag == 1) {
                    mines[i][j].setStyleSheet("background-color:black");
                }
            }
            mines[i][j].setDisable(true);
        }
    }
    this->repaint();
    emit quited(false);
}

void MainWindow::victory() {
    qTimer->stop();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (mines[i][j].has_mine) {
                if (mines[i][j].flag == 0) {
                    mines[i][j].update_flag();
                }
            }
        }
    }
    this->repaint();
    emit quited(true);
}

void MainWindow::set_mines(int x, int y) {
    std::default_random_engine e(static_cast<unsigned long>(clock()));
    std::uniform_int_distribution<int> u(0, row * column - 1);

    std::map<int, bool> vis;
    vis[x * column + y] = true;
    std::queue<int> q;

    for (int i = 0; i < mine_number; ++i) {
        int gen;
        do {
            gen = u(e);
        } while (vis[gen]);
        q.push(gen);
        vis[gen] = true;
    }
    while (!q.empty()) {
        int gen = q.front();
        q.pop();
        int _x = gen / row;
        int _y = gen % row;
        mines[_x][_y].set_mine();
    }
    qTimer->start(1000);
}


void MainWindow::showResult(bool isWin) {
    auto dialog = new QDialog;
        auto qvb = new QVBoxLayout;
        auto qhb = new QHBoxLayout;
        auto qLabel = new QLabel(isWin ? "Win" : "Game over");
        qLabel->setStyleSheet("QLabel{text-align:center;color:black;font-size:50px;font-weight:bold}");
        qvb->addWidget(qLabel);
        auto qPushButton1 = new QPushButton("restart");
        auto qPushButton2 = new QPushButton("quit");
        connect(qPushButton1, &QPushButton::clicked, [=](){
            dialog->close();
            delete dialog;
            this->close();
            new QueryWindow;
            delete this;
        });
        connect(qPushButton2, &QPushButton::clicked, [=](){
            exit(0);
        });
        qhb->addStretch();
        qhb->addWidget(qPushButton1);
        qhb->addStretch();
        qhb->addWidget(qPushButton2);
        qhb->addStretch();
        qvb->addLayout(qhb);
        dialog->setLayout(qvb);
        dialog->show();
}

void MainWindow::showSurround(int x, int y, bool flg) {
    for (auto &step : mv) {
        int nx = x + step[0], ny = y + step[1];
        if (nx >= 0 && nx < row && ny >=0 && ny < column) {
            if (!mines[nx][ny].disabled && mines[nx][ny].flag == 0) {
                if (flg) {
                    mines[nx][ny].setStyleSheet("background-color:rgb(102,204,255)");
                } else {
                    mines[nx][ny].setStyleSheet("background-color:rgb(0,0,255)");
                }
            }
        }
    }
}

void MainWindow::updateSurround(int x, int y) {
    int cnt = 0;
    int enbN = 0;
    for (auto& step : mv) {
        int nx = x + step[0], ny = y + step[1];
        if (nx >= 0 && nx < row && ny >=0 && ny < column) {
            if (mines[nx][ny].disabled) continue;
            if (mines[nx][ny].flag == 1) cnt++;
            enbN++;
        }
    }
    if (enbN == mines[x][y].text().toInt()) {
        for (auto& step : mv) {
            int nx = x + step[0], ny = y + step[1];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
                if (mines[nx][ny].disabled) continue;
                while (mines[nx][ny].flag != 1) mines[nx][ny].update_flag();
            }
        }
        return;
    }
    if (cnt == mines[x][y].text().toInt()) {
        for (auto& step : mv) {
            int nx = x + step[0], ny = y + step[1];
            if (nx >= 0 && nx < row && ny >=0 && ny < column) {
                if (mines[nx][ny].disabled) continue;
                if (mines[nx][ny].flag != 1) {
                    update(nx, ny);
                }
            }
        }
    }
}
