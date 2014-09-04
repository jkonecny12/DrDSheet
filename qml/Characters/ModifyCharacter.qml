import QtQuick 2.2

import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

import cz.ps.Models 1.0
import cz.ps.Managers 1.0

Item {
    id: root

    anchors.fill: parent

    focus: true

    signal back

    Keys.onReleased: {
        if(event.key === Qt.Key_Back)
        {
            back()
            console.log("back button catched")
            event.accepted = true
        }
    }

    RowLayout {
        id: buttonsLayout

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        Button {
            id: okBtn

            text: qsTr("OK")

            Layout.fillWidth: true
        }

        Button {
            id: cancelBtn

            text: qsTr("Zrušit")

            Layout.fillWidth: true
        }
    }
}
