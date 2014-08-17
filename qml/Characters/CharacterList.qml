import QtQuick 2.2
import QtQuick.Controls 1.2

import cz.ps.Models 1.0
import cz.ps.Managers 1.0

// TODO: complete this


Item {
    id: root

    ListView {
        id: charactersView

        anchors.fill: parent

        focus: true

        model: CharactersManager.model
        delegate: characterDelegate
    }

    Component {
        id: characterDelegate

        Rectangle {
            id: delegateRoot

            width: parent.width
            height: delegateRoot.ListView.isCurrentItem ? 70 : 40

            color: "transparent"
            border.color: "black"

            MouseArea {
                id: itemMouseArea

                anchors.fill: parent

                onClicked: {
                    charactersView.currentIndex = index
                }
            }

            Label {
                text: name
                color: delegateRoot.ListView.isCurrentItem ? "white" : "red"
            }

        }
    }
}
