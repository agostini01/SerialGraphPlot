#include "plotdialog.h"
#include "ui_plotdialog.h"
#include <QList>

PlotDialog::PlotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotDialog)
{
    ui->setupUi(this);
    setGeometry(400, 250, 542, 390);

    setupDemo(10);
}

PlotDialog::~PlotDialog()
{
    delete ui;
}

void PlotDialog::setupDemo(int demoIndex)
{
    switch (demoIndex)
    {

    case 10: setupRealtimeDataDemo(ui->customPlot); break;

    }
    setWindowTitle("QCustomPlot: "+demoName);
    //statusBar()->clearMessage();
    currentDemoIndex = demoIndex;
    ui->customPlot->replot();
}

void PlotDialog::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif
    demoName = "Real Time Data Demo";

    // include this section to fully disable antialiasing for higher performance:
    /*
  customPlot->setNotAntialiasedElements(QCP::aeAll);
  QFont font;
  font.setStyleStrategy(QFont::NoAntialias);
  customPlot->xAxis->setTickLabelFont(font);
  customPlot->yAxis->setTickLabelFont(font);
  customPlot->legend->setFont(font);
  */
    //Lines!!!
    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->addGraph(); // red line
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->addGraph(); // black line
    customPlot->graph(2)->setPen(QPen(Qt::black));
    customPlot->addGraph(); // cyan line
    customPlot->graph(3)->setPen(QPen(Qt::cyan));
    customPlot->addGraph(); // magenta line
    customPlot->graph(4)->setPen(QPen(Qt::magenta));
    customPlot->addGraph(); // yellow line
    customPlot->graph(5)->setPen(QPen(Qt::yellow));
    customPlot->addGraph(); // green line
    customPlot->graph(6)->setPen(QPen(Qt::green));
    customPlot->addGraph(); // gray line
    customPlot->graph(7)->setPen(QPen(Qt::gray));

    //Dots
    customPlot->addGraph(); // blue dot
    customPlot->graph(8)->setPen(QPen(Qt::blue));
    customPlot->graph(8)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(8)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // red dot
    customPlot->graph(9)->setPen(QPen(Qt::red));
    customPlot->graph(9)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(9)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // black dot
    customPlot->graph(10)->setPen(QPen(Qt::black));
    customPlot->graph(10)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(10)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // cyan dot
    customPlot->graph(11)->setPen(QPen(Qt::cyan));
    customPlot->graph(11)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(11)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // magenta dot
    customPlot->graph(12)->setPen(QPen(Qt::magenta));
    customPlot->graph(12)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(12)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // yellow dot
    customPlot->graph(13)->setPen(QPen(Qt::yellow));
    customPlot->graph(13)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(13)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // green dot
    customPlot->graph(14)->setPen(QPen(Qt::green));
    customPlot->graph(14)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(14)->setScatterStyle(QCPScatterStyle::ssDisc);
    customPlot->addGraph(); // gray dot
    customPlot->graph(15)->setPen(QPen(Qt::gray));
    customPlot->graph(15)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(15)->setScatterStyle(QCPScatterStyle::ssDisc);




    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setTickStep(2);
    customPlot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

void PlotDialog::atatchDataHandler(DataPackageHandler * handler)
{
    this->dataHandler = handler;
}

void PlotDialog::realtimeDataSlot()
{
    // calculate two new data points:
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    double key = 0;
#else
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.01) // at most add point every 10 ms
    {
        QList<double>::iterator iterator = (*dataHandler).lastDoublesReceived().begin();
        // QList<QByteArray>::const_iterator iterator = theList.begin()


        ++iterator; //skips time
        double value;


        if((ui->ch1Button->isChecked()))
        {
            value = *iterator + ui->ch1Offset->value();
            ui->customPlot->graph(0)->addData(key,value); // lines
            ui->customPlot->graph(8)->clearData();   // dots
            ui->customPlot->graph(8)->addData(key, value);
        }
        ++iterator;

        if((ui->ch2Button->isChecked()))
        {
            value = *iterator + ui->ch2Offset->value();
            ui->customPlot->graph(1)->addData(key,value); // lines
            ui->customPlot->graph(9)->clearData();   // dots
            ui->customPlot->graph(9)->addData(key, value);
        }
        ++iterator;

        if((ui->ch3Button->isChecked()))
        {
            value = *iterator + ui->ch3Offset->value();
            ui->customPlot->graph(2)->addData(key,value); // lines
            ui->customPlot->graph(10)->clearData();   // dots
            ui->customPlot->graph(10)->addData(key, value);
        }
        ++iterator;
        if((ui->ch4Button->isChecked()))
        {
            value = *iterator + ui->ch4Offset->value();
            ui->customPlot->graph(3)->addData(key,value); // lines
            ui->customPlot->graph(11)->clearData();   // dots
            ui->customPlot->graph(11)->addData(key, value);
        }
        ++iterator;
        if((ui->ch5Button->isChecked()))
        {
            value = *iterator + ui->ch5Offset->value();
            ui->customPlot->graph(4)->addData(key,value); // lines
            ui->customPlot->graph(12)->clearData();   // dots
            ui->customPlot->graph(12)->addData(key, value);
        }
        ++iterator;
        if((ui->ch6Button->isChecked()))
        {
            value = *iterator + ui->ch6Offset->value();
            ui->customPlot->graph(5)->addData(key,value); // lines
            ui->customPlot->graph(13)->clearData();   // dots
            ui->customPlot->graph(13)->addData(key, value);
        }
        ++iterator;
        if((ui->ch7Button->isChecked()))
        {
            value = *iterator + ui->ch7Offset->value();
            ui->customPlot->graph(6)->addData(key,value); // lines
            ui->customPlot->graph(14)->clearData();   // dots
            ui->customPlot->graph(14)->addData(key, value);
        }
        ++iterator;
        if((ui->ch8Button->isChecked()))
        {
            value = *iterator + ui->ch8Offset->value();
            ui->customPlot->graph(7)->addData(key,value); // lines
            ui->customPlot->graph(15)->clearData();   // dots
            ui->customPlot->graph(15)->addData(key, value);
        }



        // remove data of lines that's outside visible range:
        for(unsigned int i = 0; i<16; ++i)
            ui->customPlot->graph(i)->removeDataBefore(key-8);

        // rescale value (vertical) axis to fit the current data:
        for(unsigned int i = 0; i<15; ++i)
            ui->customPlot->graph(i)->rescaleValueAxis(true);
        ui->customPlot->graph(15)->rescaleValueAxis(true);


        lastPointKey = key;


    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
    ui->customPlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
        //    ui->statusBar->showMessage(
        //          QString("%1 FPS, Total Data points: %2")
        //          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
        //          .arg(ui->customPlot->graph(0)->data()->count()+ui->customPlot->graph(1)->data()->count())
        //          , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
}
