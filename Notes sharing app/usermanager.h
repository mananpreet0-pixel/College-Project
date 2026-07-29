#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "user.h"
#include <QAbstractItemModel>

class UserManager
{
public:
    static bool usernameExists(const QString &email);

    static bool signup(const QString &name,
                       const QString &email,
                       const QString &password,
                       const QString &confirmPassword,
                       QString &errorMessage);
    static bool login(const QString &email,
                      const QString &password,
                      User &loggedInUser,
                      QString &errorMessage);
    static bool changePassword(const QString &email,
                               const QString &newPassword);
};

#endif // USERMANAGER_H
