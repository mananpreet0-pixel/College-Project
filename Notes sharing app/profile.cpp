#include "profile.h"
#include "ui_profile.h"

#include "home.h"
#include "usermanager.h"
#include "Helper.h"
#include <QMessageBox>

Profile::Profile(User user, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Profile),
    currentUser(user)
{
    ui->setupUi(this);

    ui->nameText->setText(currentUser.name);
    ui->emailText->setText(currentUser.email);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_changePasswordButton_clicked()
{
    QString newPassword = ui->newPasswordEdit->text();
    QString confirmPassword = ui->confirmPasswordLabel->text();

    if(newPassword.isEmpty())
    {
        QMessageBox::warning(this,
                             "Error",
                             "Password cannot be empty.");
        return;
    }

    if(newPassword != confirmPassword)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Passwords do not match.");
        return;
    }

    if(!Helper::isStrongPassword(newPassword))
    {
        QMessageBox::warning(this,
                             "Weak Password",
                             "Password must contain:\n"
                             "- At least 8 characters\n"
                             "- One uppercase letter\n"
                             "- One lowercase letter\n"
                             "- One digit\n"
                             "- One special character");
        return;
    }

    if(UserManager::changePassword(currentUser.email, newPassword))
    {
        currentUser.password = newPassword;

        QMessageBox::information(this,
                                 "Success",
                                 "Password changed successfully.");

        ui->newPasswordEdit->clear();
        ui->confirmPasswordLabel->clear();
    }
    else
    {
        QMessageBox::warning(this,
                             "Error",
                             "Unable to change password.");
    }
}

void Profile::on_backButton_clicked()
{
    Home *home = new Home(currentUser);

    home->show();

    this->close();
}


void Profile::on_nameText_linkActivated(const QString &link)
{
    ui->nameText->setText("Name :" + currentUser.name);
}


void Profile::on_emailText_linkActivated(const QString &link)
{
    ui->emailText->setText("Email :" + currentUser.email);
}

