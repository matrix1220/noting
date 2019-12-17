#ifndef NOTESLIST_H
#define NOTESLIST_H

#include <QDialog>

namespace Ui {
class notesList;
}

class notesList : public QDialog
{
    Q_OBJECT

public:
    explicit notesList(QWidget *parent = nullptr);
    ~notesList();

private:
    Ui::notesList *ui;
};

#endif // NOTESLIST_H
