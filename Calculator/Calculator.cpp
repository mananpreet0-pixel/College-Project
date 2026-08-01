#include "Calculator.h"
#include "ui_Calculator.h"
#include <qvector>
#include <cctype>
#include <cmath>
#include <QString>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Calculator");

    QVector<QPushButton *> buttons={ui->btn0,ui->btn1,ui->btn2,ui->btn3,ui->btn4,ui->btn5,ui->btn6,ui->btn7,ui->btn8,ui->btn9,ui->mulbtn,
                                    ui->addbtn,ui->subbtn,ui->divbtn,ui->dotbtn,ui->negatebtn,ui->sqrbtn,ui->invbtn,
                                    ui->rootbtn,ui->modbtn,ui->clrbtn,ui->cebtn,ui->cbtn,ui->equbtn};
    for(int i=0;i<buttons.size();i++)
            connect(buttons[i],&QPushButton::clicked,this,&MainWindow::ButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_displayLabel_textEdited(const QString &arg1)
{}


void MainWindow::appendToDisplay(const QString &text)
{
    ui->displayLabel->setText(text);
}

void MainWindow::ButtonClicked()
{

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString text = button->text();
    if (isUnaryOperator(text))
    {
        handleUnaryOperator(text);
    }
    else if(isNumber(text[0]))
    {
        handleNumber(text);
    }
    else if (isBinaryOperator(text))
    {
        handleBinaryOperator(text);
        if(expression=="Division by Zero not allowed")
            return;
    }
    else if (isSpecialButton(text))
    {
        handleSpecialButton(text);
    }

}

bool MainWindow::isBinaryOperator(const QString &text)
{
    if(text == "+" || text =="-" || text =="x" || text =="÷" || text =="%")
        return true;

    return false;
}

bool MainWindow::isUnaryOperator(const QString &text)
{
    if(text == "1/x" || text =="x²" || text =="√" || text =="+/-")
        return true;

    return false;
}

bool MainWindow::isSpecialButton(const QString &text)
{
    if(text == "CE" || text == "C" || text =="=" || text =="⌫" )
        return true;

    return false;
}

bool MainWindow::isNumber(const QChar &ch)
{
    return ch.isDigit() || ch == '.';
}
void  MainWindow::handleNumber(const QString &text)
{
    if (text == "." && currentNumber.contains("."))
        return;

    if (text == "." && currentNumber.isEmpty())
    {
        expression += "0.";
        currentNumber = "0.";
        appendToDisplay(expression);
        return;
    }

    if (text == "." && expression.isEmpty())
    {
        expression = "0.";
        currentNumber = "0.";
        appendToDisplay(expression);
        return;
    }

    expression+=text;
    currentNumber+=text;
    appendToDisplay(expression);
}
void  MainWindow::handleBinaryOperator(const QString &text)
{
    if (expression.isEmpty())
        return;

    if (isBinaryOperator(QString(expression.back())))
    {
        expression.chop(1);
    }
    expression+=text;
    currentNumber="";
    appendToDisplay(expression);
}
void  MainWindow::handleUnaryOperator(const QString &text)
{
    if(text == "1/x")
    {
        if(currentNumber.isEmpty())
            return;

        if(currentNumber == "0")
        {
            appendToDisplay("Division by Zero");
            return;
        }

        QString oldNumber = currentNumber;

        expression.chop(oldNumber.size());

        expression += "1÷" + oldNumber;

        currentNumber = "1÷" + oldNumber;
    }
    else if(text =="x²")
    {
        if(currentNumber.isEmpty())
            return;
        QString oldNumber = currentNumber;

        expression.chop(oldNumber.size());
        expression += oldNumber + "²";
    }
    else if(text == "√")
    {
        if(expression.isEmpty() ||
            isBinaryOperator(QString(expression.back())))
        {
            expression += "√";
        }
    }
    else if(text =="+/-")
    {
        expression.chop(currentNumber.size());
        if (expression.isEmpty())
        {
            currentNumber = "-" + currentNumber;
            expression += currentNumber;
        }
        else
        {
            QString i = expression.back();
            if(i=="+")
            {
                currentNumber="-"+currentNumber;
                expression.chop(1);
                expression.append(currentNumber);
            }
            else if(i=="-")
            {
                currentNumber="+"+currentNumber;
                expression.chop(1);
                expression.append(currentNumber);
            }
        }

    }

    appendToDisplay(expression);
}
void  MainWindow::handleSpecialButton(const QString &text)
{
    if(text == "CE")
    {
        expression.chop(currentNumber.size());
        currentNumber.clear();
        appendToDisplay(expression);
    }
    else if(text == "C")
    {
        expression.clear();
        currentNumber.clear();
        appendToDisplay("");
    }
    else if(text == "⌫")
    {
        if (!currentNumber.isEmpty())
            currentNumber.chop(1);
        expression.chop(1);
        appendToDisplay(expression);
    }
    else if(text == "=")
    {
        tokens.clear();

        QString currentToken;

        for(int i = 0; i < expression.size(); i++)
        {
            if(isBinaryOperator(QString(expression[i])))
            {
                if(!currentToken.isEmpty())
                {
                    tokens.append(currentToken);
                    currentToken.clear();
                }

                tokens.append(QString(expression[i]));
            }
            else if(QString(expression[i]) == "²")
            {
                if(!currentToken.isEmpty())
                {
                    tokens.append(currentToken);
                    currentToken.clear();
                }

                tokens.append("²");
            }

            else if(QString(expression[i]) == "√")
            {
                tokens.append("√");
            }
            else
            {
                currentToken += expression[i];
            }
        }

        if(!currentToken.isEmpty())
        {
            tokens.append(currentToken);
        }
        QVector<QString> newTokens;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "√" && i + 1 < tokens.size())
            {
                newTokens.append(tokens[i + 1]);
                newTokens.append("√");
                i++;
            }
            else
            {
                newTokens.append(tokens[i]);
            }
        }

        tokens = newTokens;
        infix_to_postfix(tokens);

    }

}
int MainWindow::precedence(const QString &text)
{
    if (isUnaryOperator(text))
        return 3;
    if (text == "+" || text == "-")
        return 1;

    if (text == "x" || text == "÷" || text == "%")
        return 2;

    return 0;
}

