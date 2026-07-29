#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Home;
}
QT_END_NAMESPACE

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(User user, QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_logoutButton_clicked();

    void on_welcomeLabel_linkActivated(const QString &link);

    void on_emailLabel_linkActivated(const QString &link);

    void on_uploadButton_clicked();

    void on_myNotesButton_clicked();

    void on_browseButton_clicked();

    void on_profileButton_clicked();

private:
    Ui::Home *ui;
    User currentUser;
};

#endif // HOME_H