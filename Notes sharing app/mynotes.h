#ifndef MYNOTES_H
#define MYNOTES_H

#include <QWidget>
#include <QVector>
#include "User.h"
#include "Note.h"

namespace Ui {
class MyNotes;
}

class MyNotes : public QWidget
{
    Q_OBJECT

public:
    explicit MyNotes(User user, QWidget *parent = nullptr);
    ~MyNotes();

private slots:
    void on_backButton_clicked();
    void on_refreshButton_clicked();

    void on_openButton_clicked();

    void on_deleteButton_clicked();

private:
    void loadNotes();

    Ui::MyNotes *ui;
    User currentUser;
    QVector<Note> userNotes;
};

#endif // MYNOTES_H