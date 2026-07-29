#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include "Note.h"
#include <QVector>

class NoteManager
{
public:
    static bool saveNote(const Note &note);
    static QVector<Note> getUserNotes(const QString &email);
    static bool deleteNote(const Note &note);
    static QVector<Note> getAllNotes();
};

#endif // NOTEMANAGER_H