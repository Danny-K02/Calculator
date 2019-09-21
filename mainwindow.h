#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <iostream>
#include <QMainWindow>
using namespace std;

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
    void digits_numbers();

    void on_dot_clicked();

    void operations();

    void on_clear_clicked();

    void on_summ_clicked();

    void math_operations();

    void on_backsp_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
