#include "home.h"
#include "ui_home.h"
#include "mainwindow.h"
#include <qmessagebox>
#include "uploadnotes.h"
#include "mynotes.h"
#include "browsenotes.h"
#include "profile.h"

Home::Home(User user, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Home),
    currentUser(user)
{
    ui->setupUi(this);

    ui->welcomeLabel->setText("Welcome, " + currentUser.name);
    ui->emailLabel->setText(currentUser.email);
}

Home::~Home()
{
    delete ui;
}

void Home::on_logoutButton_clicked()
{
    MainWindow *login = new MainWindow();

    login->show();

    this->close();
}
void Home::on_welcomeLabel_linkActivated(const QString &link)
{
    ui->welcomeLabel->setText("Welcome, 👋");
}

void Home::on_emailLabel_linkActivated(const QString &link)
{
   ui->emailLabel->setText("Email : " + currentUser.email);
}

void Home::on_uploadButton_clicked()
{
    UploadNotes *page = new UploadNotes(currentUser);

    page->show();

    this->hide();
}


void Home::on_myNotesButton_clicked()
{
    MyNotes *page = new MyNotes(currentUser);

    page->show();

    this->close();
}


void Home::on_browseButton_clicked()
{
    BrowseNotes *browse = new BrowseNotes(currentUser);

    browse->show();

    this->close();
}


void Home::on_profileButton_clicked()
{
    Profile *profile = new Profile(currentUser);

    profile->show();

    this->close();
}




