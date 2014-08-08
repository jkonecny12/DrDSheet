import QtQuick 2.2
import QtQuick.Controls 1.2

// TODO: complete this


Item {
    id: root

    ListView {
        id: charactersView

        anchors.fill: parent

        model: charactersModel
        delegate: characterDelegate
    }

    Component {
        id: characterDelegate

        Item {

            width: parent.width
            height: 35

            Text {
                text: name
            }

        }
    }


    ListModel {
        id: charactersModel

        ListElement {
            name: "BigBrother"
            //class: "wtf"

        }

        ListElement {
            name: "test"
        }

        ListElement {
            name: "test2"
        }
    }
}
