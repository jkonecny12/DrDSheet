import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

import "./Characters"

Window {
    id: root

    visible: true
    width: 360
    height: 360
    color: "silver"

    CharacterList {
        id: charList

        anchors {
            top: parent.top
            bottom: buttonsLayout.top
            left: parent.left
            right: parent.right
        }

    }

    RowLayout {
        id: buttonsLayout

        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        height: 25

        Button {
            id: createNew

            text: qsTr("Vytvořit")
        }

        Button {
            id: modifyNew

            text: qsTr("Upravit")
        }

        Button {
            id: deleteNew

            text: qsTr("Smazat")
        }
    }

}
