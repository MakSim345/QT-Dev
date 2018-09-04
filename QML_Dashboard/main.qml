import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 600
    height: 300
    title: qsTr("Mersedes A-class")
    Rectangle {
        id: backgroundSpeed
        width: parent.width/2;
        height: parent.height;
        color: "black"
        Image {
            id: speed
            x: 0; y: 0
            width: parent.width;
            height: parent.height;
            source: "speedo.png"
            }
        Image {
            id: needleSpeed
            source: "needlered.png"

            width: 13
            height: parent.height/2.5

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: -height * 0.5
            transformOrigin: Item.Bottom

            Behavior on rotation {
            RotationAnimation {
                    duration: 1000
                }
             }
            rotation: -135

            }
        }

     Rectangle {
        id: backgroundPwm
        width: parent.width/2;
        height: parent.height;
        x: parent.width/2; y: 0
        color: "black"
        Image {
            id: taho
            x: 0; y: 0
            width: parent.width;
            height: parent.height;
            source: "tacho.png"
            }

        Image {
            id: needleRpm
            source: "needlered.png"
            width: 13
            height: parent.height/2.5
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: -height*0.5
            transformOrigin: Item.Bottom

            rotation: -125
            Behavior on rotation {
            RotationAnimation {
                    duration: 1000
                }
             }

            }
        }
     MouseArea {
      anchors.fill: parent
      onPressed: {
          needleSpeed.rotation += 120
          needleRpm.rotation += 110
      }
      onReleased: {
           needleSpeed.rotation = -135
           needleRpm.rotation = -125
      }
     }
}
