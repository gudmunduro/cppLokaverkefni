#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "FlightBooking/includes.h"
#include "FlightBooking/List.h"
#include "FlightBooking/FlightBooking.h"
#include "flightinfo.h"
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
    void prepareTable();
    ~MainWindow();

    void addRow(int id, int reserved, int capacity);

private slots:

    void on_flightsTable_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    FlightList *flightList;
};

#endif // MAINWINDOW_H
