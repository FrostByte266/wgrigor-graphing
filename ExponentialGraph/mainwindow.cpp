#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <cmath>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Constructor
    ui->setupUi(this);
    //Initialize the graph
    ui->customPlot->addGraph();
    setRange(10);
    plot();
}

MainWindow::~MainWindow()
{
    //Destructor
    delete ui;
}

void MainWindow::setRange(const double& xyRange){
    //Set range to starting from the nexative end to the positive
    ui->customPlot->xAxis->setRange(-xyRange, xyRange);
    ui->customPlot->yAxis->setRange(-xyRange, xyRange);
    //Reset graph
    ui->customPlot->replot();
    //Update globabl variable
    xyRangeAt = xyRange;
}

void MainWindow::plot(){
    const double iterations = xyRangeAt;
    for(int i=-static_cast<int>(xyRangeAt); i<iterations; ++i){ //Recursively generate x and y tokens
        x.append(i);
        y.append(std::pow(ui->baseVal->value(), i)); //y=base^x
        std::cerr << "X: " << i << " Y: " << std::pow(ui->baseVal->value(), i) << std::endl; //Debug, outputs X and Y pair
    }
    //Update data container and replot
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}

void MainWindow::clear(){
    //Empty data container
    x.clear();
    y.clear();
    //Replot with empty container
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}

void MainWindow::displayEquation(){
    const QString val = QString::number(ui->baseVal->value()); //Get UI value
    const QString equation = "Equation: 𝑓(𝓍)=" + val + "ˣ"; //Format to template
    ui->dynamicEquationLabel->setText(equation); //Update UI
}

// Replot when UI values are changed

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
