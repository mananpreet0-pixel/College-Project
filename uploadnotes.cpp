#include "uploadnotes.h"
#include "ui_uploadnotes.h"
#include "home.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include "NoteManager.h"
#include "Note.h"

UploadNotes::UploadNotes(User user, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::UploadNotes),
    currentUser(user)
{
    ui->setupUi(this);
}

UploadNotes::~UploadNotes()
{
    delete ui;
}

void UploadNotes::on_backButton_clicked()
{
    Home *home = new Home(currentUser);

    home->show();

    this->close();
}
void UploadNotes::on_uploadButton_clicked()
{
    if(selectedFilePath.isEmpty())
    {
        QMessageBox::warning(this,
                             "Error",
                             "Please choose a file first.");
        return;
    }

    QDir dir;
    dir.mkpath("Notes");

    QString userFolder = "Notes/" + currentUser.email;
    dir.mkpath(userFolder);

    QFileInfo info(selectedFilePath);

    QString destination = userFolder + "/" + info.fileName();

    if(QFile::exists(destination))
    {
        QFile::remove(destination);
    }

    if(QFile::copy(selectedFilePath, destination))
    {
        Note note;

        note.title = info.fileName();
        note.uploaderName = currentUser.name;
        note.uploaderEmail = currentUser.email;
        note.filePath = destination;

        NoteManager::saveNote(note);

        QMessageBox::information(this,
                                 "Success",
                                 "File uploaded successfully!");

        selectedFilePath.clear();
        ui->selectedFileLabel->setText("No file selected");
    }
    else
    {
        QMessageBox::warning(this,
                             "Error",
                             "Unable to upload file.");
    }
}


void UploadNotes::on_chooseButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        "Select Notes",
        "",
        "Documents (*.pdf *.doc *.docx *.ppt *.pptx)"
        );

    if(file.isEmpty())
        return;

    selectedFilePath = file;

    ui->selectedFileLabel->setText(QFileInfo(file).fileName());
}


