//
// Created by angel on 19-2-2.
//

#ifndef MINE_SWEEPING_BUTTON_H
#define MINE_SWEEPING_BUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT
public:
    const static int LENGTH = 30;
    bool has_mine;
    int pos_x, pos_y;
    int flag;

    bool disabled = false;
    bool left_disabled = false;
    bool isSurroundShow = false;

public:
    explicit Button(int x=-1, int y=-1);
    ~Button() override;
    void setLeftDisabled(bool dis);
    void set_mine();
    void set_pos(int x, int y);
    void setDisable(bool flag);

private slots:
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;

public slots:
    void update_flag();

signals:
    void flagSet();
    void flagUnSet();
    void rightClicked();
    void leftClicked(int x, int y);

    void updateSurround(int x, int y);
    void showSurround(int x, int y, bool flg);

};

#endif //MINE_SWEEPING_BUTTON_H
