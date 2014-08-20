import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

import cz.ps.Models 1.0
import cz.ps.Managers 1.0


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
            height: delegateRoot.ListView.isCurrentItem ? 150 : 40

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
                id: nameLabel

                anchors.top: parent.top
                anchors.left: parent.left

                text: name
            }

            Label {
                id: classLabel

                anchors.top: parent.top
                anchors.right: parent.right

                text: characterClass
            }

        }
    }
}
