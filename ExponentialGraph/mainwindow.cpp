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
        y.append(std::pow(ui->doubleSpinBox->value(), i));
        std::cerr << "X: " << i << " Y: " << std::pow(ui->doubleSpinBox->value(), i) << std::endl;
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


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    clear();
    plot();
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    setRange(arg1);
}
