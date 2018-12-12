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
private slots: //Declaration of functions
    void setRange(const double &xyrange) ;
    void plot(void);
    void clear(void);
    void setEquation(void);
    const QString getVertex(void);
    void setVertex(void);
    void invertX();
    void invertY();
    void on_invertYbtn_clicked();
    void on_invertXbtn_clicked();
    void on_valueRange_valueChanged(double arg1);
    void on_valueA_valueChanged(double arg1);
    void on_valueB_valueChanged(double arg1);
    void on_valueC_valueChanged(double arg1);

private: //Declaration of internal variables
    Ui::MainWindow *ui;
    double xyrangeAt;
    QVector<double> x, y;


};

#endif // MAINWINDOW_H
