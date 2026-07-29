#ifndef UPLOADNOTES_H
#define UPLOADNOTES_H

#include <QWidget>
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class UploadNotes;
}
QT_END_NAMESPACE

class UploadNotes : public QWidget
{
    Q_OBJECT

public:
    explicit UploadNotes(User user, QWidget *parent = nullptr);
    ~UploadNotes();

private slots:
    void on_backButton_clicked();

    void on_uploadButton_clicked();

    void on_chooseButton_clicked();

private:
    Ui::UploadNotes *ui;
    User currentUser;

    QString selectedFilePath;
};

#endif