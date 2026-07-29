#include "mynotes.h"
#include "ui_mynotes.h"

#include "NoteManager.h"
#include "home.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>


MyNotes::MyNotes(User user, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MyNotes),
    currentUser(user)
{
    ui->setupUi(this);

    loadNotes();
}

MyNotes::~MyNotes()
{
    delete ui;
}
void MyNotes::loadNotes()
{
    ui->notesListWidget->clear();

    userNotes = NoteManager::getUserNotes(currentUser.email);

    for(const Note &note : userNotes)
    {
        ui->notesListWidget->addItem(note.title);
    }
}
void MyNotes::on_refreshButton_clicked()
{
    loadNotes();
}


void MyNotes::on_backButton_clicked()
{
    Home *home = new Home(currentUser);

    home->show();

    this->close();
}



void MyNotes::on_openButton_clicked()
{
    int row = ui->notesListWidget->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Please select a note.");
        return;
    }

    Note note = userNotes[row];

    QDesktopServices::openUrl(
        QUrl::fromLocalFile(note.filePath)
        );
}





void MyNotes::on_deleteButton_clicked()
{
    int row = ui->notesListWidget->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Please select a note.");
        return;
    }

    Note note = userNotes[row];

    if(NoteManager::deleteNote(note))
    {
        QMessageBox::information(this,
                                 "Success",
                                 "Note deleted.");

        loadNotes();
    }
    else
    {
        QMessageBox::warning(this,
                             "Error",
                             "Unable to delete note.");
    }
}

