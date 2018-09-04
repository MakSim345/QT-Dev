import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1024
    height: 580
    title: qsTr("Hello World")
    DashBoard {
        speed: dashboardData.speed
        rpm: dashboardData.rpm
        width: parent.width
        height: parent.height
    }
}
