#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include "User.h"

namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:
    explicit Profile(User user, QWidget *parent = nullptr);
    ~Profile();

private slots:
    void on_changePasswordButton_clicked();

    void on_backButton_clicked();

    void on_nameText_linkActivated(const QString &link);

    void on_emailText_linkActivated(const QString &link);

private:
    Ui::Profile *ui;
    User currentUser;
};

#endif // PROFILE_H