import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

import cz.ps.Models 1.0
import cz.ps.Managers 1.0


Item {
    id: root

    signal createNewCharacter
    signal modifyCharacter(int index)
    signal removeCharacter

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
                anchors.leftMargin: 3
                anchors.topMargin: 3

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
                anchors.rightMargin: 3
                anchors.topMargin: 3

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

    RowLayout {
        id: buttonsLayout

        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        height: 50

        Button {
            id: createNew

            text: qsTr("Vytvořit")

            Layout.fillWidth: true

            onClicked: {
                root.createNewCharacter()
            }
        }

        Button {
            id: modifyNew

            text: qsTr("Upravit")

            Layout.fillWidth: true

            onClicked: {
                root.modifyCharacter(charactersView.currentIndex)
            }
        }

        Button {
            id: deleteNew

            text: qsTr("Smazat")

            Layout.fillWidth: true

            onClicked: {
                root.removeCharacter()
            }
        }
    }
}
