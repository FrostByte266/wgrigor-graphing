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
    void setRange(const double& xyRange);
    void plot();
    void clear();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    double xyRangeAt;
    QVector<double> x, y;
};

#endif // MAINWINDOW_H
