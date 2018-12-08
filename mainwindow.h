#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "FlightBooking/includes.h"
#include "FlightBooking/List.h"
#include "FlightBooking/FlightBooking.h"
#include "flightinfo.h"
#include "addflightdialog.h"
#include <QMainWindow>
#include "FlightBooking/globals.h"

using namespace Global;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void reloadTable();
    ~MainWindow();

    void addRow(int id, int reserved, int capacity);

private slots:

    void on_flightsTable_cellDoubleClicked(int row, int column);

    void on_removeFlightButton_clicked();

    void on_addFlightButton_clicked();

private:
    Ui::MainWindow *ui;
    FlightList *flightList;
};

#endif // MAINWINDOW_H
