//
// Created by angel on 19-2-5.
//

#ifndef MINE_SWEEPING_QUERYWINDOW_H
#define MINE_SWEEPING_QUERYWINDOW_H

#include <QDialog>

class QueryWindow : public QDialog
{
    Q_OBJECT
public:
    QueryWindow();
    ~QueryWindow() override;


    int row, column, mineNumber;
};

#endif //MINE_SWEEPING_QUERYWINDOW_H
