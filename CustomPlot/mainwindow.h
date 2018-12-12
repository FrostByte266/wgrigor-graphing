#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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

private:
    Ui::MainWindow *ui;
    QVector<double> x,y;
    double xincpt;
    double yincpt;
    double xyrangeAt;
};

#endif // MAINWINDOW_H
