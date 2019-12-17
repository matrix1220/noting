#include "noteslist.h"
#include "ui_noteslist.h"

notesList::notesList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notesList)
{
    ui->setupUi(this);
}

notesList::~notesList()
{
    delete ui;
}
