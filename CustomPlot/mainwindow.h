#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> //Tells the compiler to include things from the QMainWindow header file
//This defines the namespaces for the GUI widgets
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: //Notifies the compiler about functions that will be defined and used, they are actually defined in mainwindow.cpp
    void placeYint();
    void placeXint();
    double getSlope();
    void setSlope();
    const QString calcEquation();
    void setEquation();
    void addPoints(const double &xval);
    void setRange(const double &xyrange);
    void clearGraph();
    void log();
    void on_varValXincpt_valueChanged(double arg1);
    void on_varValYincpt_valueChanged(double arg1);

    void on_varValRange_valueChanged(double arg1);

private: //Notifies the compiler about variables that will be defined and used, they are actually defined in mainwindow.cpp
    Ui::MainWindow *ui; //This is just some shorthad for coding (insitead of wiritng Ui::Mainwindow::... to access ui functions, you can write: ui->...
    QVector<double> x,y;
    double xincpt;
    double yincpt;
    double xyrangeAt;
};

#endif // MAINWINDOW_H
