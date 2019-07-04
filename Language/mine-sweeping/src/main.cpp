#include <QApplication>
#include "QueryWindow.h"

int main(int argc, char *argv[])
{
    auto app = new QApplication(argc, argv);
    new QueryWindow;
    return app->exec();
}
