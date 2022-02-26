#include "notesdriver.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

namespace notesDriver {
    QSqlDatabase db;
}
void notesDriver::init() {
    const QString DRIVER("QSQLITE");
    notesDriver::db = QSqlDatabase::addDatabase(DRIVER);
    notesDriver::db.setDatabaseName("notes_db.db");
    notesDriver::db.open();
}

QList<notesDriver::note> notesDriver::getAll()
{
    QSqlQuery query;
    QList<notesDriver::note> return_value;
    query.exec("SELECT id, body FROM notes");
    while (query.next()) {
        return_value.append(note(query.value(0).toInt(),query.value(1).toString()));
    }
    return return_value;
}


notesDriver::note::note(int id)
{
    this->id = id;
    QSqlQuery query;
    query.prepare("SELECT body FROM notes WHERE id = ?");
    query.addBindValue(id);
    query.exec();
    query.first();
    body = query.value(0).toString();
}

notesDriver::note::note(int id, QString body)
{
    this->id = id;
    this->body = body;
    QSqlQuery query;
    query.prepare("INSERT INTO notes(id, body) VALUES (?, ?)");
    query.addBindValue(body);
    query.addBindValue(id);
    query.exec();
}

void notesDriver::note::del()
{
    QSqlQuery query;
    query.prepare("DELETE FROM notes WHERE id = ?");
    query.addBindValue(id);
    query.exec();
}

QString notesDriver::note::getTitle()
{
    return body.chopped(10);
}

QString notesDriver::note::getBody()
{
    return body;
}

int notesDriver::note::getId()
{
    return id;
}

void notesDriver::note::setBody(QString body)
{
    this->body = body;
    QSqlQuery query;
    query.prepare("UPDATE notes SET body = ? WHERE id = ?");
    query.addBindValue(body);
    query.addBindValue(id);
    query.exec();
}
