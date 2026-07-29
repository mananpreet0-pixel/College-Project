#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QAbstractItemModel>
#include <QRegularExpression>


class Helper
{
public:
    static bool isStrongPassword(const QString &password);
    static QString toLower(QString str);
    static bool isBlank(const QString &str);
    static bool isValidEmail(const QString &email);
};

#endif

