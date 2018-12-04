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
    void on_plotGraph_clicked(void) noexcept;
    void clear(void) noexcept;
    void setEquation(void) noexcept;
    void on_clearGraph_clicked(void) noexcept;
    const QString getVertex(void) noexcept;
    void setVertex(void) noexcept;
    void on_setRange_clicked() noexcept;
    void invertX() noexcept;
    void invertY() noexcept;
    void on_invertYbtn_clicked();

    void on_invertXbtn_clicked();

private: //Declaration of internal variables
    Ui::MainWindow *ui;
    double xyrangeAt;
    QVector<double> x, y;


};

#endif // MAINWINDOW_H
