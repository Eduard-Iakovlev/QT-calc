#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_button1_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 1;
    else operand = operand * 10 + 1;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button2_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 2;
    else operand = operand * 10 + 2;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button3_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 3;
    else operand = operand * 10 + 3;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button4_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 4;
    else operand = operand * 10 + 4;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button5_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 5;
    else operand = operand * 10 + 5;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button6_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 6;
    else operand = operand * 10 + 6;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button7_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 7;
    else operand = operand * 10 + 7;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_button8_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 8;
    else operand = operand * 10 + 8;
    updateLcdOperand();
     result = toString(operand);
}


void MainWindow::on_button9_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
    if(operand < 0)operand = operand * 10 - 9;
    else operand = operand * 10 + 9;
    updateLcdOperand();
     result = toString(operand);
}


void MainWindow::on_button0_clicked(){
    if(operation == '=' && operand == 0) on_buttonClear_clicked();
     operand = operand * 10;
    updateLcdOperand();
     result = toString(operand);
}


void MainWindow::on_buttonSign_clicked(){
    operand *= -1;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_buttonPlus_clicked(){
    calculation();
    if(result == error){
        return;
    }
    operand = 0;
    updateLcdOperand();
    result += "+";
    updateLineResult();
    operation = '+';
}


void MainWindow::on_buttonMinus_clicked(){
    calculation();
    if(result == error){
        return;
    }
    operand = 0;
    updateLcdOperand();
    result += "-";
    updateLineResult();
    operation = '-';

}


void MainWindow::on_buttonMult_clicked(){
    calculation();
    if(result == error){
        return;
    }
    operand = 0;
    updateLcdOperand();
    result += "*";
    updateLineResult();
    operation = '*';

}


void MainWindow::on_buttonDevide_clicked(){
    calculation();
    if(result == error){
        return;
    }
    operand = 0;
    updateLcdOperand();
    result += "/";
    updateLineResult();
    operation = '/';

}


void MainWindow::on_buttonEquals_clicked(){
    calculation();
    updateLineResult();
    operand = 0;
    updateLcdOperand();
    operation = '=';
}


void MainWindow::on_buttonBackspace_clicked(){
    operand = (int)operand / 10;
    updateLcdOperand();
    result = toString(operand);
}


void MainWindow::on_buttonClear_clicked(){
    operand = 0;
    res = 0;
    operation = '\0';
    updateLcdOperand();
    result.clear();
    updateLineResult();
}

void MainWindow::updateLcdOperand(){
    ui->lcdOperand->display(operand);
}

void MainWindow::updateLineResult(){
    ui->lineResult->setText(QString::fromStdString(result));
}

void MainWindow::calculation(){
    switch (operation) {
    case '+':
        res += operand;
        result = toString(res);
        break;
    case '-':
        res -= operand;
        result = toString(res);
        break;
    case '*':
        res *= operand;
        result = toString(res);
        break;
    case '/':
        if(operand == 0){
            result = error;
            updateLineResult();
            operand = 0;
            operation = '\0';
            res = 0;
            break;
        }
        res /= operand;
        result = toString(res);
        break;
    default:
        if(operation != '=')res = operand;
        break;
    }
}

std::string MainWindow::toString(double res){
    std::string str = std::to_string(res);
    for(size_t iter = str.size()-1; iter > 0; iter--){
        if(str[iter] == '.'){
            str[iter] = '\0';
            break;
        }
        if(str[iter] != '0') break;
        else str[iter] = '\0';
    }
    return str;
}



