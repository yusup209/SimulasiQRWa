#include "qrdialog.h"
#include "ui_qrdialog.h"

QRDialog::QRDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRDialog)
{
    ui->setupUi(this);
}

QRDialog::~QRDialog()
{
    delete ui;
}
