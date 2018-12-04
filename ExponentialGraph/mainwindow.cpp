#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();
    setRange(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRange(const double& xyRange){
    ui->customPlot->xAxis->setRange(-xyRange, xyRange);
    ui->customPlot->yAxis->setRange(-xyRange, xyRange);
    xyRangeAt = xyRange;
}

void MainWindow::plot(){
    const double iterations = xyRangeAt*100;
    for(int i=0; i<iterations; ++i){
        x.append(i);
        y.append(qExp(i/(ui->doubleSpinBox->QDoubleSpinBox::value())));
    }
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}



void MainWindow::on_pushButton_clicked()
{
    clear();
    plot();
}

void MainWindow::clear(){
    x.clear();
    y.clear();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}
