import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 400
    height: 400
    title: qsTr("Hello world!")
    Rectangle {
        id: bacgroundRocket
        width: parent.width;
        height: parent.height;
        color: "gray"
        Image {
            id: rocket
            x: 50; y: 50
            source: "rocket.png"
            transformOrigin: Item.Center
        }
        Keys.onLeftPressed: rocket.rotation = (rocket.rotation - 10) % 360
        Keys.onRightPressed: rocket.rotation = (rocket.rotation + 10) % 360
        focus: true
        }

    Rectangle {
        id: myButton
        color: "blue"

        width: 10
        height: 50

        Text {
            text: "Click me"
            anchors.centerIn: myButton
        }
        MouseArea {
            anchors.fill: myButton
            onPressed: {
             myButton.color = "lightblue"
             myButton.scale = 0.9
            }
            onReleased: {
             myButton.color = "blue"
             myButton.scale = 1.0
            }

            onClicked: {
                greenRectangle.color = "red"
            }
        }
    }

}
/*
 Rectangle {
        id: backgroundRect
        width: parent.width
        height: parent.height
        color: "grey"
        Rectangle {
            id: lightblueRect
            x: 50
            y: 50
            width: parent.width - 100
            height: (parent.height - 100 )/2
            color: "lightblue"
            Rectangle {
                x: 50
                y: 50
                width: 50
                height: 50
                color: "white"
            }
        }

*/
