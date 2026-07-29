#include "browsenotes.h"
#include "ui_browsenotes.h"

#include "NoteManager.h"
#include "home.h"

#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

BrowseNotes::BrowseNotes(User user, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::BrowseNotes),
    currentUser(user)
{
    ui->setupUi(this);

    loadNotes();
}

BrowseNotes::~BrowseNotes()
{
    delete ui;
}

void BrowseNotes::loadNotes()
{
    ui->notesListWidget->clear();

    allNotes = NoteManager::getAllNotes();

    for(const Note &note : allNotes)
    {
        ui->notesListWidget->addItem(
            note.title +
            "\nUploaded by: " +
            note.uploaderName
            );
    }
}

void BrowseNotes::on_refreshButton_clicked()
{
    loadNotes();
}

void BrowseNotes::on_searchButton_clicked()
{
    QString keyword = ui->searchEdit->text().trimmed().toLower();

    ui->notesListWidget->clear();

    for(const Note &note : allNotes)
    {
        if(note.title.toLower().contains(keyword) ||
            note.uploaderName.toLower().contains(keyword))
        {
            ui->notesListWidget->addItem(
                note.title +
                "\nUploaded by: " +
                note.uploaderName
                );
        }
    }
}

void BrowseNotes::on_openButton_clicked()
{
    int row = ui->notesListWidget->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Please select a note.");
        return;
    }

    QDesktopServices::openUrl(
        QUrl::fromLocalFile(allNotes[row].filePath)
        );
}

void BrowseNotes::on_downloadButton_clicked()
{
    int row = ui->notesListWidget->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Please select a note.");
        return;
    }

    QString destination =
        QFileDialog::getSaveFileName(
            this,
            "Save Note",
            allNotes[row].title
            );

    if(destination.isEmpty())
        return;

    if(QFile::copy(allNotes[row].filePath, destination))
    {
        QMessageBox::information(this,
                                 "Success",
                                 "Note downloaded successfully.");
    }
    else
    {
        QMessageBox::warning(this,
                             "Error",
                             "Unable to download note.");
    }
}

void BrowseNotes::on_backButton_clicked()
{
    Home *home = new Home(currentUser);

    home->show();

    this->close();
}