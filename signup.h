#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_signupButton_clicked();

    void on_nameEdit_textEdited(const QString &arg1);

    void on_emailEdit_textEdited(const QString &arg1);

    void on_PasswordEdit_textEdited(const QString &arg1);

    void on_ConfirmpasswordEdit_textEdited(const QString &arg1);

private:
    Ui::signup *ui;
};

#endif
