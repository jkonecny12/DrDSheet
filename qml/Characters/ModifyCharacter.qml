import QtQuick 2.2

import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

import cz.ps.Models 1.0
import cz.ps.Managers 1.0

Item {
    id: root

    anchors.fill: parent

    RowLayout {
        id: buttonsLayout

        anchors.bottom: parent.bottom

        Button {
            id: okBtn

            text: qsTr("OK")
        }

        Button {
            id: cancelBtn

            text: qsTr("Zrušit")
        }
    }
}
