#ifndef NOTEVIEW_H
#define NOTEVIEW_H

#include <QDialog>
#include "notesdriver.h"

namespace Ui {
class noteView;
}

class noteView : public QDialog
{
    Q_OBJECT

public:
    noteView(int note_id, int status = 0, QWidget *parent = nullptr);
    ~noteView();

private slots:
    void on_btn_edit_clicked();

    void on_btn_save_clicked();

    void on_body_textChanged();

private:
    Ui::noteView *ui;
    void handle_status();
    int status;
    notesDriver::note * temp_note;
};

#endif // NOTEVIEW_H
