
#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->n0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->n9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pars,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->perc,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->div,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->mult,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->mult->setCheckable(true);
    ui->div->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*) sender();
    double all_numbers;
    QString new_label;
    all_numbers=(ui->showresult->text()+button->text()).toDouble();
    new_label= QString::number(all_numbers,'g',15);

    ui->showresult->setText(new_label);
}

void MainWindow::on_dot_clicked()
{
    if(!(ui->showresult->text().contains('.')))
    {
        ui->showresult->setText(ui->showresult->text()+".");
    }
}
void MainWindow::operations()
{
    QPushButton *button = (QPushButton*) sender();
    double all_numbers;
    QString new_label;
    if(button->text()=="+/-")
    {
        all_numbers=(ui->showresult->text()).toDouble();
        all_numbers=all_numbers * -1;
        new_label= QString::number(all_numbers,'g',15);
    }
    else if(button->text()=="%")
    {
        all_numbers = (ui->showresult->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label= QString::number(all_numbers,'g',15);
    }
        ui->showresult->setText(new_label);

}
void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton*) sender();

    num_first = ui->showresult->text().toDouble();
    ui->showresult->setText("");
    button->setChecked(true);
}
void MainWindow::on_clear_clicked()
{
    ui->showresult->setText("");
}

void MainWindow::on_summ_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second=ui->showresult->text().toDouble();

    if(ui->plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->showresult->setText(new_label);
        ui->plus->setChecked(false);
    }
    else if(ui->minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->showresult->setText(new_label);
        ui->minus->setChecked(false);
    }
    else if(ui->mult->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->showresult->setText(new_label);
        ui->mult->setChecked(false);
    }
    else if(ui->div->isChecked())
    {
        if(num_second == 0)
        {
            ui->showresult->setText("inf");
        }
        else
        {


            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber,'g',15);
            ui->showresult->setText(new_label);
        }
        ui->div->setChecked(false);
    }
}

void MainWindow::on_backsp_clicked()
{
 /*   QPushButton *button = (QPushButton*) sender();
    double all_numbers;
    QString new_label;
    all_numbers=(ui->showresult->text()).toDouble();
    all_numbers=all_numbers
    new_label= QString::number(all_numbers,'g',15);

    ui->showresult->setText(new_label);*/
}
