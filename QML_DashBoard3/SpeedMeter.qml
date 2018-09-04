import QtQuick 2.4

Image {
    property int speed
    id: speedMeterImage
    source: "speedo.png"
    Image {
        id: speedNeedle
        width: 13
        height: 150
        source: "needlered.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: -height * 0.5
        transformOrigin: Item.Bottom
        rotation: transferSpeedToRotation( speed );
        Behavior on rotation {
            PropertyAnimation {
                duration: 2000
            }
        }
    }
    function transferSpeedToRotation( speed ){
        return speed - 135;
    }

    // called from outside
    function setSpeed( speed ){
        speedNeedle.rotation = transferSpeedToRotation( speed );
    }
}





