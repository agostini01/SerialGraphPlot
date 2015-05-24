#ifndef DATAPACKAGEHANDLER_H
#define DATAPACKAGEHANDLER_H

#include <QByteArray>
#include <QVector>

class DataPackageHandler
{
public:
    DataPackageHandler();

    // The handling machanism can be edited in this function
    void handleNewData(const QByteArray &theByteArray);

    QVector<QList<double> > packages() const;

    QList<double> lastDoublesReceived() const;

private:
    QByteArray m_lastReceived;
    QList<double> m_lastDoublesReceived;
    QVector<QList<double> > m_packages;    // Calls datapackage with doubles... should be changed for other classes
};



#endif // DATAPACKAGEHANDLER_H
