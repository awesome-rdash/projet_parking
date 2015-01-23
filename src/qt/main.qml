import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 320
    height: 480
    visible: true

    Text {
        id: nbrePlacesDisponibles
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 78
        property string places: parking.places
        onPlacesChanged: {
            nbrePlacesDisponibles.text = places;
        }
    }
}
