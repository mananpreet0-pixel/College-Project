#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:

    void on_displayLabel_textEdited(const QString &arg1);


private:
    Ui::MainWindow *ui;
    void appendToDisplay(const QString &text);
    void ButtonClicked();
    bool isBinaryOperator(const QString &text);
    bool isUnaryOperator(const QString &text);
    bool isSpecialButton(const QString &text);
    bool isNumber(const QChar &ch);
    void handleNumber(const QString &text);
    void handleBinaryOperator(const QString &text);
    void handleUnaryOperator(const QString &text);
    void handleSpecialButton(const QString &text);
    int precedence(const QString &text);
    void infix_to_postfix(const QVector<QString>  &tokens);
    double evaluatePostfix(QString  &postfix);
    QString expression;
    QString currentNumber;
    QVector<QString>  tokens;
    QVector<QString>  oprator;
    QVector<double> values;

};
#endif // MAINWINDOW_H
