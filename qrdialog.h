#ifndef QRDIALOG_H
#define QRDIALOG_H

#include <QDialog>

namespace Ui {
class QRDialog;
}

class QRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRDialog(QWidget *parent = nullptr);
    ~QRDialog();

private:
    Ui::QRDialog *ui;
};

#endif // QRDIALOG_H
