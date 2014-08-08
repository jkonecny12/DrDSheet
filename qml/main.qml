import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

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
            bottom: addCharacterBtn.top
            left: parent.left
            right: parent.right
        }

    }

    Button {
        id: addCharacterBtn

        height: 30

        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        text: "Add character"
    }

}
