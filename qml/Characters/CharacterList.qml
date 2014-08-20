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

    Character {
        id: characterTranslator
    }

    Component {
        id: characterDelegate

        Rectangle {
            id: delegateRoot

            anchors {
                margins: 3
            }

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

            Column {
                anchors.top: parent.top
                anchors.left: parent.left

                Label {
                    id: nameLabel

                    text: name
                }

                Label {
                    id: raceLabel

                    visible: delegateRoot.ListView.isCurrentItem ? true : false

                    text: characterTranslator.raceToString(race)
                }
            }

            Column {
                anchors.top: parent.top
                anchors.right: parent.right

                Label {
                    id: classLabel

                    text: characterTranslator.classToString(characterClass)
                }

                Label {
                    id: sexLabel

                    visible: delegateRoot.ListView.isCurrentItem ? true : false

                    text: characterTranslator.sexToString(sex)
                }
            }
        }
    }
}
