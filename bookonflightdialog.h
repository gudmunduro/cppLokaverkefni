#ifndef BOOKONFLIGHTDIALOG_H
#define BOOKONFLIGHTDIALOG_H

#include <QDialog>
#include "FlightBooking/List.h"
#include "FlightBooking/globals.h"

using namespace Global;

namespace Ui {
class BookOnFlightDialog;
}

class BookOnFlightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookOnFlightDialog(QWidget *parent = nullptr);
    ~BookOnFlightDialog();

    void prepareTable();
    void addRow(string ssn, string name, int age);
    string selectedPersonSSN = "";

private slots:
    void on_bookButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::BookOnFlightDialog *ui;
};

#endif // BOOKONFLIGHTDIALOG_H
