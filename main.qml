import QtQuick 2.12

Item {
    width: 200
    height: 200

    Rectangle {
        id: rect1
        width: 100
        height: 100
        color: "gray"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                KMJ.num += 1
            }
        }

        Text {
            id: txt1
            text: KMJ.num
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 50

            onTextChanged: {
                console.log("[qml] textchanged !")
            }
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_height:100;anchors_width:100}
}
##^##*/
