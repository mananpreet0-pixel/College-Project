#include "usermanager.h"
#include "Helper.h"
#include <QFile>
#include <QTextStream>
#include <qmessagebox>
#include <QVector>

bool UserManager::usernameExists(const QString &email)
{
    QFile file("users.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString name = in.readLine();
        QString storedEmail = in.readLine();
        QString password = in.readLine();

        in.readLine();

        if (storedEmail == email)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool UserManager::signup(const QString &name,
                         const QString &email,
                         const QString &password,
                         const QString &confirmPassword,
                         QString &errorMessage)
{
    if(name.isEmpty())
    {
        errorMessage = "Name cannot be empty.";
        return false;
    }

    if(email.isEmpty())
    {
        errorMessage = "Email cannot be empty.";
        return false;
    }

    if(password.isEmpty())
    {
        errorMessage = "Password cannot be empty.";
        return false;
    }

    if(password != confirmPassword)
    {
        errorMessage = "Passwords do not match.";
        return false;
    }

    if(!Helper::isStrongPassword(password))
    {
        errorMessage =
            "Password must contain:\n"
            "- At least 8 characters\n"
            "- One uppercase letter\n"
            "- One lowercase letter\n"
            "- One digit\n"
            "- One special character";

        return false;
    }

    if(usernameExists(email))
    {
        errorMessage = "Email already exists.";
        return false;
    }
    QString normalizedEmail = email.trimmed().toLower();

    QFile file("users.txt");

    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        errorMessage = "Cannot open users.txt";
        return false;
    }

    QTextStream out(&file);

    out << name << '\n';
    out << normalizedEmail << '\n';
    out << password << '\n';
    out << '\n';

    file.close();

    return true;
}

bool UserManager::login(const QString &email,
                        const QString &password,
                        User &loggedInUser,
                        QString &errorMessage)
{
    if(email.isEmpty())
    {
        errorMessage = "Email cannot be empty.";
        return false;
    }

    if(!Helper::isValidEmail(email))
    {
        errorMessage = "Please enter a valid email address..";
        return false;
    }

    if(password.isEmpty())
    {
        errorMessage = "Password cannot be empty.";
        return false;
    }

    QFile file("users.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        errorMessage = "Cannot open users.txt.";
        return false;
    }

    QString normalizedEmail = email.trimmed().toLower();

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString storedName = in.readLine();
        QString storedEmail = in.readLine();
        QString storedPassword = in.readLine();

        if(!in.atEnd())
            in.readLine();

        if(storedEmail == normalizedEmail)
        {
            if(storedPassword == password)
            {
                loggedInUser.name = storedName;
                loggedInUser.email = storedEmail;
                loggedInUser.password = storedPassword;

                file.close();
                return true;
            }

            errorMessage = "Incorrect password.";
            file.close();
            return false;
        }
    }

    file.close();

    errorMessage = "Email not found.";
    return false;
}
bool UserManager::changePassword(const QString &email,
                           const QString &newPassword)
{
    QFile file("users.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QVector<User> users;

    QTextStream in(&file);

    while(!in.atEnd())
    {
        User user;

        user.name = in.readLine();
        user.email = in.readLine();
        user.password = in.readLine();

        if(user.email == email)
        {
            user.password = newPassword;
        }

        users.push_back(user);

        if(!in.atEnd())
            in.readLine();
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    for(const User &user : users)
    {
        out << user.name << '\n';
        out << user.email << '\n';
        out << user.password << '\n';
        out << '\n';
    }

    file.close();

    return true;
}
