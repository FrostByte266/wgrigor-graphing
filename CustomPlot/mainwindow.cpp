#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <string>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Constructor
    ui->setupUi(this);
    //Initialize graph
    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("𝓍");
    ui->customPlot->yAxis->setLabel("𝓎");
    MainWindow::setRange(10);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);



}

MainWindow::~MainWindow()
{
    //Destructor
    delete ui;
}
void MainWindow::placeYint()
{
    const double ystat=ui->varValYincpt->QDoubleSpinBox::value(); //Get user input
    yincpt = ystat;
    //Insert calculated data into container
    y.append(ystat);
    x.append(0);
    //Plot on graph
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->replot();
}


void MainWindow::placeXint()
{
    const double xstat=ui->varValXincpt->QDoubleSpinBox::value(); //Get user input
    xincpt=xstat;
    //Insert calculated data into container
    y.append(0);
    x.append(xstat);
    //Plot on graph
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->replot();
}


double MainWindow::getSlope()
{
    const double slope = (yincpt)/(xincpt); //m=rise/run
    return -slope;
}

void MainWindow::setSlope()
{
    QString slopeText = QString::number(getSlope()); //Calculate slope
    ui->MainWindow::slopeValue->setText(slopeText); //Update UI
}

const QString MainWindow::calcEquation(){
    QString equation;
    //Formulate data into a string to display
    equation="𝓎=" + QString::number(getSlope()) + "𝓍+ " + QString::number(yincpt);
    return equation;
}

void MainWindow::setEquation(){
    //Update UI with the equation
    QString equationText = calcEquation();
    ui->MainWindow::equationValue->setText(equationText);
}

void MainWindow::addPoints(const double& xval){
    const double yval = (getSlope()*xval)+yincpt; //y=mx+b
    //Insert to container
    x.append(xval);
    y.append(yval);
    //Plot on graph
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->update();
    ui->customPlot->replot();
}
void MainWindow::setRange(const double& xyrange){
    //Update graph ranges
    ui->customPlot->xAxis->setRange(-xyrange, xyrange);
    ui->customPlot->yAxis->setRange(-xyrange, xyrange);
    //Update header defined gloabl
    xyrangeAt=xyrange;
}

void MainWindow::clearGraph(){
    //Empty data container
    x.clear();
    y.clear();
    //Replot with empty container (clear)
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->update();
    ui->customPlot->replot();
    //Update UI
    ui->MainWindow::slopeValue->setText(nullptr);
    ui->MainWindow::equationValue->setText(nullptr);
}

void MainWindow::log(){ //Debugging
    for(int i = 0; i <= x.size(); i++)
        std::cerr << x.at(i) << " , " << y.at(i) << std::endl;
}


//Update graph on UI input changes

void MainWindow::on_varValXincpt_valueChanged(double arg1)
{
    clearGraph();
    placeYint();
    placeXint();
    addPoints(-xyrangeAt);
    addPoints(xyrangeAt);
    setSlope();
    setEquation();
    log();
}

void MainWindow::on_varValYincpt_valueChanged(double arg1)
{
    clearGraph();
    placeYint();
    placeXint();
    addPoints(-xyrangeAt);
    addPoints(xyrangeAt);
    setSlope();
    setEquation();
    log();
}

void MainWindow::on_varValRange_valueChanged(double arg1)
{
    clearGraph();
    setRange(arg1);
    clearGraph();
    placeYint();
    placeXint();
    addPoints(-xyrangeAt);
    addPoints(xyrangeAt);
    setSlope();
    setEquation();
    log();
}
