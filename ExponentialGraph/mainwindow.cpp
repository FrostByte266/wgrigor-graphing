#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <cmath>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();
    setRange(10);
    plot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRange(const double& xyRange){
    ui->customPlot->xAxis->setRange(-xyRange, xyRange);
    ui->customPlot->yAxis->setRange(-xyRange, xyRange);
    ui->customPlot->replot();
    xyRangeAt = xyRange;
}

void MainWindow::plot(){
    const double iterations = xyRangeAt;
    for(int i=-static_cast<int>(xyRangeAt); i<iterations; ++i){
        x.append(i);
        y.append(std::pow(ui->baseVal->value(), i));
        std::cerr << "X: " << i << " Y: " << std::pow(ui->baseVal->value(), i) << std::endl;
    }
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}

void MainWindow::clear(){
    x.clear();
    y.clear();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}


void MainWindow::on_baseVal_valueChanged(double arg1)
{
    clear();
    plot();
    displayEquation();
}

void MainWindow::on_rangeVal_valueChanged(double arg1)
{
    setRange(arg1);
}

void MainWindow::displayEquation(){
    const QString val = QString::number(ui->baseVal->value());
    const QString equation = "Equation: 𝑓(𝓍)=" + val + "ˣ";
    ui->dynamicEquationLabel->setText(equation);
}