void MainWindow::infix_to_postfix(const QVector<QString>  &tokens)
{
    QString result;

    for(int i=0;i<tokens.size();i++)
    {
        QString token = tokens[i];

        if(isNumber(token[0]))
        {
            result += token + " ";
        }

        else if(token == "²" || token == "√")
        {
            result += token + " ";
        }

        else if(isBinaryOperator(token))
        {
            while(!oprator.isEmpty() &&
                   precedence(oprator.back()) >= precedence(token))
            {
                QString op = oprator.back();
                oprator.pop_back();
                result += op + " ";
            }

            oprator.append(token);
        }
    }
    while(!oprator.isEmpty())
    {
        result += oprator.back() + " ";
        oprator.pop_back();
    }
    try
    {
        double answer = evaluatePostfix(result);
        appendToDisplay(QString::number(answer));
    }
    catch (const std::runtime_error &e)
    {
        appendToDisplay(e.what());
    }
}

double MainWindow::evaluatePostfix(QString  &postfix)
{
    values.clear();
    QStringList tokenList = postfix.split(' ', Qt::SkipEmptyParts);
    for(QString &token : tokenList)
    {
        if(isNumber(token[0]))
        {
            values.push_back(token.toDouble());
        }

        else if(token == "²")
        {
            if(values.empty())
                throw std::runtime_error("Invalid Expression");

            double x = values.back();
            values.pop_back();

            values.push_back(x * x);
        }

        else if(token == "√")
        {
            if(values.empty())
                throw std::runtime_error("Invalid Expression");

            double x = values.back();
            values.pop_back();

            values.push_back(sqrt(x));
        }

        else
        {
            if(values.size() < 2)
                throw std::runtime_error("Invalid Expression");

            double right = values.back();
            values.pop_back();

            double left = values.back();
            values.pop_back();

            if(token == "÷" && right == 0)
            {
                throw std::runtime_error("Division by Zero");
            }

            if(token == "+")
            {
                values.push_back(left+right);
            }
            else if(token == "-")
            {
                values.push_back(left-right);
            }
            else if(token == "x")
            {
                values.push_back(left*right);
            }
            else if(token == "÷")
            {
                values.push_back(left/right);
            }
            else if(token == "%")
            {
                values.push_back(std::fmod(left, right));
            }
            else
            {
                throw std::runtime_error("Unknown Operator");
            }

        }
    }
    if(values.size() != 1)
    {
        throw std::runtime_error("Invalid Expression");
    }

    return values.back();
}