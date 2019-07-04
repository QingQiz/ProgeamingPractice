//
// Created by angel on 19-2-2.
//

#include "Button.h"
#include <QDebug>

Button::Button(int x, int y) :
    has_mine(false), pos_x(x), pos_y(y), flag(0)
{
    setMaximumHeight(LENGTH);
    setMinimumHeight(LENGTH);
    setMaximumWidth(LENGTH);
    setMinimumWidth(LENGTH);
    setStyleSheet("background-color: rgb(0,0,255)");
}

void Button::set_mine() {
    has_mine = true;
}

Button::~Button() {;}

void Button::set_pos(int x, int y) {
    pos_x = x, pos_y = y;
}

void Button::mouseReleaseEvent(QMouseEvent *e) {
    auto check_pos = [&](int x)->bool {
        return x > 0 && x < LENGTH;
    };
    if (check_pos(e->x()) && check_pos(e->y())) {
        if (e->button() == Qt::RightButton) {
            if (!disabled) emit rightClicked();
        } else if (e->button() == Qt::LeftButton) {
            if (!left_disabled && !disabled)
                emit leftClicked(pos_x, pos_y);
            if (this->disabled) {
                emit updateSurround(pos_x, pos_y);
            }
        }
    }
    emit showSurround(pos_x, pos_y, false);
}

void Button::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton) {
        if (disabled) {
            isSurroundShow = true;
            emit showSurround(pos_x, pos_y, true);
        }
    }
}

void Button::update_flag() {
    // TODO add an image for each flag
    static char color[][50] = {
            "background-color:rgb(0,0,255)",
            "background-color:rgb(255,0,0)",
            "background-color:rgb(255,193,37)"
    };
    if (disabled) return;
    flag = (flag + 1) % 3;
    this->setStyleSheet(color[flag]);
    this->setLeftDisabled(flag != 0);
    if (flag == 2) {
        emit flagUnSet();
    } else if (flag == 1) {
        emit flagSet();
    }
}

void Button::setLeftDisabled(bool dis) {
    left_disabled = dis;
}

void Button::setDisable(bool flag) {
    disabled = flag;
}
