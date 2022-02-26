#include "noteslist.h"
#include "ui_noteslist.h"
#include "notesdriver.h"
#include "noteview.h"

using namespace notesDriver;

notesList::notesList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notesList)
{
    ui->setupUi(this);
    refresh_list();
}

notesList::~notesList()
{
    delete ui;
}

void notesList::refresh_list()
{
    ui->NotesList->clear();
    for(note temp : getAll()) {
        QListWidgetItem * temp_item = new QListWidgetItem(temp.getTitle(),ui->NotesList);
        temp_item->setData(100,temp.getId());
        ui->NotesList->addItem(temp_item);
    }
}

void notesList::on_btn_add_clicked()
{
    int note_id = ui->NotesList->currentItem()->data(100).toInt();
    noteView new_window(note_id, 0, this);
    new_window.exec();
    refresh_list();
}

void notesList::on_btn_del_clicked()
{
    int note_id = ui->NotesList->currentItem()->data(100).toInt();
    note temp_note(note_id);
    temp_note.del();
    refresh_list();
}

void notesList::on_NotesList_itemDoubleClicked(QListWidgetItem *item)
{
    int note_id = item->data(100).toInt();
    noteView new_window(note_id, 1, this);
    new_window.exec();
    refresh_list();
}
