#ifndef ADDFLIGHTDIALOG_H
#define ADDFLIGHTDIALOG_H

#include <QDialog>

namespace Ui {
class AddFlightDialog;
}

class AddFlightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFlightDialog(QWidget *parent = nullptr);
    ~AddFlightDialog();

    int selectedID;
    int selectedCapacity;
    bool shouldAdd = false;

private slots:
    void on_addFlight_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddFlightDialog *ui;

};

#endif // ADDFLIGHTDIALOG_H
