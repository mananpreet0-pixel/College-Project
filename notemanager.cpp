#include "NoteManager.h"

#include <QFile>
#include <QTextStream>
#include <QVector>

bool NoteManager::saveNote(const Note &note)
{
    QFile file("notes.txt");

    if(!file.open(QIODevice::Append | QIODevice::Text))
        return false;

    QTextStream out(&file);

    out << note.title << '\n';
    out << note.uploaderName << '\n';
    out << note.uploaderEmail << '\n';
    out << note.filePath << '\n';
    out << '\n';

    file.close();

    return true;
}
QVector<Note> NoteManager::getUserNotes(const QString &email)
{
    QVector<Note> notes;

    QFile file("notes.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text ))
        return notes;
    QTextStream in(&file);

    while(!in.atEnd())
    {
        Note note;

        note.title = in.readLine();
        note.uploaderName = in.readLine();
        note.uploaderEmail = in.readLine();
        note.filePath = in.readLine();

        if(note.uploaderEmail == email)
        {
            notes.push_back(note);
        }

        if(!in.atEnd())
            in.readLine();
    }

    file.close();

    return notes;

}
bool NoteManager::deleteNote(const Note &note)
{
    QFile::remove(note.filePath);

    QFile file("notes.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QVector<Note> notes;

    QTextStream in(&file);

    while(!in.atEnd())
    {
        Note temp;

        temp.title = in.readLine();
        temp.uploaderName = in.readLine();
        temp.uploaderEmail = in.readLine();
        temp.filePath = in.readLine();

        if(!in.atEnd())
            in.readLine();

        if(temp.filePath != note.filePath)
        {
            notes.push_back(temp);
        }
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    for(const Note &n : notes)
    {
        out << n.title << '\n';
        out << n.uploaderName << '\n';
        out << n.uploaderEmail << '\n';
        out << n.filePath << '\n';
        out << '\n';
    }

    file.close();

    return true;
}
QVector<Note> NoteManager::getAllNotes()
{
    QVector<Note> notes;

    QFile file("notes.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text ))
        return notes;
    QTextStream in(&file);

    while(!in.atEnd())
    {
        Note note;

        note.title = in.readLine();
        note.uploaderName = in.readLine();
        note.uploaderEmail = in.readLine();
        note.filePath = in.readLine();

        notes.push_back(note);

        if(!in.atEnd())
            in.readLine();
    }

    file.close();

    return notes;
}