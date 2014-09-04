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

    Item {
        id: rootItem

        anchors.fill: parent

        state: "CHARLIST"

        states: [
            State {
                name: "CHARLIST"
                PropertyChanges {
                    target: charListScreen
                    visible: true
                }
            },

            State {
                name: "MODIFCHAR"
                PropertyChanges {
                    target: modifyCharacterScreen
                    visible: true
                }
            }
        ]

        CharacterList {
            id: charListScreen

            anchors.fill: parent

            visible: false

            onModifyCharacter: {
                rootItem.state = "MODIFCHAR"
            }

        }

        ModifyCharacter {
            id: modifyCharacterScreen

            anchors.fill: parent

            visible: false

            onBack: {
                rootItem.state = "CHARLIST"
            }
        }
    }
}
