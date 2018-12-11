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
    void setRange(const double &xyrange) noexcept;
    void plot(void) noexcept;
    void clear(void) noexcept;
    void setEquation(void) noexcept;
    const QString getVertex(void) noexcept;
    void setVertex(void) noexcept;
    void invertX() noexcept;
    void invertY() noexcept;
    void on_invertYbtn_clicked() noexcept;
    void on_invertXbtn_clicked() noexcept;
    void on_valueRange_valueChanged(double arg1) noexcept;
    void on_valueA_valueChanged(double arg1) noexcept;
    void on_valueB_valueChanged(double arg1) noexcept;
    void on_valueC_valueChanged(double arg1) noexcept;

private: //Declaration of internal variables
    Ui::MainWindow *ui;
    double xyrangeAt;
    QVector<double> x, y;


};

#endif // MAINWINDOW_H
