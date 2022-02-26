#ifndef NOTESDRIVER_H
#define NOTESDRIVER_H
#include <QList>

namespace notesDriver {
class note;
QList<note> getAll();
void init();

class note
{
public:
    note(int);
    note(int,QString);
    void del();
    QString getTitle();
    QString getBody();
    int getId();
    void setBody(QString);
private:
    int id;
    QString body;
};

}
#endif // NOTESDRIVER_H
