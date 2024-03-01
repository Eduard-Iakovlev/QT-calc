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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_button0_clicked();
    void on_buttonSign_clicked();
    void on_buttonPlus_clicked();
    void on_buttonMinus_clicked();
    void on_buttonMult_clicked();
    void on_buttonDevide_clicked();
    void on_buttonEquals_clicked();
    void on_buttonBackspace_clicked();
    void on_buttonClear_clicked();

    void updateLcdOperand();
    void updateLineResult();
    void calculation();
    std::string toString(double);

private:
    char operation{};
    double operand = 0;
    double res = 0;
    std::string result{};
    std::string error = "ERROR";
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
