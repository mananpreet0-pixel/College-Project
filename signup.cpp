#include "signup.h"
#include "ui_signup.h"
#include <qmessagebox>
#include <cstdio>
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <QObject>
#include "Helper.h"
#include "usermanager.h"


signup::signup(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_signupButton_clicked()
{
    QString name = ui->nameEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();
    QString password = ui->PasswordEdit->text();
    QString confirmPassword = ui->ConfirmpasswordEdit->text();

    QString error;

    if(UserManager::signup(name,
                            email,
                            password,
                            confirmPassword,
                            error))
    {
        QMessageBox::information(this,
                                 "Success",
                                 "Account created successfully!");

        ui->nameEdit->clear();
        ui->emailEdit->clear();
        ui->PasswordEdit->clear();
        ui->ConfirmpasswordEdit->clear();

        ui->nameEdit->setFocus();
    }
    else
    {
        QMessageBox::warning(this,
                             "Signup Failed",
                             error);
    }
    this->close();
}


void signup::on_nameEdit_textEdited(const QString &arg1)
{}



void signup::on_emailEdit_textEdited(const QString &arg1)
{}


void signup::on_PasswordEdit_textEdited(const QString &arg1)
{}


void signup::on_ConfirmpasswordEdit_textEdited(const QString &arg1)
{}

