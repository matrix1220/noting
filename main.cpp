#include "noteslist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    notesList w;
    w.show();

    return a.exec();
}
