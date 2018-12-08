#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <QDialog>
#include "FlightBooking/FlightBooking.h"

namespace Ui {
class FlightInfo;
}

class FlightInfo : public QDialog
{
    Q_OBJECT

public:
    explicit FlightInfo(QWidget *parent = nullptr, FlightBooking *flight = nullptr);
    ~FlightInfo();

    void reloadTable();
    void addRow(string ssn, string name, int age, int seat);
private slots:
    void on_bookFlight_clicked();

    void on_unbookButton_clicked();

private:
    Ui::FlightInfo *ui;
    FlightBooking *flight;
};

#endif // FLIGHTINFO_H
