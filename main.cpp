#include "noteslist.h"
#include <QApplication>
#include "notesdriver.h"

int main(int argc, char *argv[])
{
    notesDriver::init();
    QApplication a(argc, argv);
    notesList w;
    w.show();

    return a.exec();
}
