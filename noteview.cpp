#include "noteview.h"
#include "ui_noteview.h"
#include "notesdriver.h"

noteView::noteView(int note_id, int status, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::noteView),
    temp_note(new notesDriver::note(note_id))
{
    ui->setupUi(this);
    this->status = status;
    //this->temp_note = notesDriver::note(note_id);
    handle_status();
}

noteView::~noteView()
{
    delete ui;
    delete temp_note;
}

void noteView::handle_status()
{
    switch (status) {
        case 0: // create
            ui->body->setReadOnly(false);
            ui->btn_edit->setVisible(false);
            ui->btn_save->setVisible(true);
            break;
        case 1: // view
            ui->body->setReadOnly(true);
            ui->btn_edit->setText("Edit");
            ui->btn_save->setVisible(false);
            break;
        case 2: // edit
            ui->body->setReadOnly(false);
            ui->btn_edit->setText("Not edit");
            ui->btn_save->setVisible(true);
            ui->btn_save->setEnabled(false);
            break;
    }
}

void noteView::on_btn_edit_clicked()
{
    if(status==1) status=2;
    else if(status==2) status=1;
    handle_status();
}

void noteView::on_btn_save_clicked()
{
    temp_note->setBody(ui->body->toPlainText());
    this->close();
}

void noteView::on_body_textChanged()
{
    if(temp_note->getBody() == ui->body->toPlainText()) {
        ui->btn_save->setEnabled(false);
    } else  {
        ui->btn_save->setEnabled(true);
    }
}
