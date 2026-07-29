#include "mainwindow.h"
#include "usermanager.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "signup.h"
#include "user.h"
#include "home.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_passwordEdit_textEdited(const QString &arg1)
{}


void MainWindow::on_loginButton_clicked()
{
    QString error;
    QString email = ui->emailEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    User currentUser;

    if(UserManager::login(email,
                           password,
                           currentUser,
                           error))
    {
        Home *home = new Home(currentUser);

        home->show();

        this->close();

    }
    else
    {
        QMessageBox::warning(this,
                             "Login Failed",
                             error);
    }
}


void MainWindow::on_emailEdit_textEdited(const QString &arg1)
{}


void MainWindow::on_signupButton_clicked()
{
    signup *s = new signup(this);
    s->show();
}

