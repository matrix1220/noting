#ifndef NOTESLIST_H
#define NOTESLIST_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class notesList;
}

class notesList : public QDialog
{
    Q_OBJECT

public:
    explicit notesList(QWidget *parent = nullptr);
    ~notesList();

private slots:
    void on_btn_add_clicked();

    void on_btn_del_clicked();

    void on_NotesList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::notesList *ui;
    void refresh_list();
};

#endif // NOTESLIST_H
