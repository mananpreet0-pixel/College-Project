#ifndef BROWSENOTES_H
#define BROWSENOTES_H

#include <QWidget>
#include <QVector>

#include "User.h"
#include "Note.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class BrowseNotes;
}
QT_END_NAMESPACE

class BrowseNotes : public QWidget
{
    Q_OBJECT

public:
    explicit BrowseNotes(User user, QWidget *parent = nullptr);
    ~BrowseNotes();

private slots:
    void on_openButton_clicked();

    void on_downloadButton_clicked();

    void on_refreshButton_clicked();

    void on_searchButton_clicked();

    void on_backButton_clicked();

private:
    void loadNotes();

    Ui::BrowseNotes *ui;

    User currentUser;

    QVector<Note> allNotes;
};

#endif // BROWSENOTES_H