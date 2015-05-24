#include "datapackagehandler.h"

#include <QRegExp>
#include <QList>
#include <QDebug>

DataPackageHandler::DataPackageHandler()
{

}

void DataPackageHandler::handleNewData(const QByteArray &theByteArray)
{
    //QRegExp rx("(\\ |\\,|\\.|\\:|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
    QList<QByteArray> theList = theByteArray.split(' ');
    QList<double> theDoubleList;

    bool ok;
    for (QList<QByteArray>::const_iterator iterator = theList.begin(), end = theList.begin()+theList.size(); iterator != end; ++iterator) {
        theDoubleList.append((*iterator).toDouble(&ok));
    }
    while (theDoubleList.size()<theList.size())
        theDoubleList.append(0);

    m_lastDoublesReceived = theDoubleList;
    //m_packages.append(theDoubleList);
}
QVector<QList<double> > DataPackageHandler::packages() const
{
    return m_packages;
}
QList<double> DataPackageHandler::lastDoublesReceived() const
{
    return m_lastDoublesReceived;
}
