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

        model: CharactersManager.model
        delegate: characterDelegate
    }

    Component {
        id: characterDelegate

        Item {

            width: parent.width
            height: 35

            Label {
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
