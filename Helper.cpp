#include "Helper.h"
#include <QFile>
#include <QTextStream>


bool Helper::isStrongPassword(const QString &password)
{
    if (password.length() < 8)
        return false;

    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for (QChar ch : password)
    {
        if (ch.isSpace())
            return false;

        if (ch.isUpper())
            upper = true;
        else if (ch.isLower())
            lower = true;
        else if (ch.isDigit())
            digit = true;
        else
            special = true;
    }

    return upper && lower && digit && special;
}

QString Helper::toLower(QString str)
{
    return str.toLower();
}

bool Helper::isBlank(const QString &str)
{
    return str.trimmed().isEmpty();
}

bool Helper::isValidEmail(const QString &email)
{
    QRegularExpression regex(
        "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$"
        );

    return regex.match(email).hasMatch();
}