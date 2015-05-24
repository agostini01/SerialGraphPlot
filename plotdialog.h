#ifndef PLOTDIALOG_H
#define PLOTDIALOG_H

#include <QDialog>
#include <QTimer>
#include <datapackagehandler.h>
#include "qcustomplot.h"

namespace Ui {
class PlotDialog;
}

class PlotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlotDialog(QWidget *parent = 0);
    ~PlotDialog();

    void setupDemo(int demoIndex);
    void setupRealtimeDataDemo(QCustomPlot *customPlot);

    void atatchDataHandler(DataPackageHandler *handler);

private slots:
    void realtimeDataSlot();

private:
    Ui::PlotDialog *ui;
    QString demoName;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;
    int currentDemoIndex;
    DataPackageHandler *dataHandler;
};

#endif // PLOTDIALOG_H
