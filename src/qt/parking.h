#ifndef PARKING_H
#define PARKING_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QBluetoothSocket>

static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));

class Parking : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString places READ nbrePlaces NOTIFY messageChanged)

public:
    explicit Parking(QObject *parent = 0);
    ~Parking();
    int randNbre(int low, int high);
    QString nbrePlaces();


public slots:
    void updateNbre();
    void setMessage(const QString &Message);
    void cmdRecv();

    //Bluetooth slots
    void connectionEtablished();

Q_SIGNALS:
    void messageChanged();

private:
    QTimer *m_timer;
    QString m_nbrePlaces;
    //AndroidRfComm *rfcomm;
    QBluetoothSocket *socket;
};

#endif // PARKING_H
