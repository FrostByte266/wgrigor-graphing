//Tells the compiler to include the proper libraries and headers, the #include is a preprocessor directive,
//this tells the compiler it will need functions and variables from other files
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //This is called the constructor class, this happens whenever an object is created
    ui->setupUi(this);
    ui->customPlot->addGraph(); //Create the graph
    ui->customPlot->xAxis->setLabel("𝓍"); //Label the x axis
    ui->customPlot->yAxis->setLabel("𝓎"); //Label the y axis
    MainWindow::setRange(10); //Sets the range on the graph to 10
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); //Set the style of the points



}

MainWindow::~MainWindow() //Delete the main window when the program is closed with the "X" on the window
{
    delete ui;
}
void MainWindow::placeYint()
{
    double ystat=ui->varValYincpt->QDoubleSpinBox::value(); //Get the value of the y intercept from the ui and store it to variable
    yincpt = ystat; //Set the y intercept to the value from the menu
    y.append(ystat); //Add it to the list of y coordinates
    x.append(0); //Since it is the y intercept, x can be set to 0
    ui->customPlot->graph(0)->setData(x,y); //Tell the program what the graph's data is
    ui->customPlot->replot(); //Show the updated graph
}


void MainWindow::placeXint()
{
    double xstat=ui->varValXincpt->QDoubleSpinBox::value();
    xincpt=xstat;
    y.append(0);
    x.append(xstat);
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->replot();
}

void MainWindow::on_submitPlot_clicked()
{
    clearGraph();
    placeXint();
    placeYint();
    setSlope();
    setEquation();
    addPoints(xyrangeAt);
    addPoints(-xyrangeAt);
}

void MainWindow::on_submitClear_clicked()
{
    clearGraph();
}

double MainWindow::getSlope()
{
    double slope;
    slope = (yincpt)/(-xincpt);
    return slope;
}

void MainWindow::setSlope()
{
    QString slopeText = QString::number(getSlope());
    ui->MainWindow::slopeValue->setText(slopeText);
}

QString MainWindow::calcEquation(){
    QString equation;
    equation="𝓎=" + QString::number(getSlope()) + "𝓍+ " + QString::number(yincpt);
    return equation;
}

void MainWindow::setEquation(){
    QString equationText = calcEquation();
    ui->MainWindow::equationValue->setText(equationText);
}

void MainWindow::addPoints(const double& xval){
    double yval;
    yval=(getSlope()*xval)+yincpt;
    x.append(xval);
    y.append(yval);
    ui->customPlot->graph(0)->addData(x, y);
    ui->customPlot->update();
    ui->customPlot->replot();
}
void MainWindow::setRange(const double &xyrange){
    ui->customPlot->xAxis->setRange(-xyrange, xyrange);
    ui->customPlot->yAxis->setRange(-xyrange, xyrange);
    xyrangeAt=xyrange;
}

void MainWindow::on_submitRange_clicked()
{
    MainWindow::setRange(ui->varValRange->QDoubleSpinBox::value());
    if(ui->varValXincpt->QDoubleSpinBox::value() !=0.0 || ui->varValYincpt->QDoubleSpinBox::value() !=0.0){
        clearGraph();
        placeXint();
        placeYint();
        setSlope();
        setEquation();
        addPoints(xyrangeAt);
        addPoints(-xyrangeAt);
    }

    ui->customPlot->replot();
}
void MainWindow::clearGraph(){
    x.clear();
    y.clear();
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->update();
    ui->customPlot->replot();
    ui->MainWindow::slopeValue->setText(nullptr);
    ui->MainWindow::equationValue->setText(nullptr);
}
