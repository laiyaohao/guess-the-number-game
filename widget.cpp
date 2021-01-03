#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // initialize
    srand(time(NULL));

    //generate
    secretNumber = rand() % 100 + 1;
    qDebug() << "Secret number generate: " << QString::number(secretNumber);
    ui->messageLabel->setText("");
    ui->startOverButton->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "Guess Number is: " << QString::number(guessNumber);
    if (secretNumber == guessNumber) {
        // congratz
        ui->messageLabel->setText("Congratz, the number you have guessed correcly is " + QString::number(guessNumber));
        // restart the app
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);

    }
    else {
        if (secretNumber > guessNumber) {
            ui->messageLabel->setText("Number is higher");
        }
        else {
            ui->messageLabel->setText("Number is lower");
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->guessButton->setDisabled(false); //enable the guess button again
    ui->startOverButton->setDisabled(true); // disable the startover button again
    ui->spinBox->setValue(1); // make spinbox go back to 1
    secretNumber = rand() % 100 + 1;

    ui->messageLabel->setText("");
}
