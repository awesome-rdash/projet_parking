#include "parking.h"

Parking::Parking(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateNbre()));
    m_timer->start(1000);
    qDebug() << "Parking initialisé";
/*
    rfcomm = new AndroidRfComm();

    if (rfcomm->isEnabled()) {
        rfcomm->connect("arduino_parking");
        if (rfcomm->isConnected()) {
            rfcomm->sendLine("a");
            QString received=rfcomm->receiveLine(200, 100);
            qDebug() << received;
        }
    }*/

    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    qDebug() << "Socket créé";
    socket->connectToService(QBluetoothAddress("00:13:EF:00:06:4F"), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);
    qDebug() << "Tentative de connection";
}

Parking::~Parking()
{

    qDebug() << "Destructeur";
}

QString Parking::updateNbreFromBt()
{
    /*rfcomm->sendLine("a");
    QString received=rfcomm->receiveLine(200, 100);
    qDebug() << received;*/
    QString received = "";


    return received;
}

void Parking::updateNbre()
{
    QByteArray target;
    QDataStream s(&target, QIODevice::ReadWrite);
    const char valeur = 'a';
    s << valeur;
    socket->write(target);
    Q_EMIT messageChanged();
    qDebug() << "Envoie de A sur l'arduino";
}

void Parking::setMessage(const QString &Message)
{
    m_nbrePlaces = Message;
    Q_EMIT messageChanged();
    qDebug() << "setMessage";
}

int Parking::randNbre(int low, int high)
{
    qDebug() << "random";
    return qrand() % ((high + 1) - low) + low;
}

QString Parking::nbrePlaces()
{
    qDebug() << "nbrePlaces retourné";
    return m_nbrePlaces;
}

