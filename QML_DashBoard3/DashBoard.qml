import QtQuick 2.0

Rectangle {
    property int speed
    property int rpm

    id: dashBoard
    state: "stopped"
    color: "black"
    gradient: Gradient {
        id: backgroundGradient
        GradientStop {
            position: 0.7
            color: "black"
        }
        GradientStop {
            id: myGradientStop
            position: 1.0
            color: "blue"
        }
    }

    Column {
        anchors.fill: parent
        Row {
            id: row
            width: parent.width
            height: parent.height - 100

            SpeedMeter {
                id: speedMeter
                speed: dashBoard.speed;
                height: parent.height
                width: parent.width / 2
            }

            Image {
                id: rpmMeterImage
                source: "tacho.png"
                height: parent.height
                width: parent.width / 2

                Image {
                    id: rpmNeedle
                    width: 13
                    height: 150
                    source: "needlered.png"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenterOffset: -height * 0.5
                    transformOrigin: Item.Bottom
                    rotation: -135
                    Behavior on rotation {
                        PropertyAnimation {
                            duration: 2000
                        }
                    }
                }
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onPressed: {
            rpmNeedle.rotation += 120
            speedMeter.setSpeed(200);
            myGradientStop.color = "red"
        }
        onReleased: {
            rpmNeedle.rotation -= 120
            speedMeter.setSpeed(0);
            myGradientStop.color = "blue"
        }
    }

    Rectangle {
        height: 50
        width: 50
        color: "white"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                dashBoard.state = "running"
            }
        }
    }
    states: [
        State {
            name: "stopped"
            PropertyChanges {
                target: myGradientStop;
                color: "blue"
            }
        },
        State {
            name: "running"
            PropertyChanges {
                target: myGradientStop
                color: "red"
                }

        }

    ]

}

