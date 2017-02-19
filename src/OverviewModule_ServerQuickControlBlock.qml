import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQuick.Controls.Material 2.0

Button {
    id: button
    width: 300
    height: 80
    property alias name: nameLabel.text
    property alias info: infoLabel.text
    property alias imageSource: actionImage.source
    Material.background:"White"
    Material.elevation:3

    Label {
        id: nameLabel
        width: 167
        height: 24
        text: qsTr("開啟伺服器檔案")
        anchors.left: actionImage.right
        anchors.leftMargin: 5
        anchors.top: actionImage.top
        anchors.topMargin: 8
        font.family: "Microsoft JhengHei UI"
        font.pointSize: 18
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
    }

    Label {
        id: infoLabel
        width: 63
        height: 24
        text: qsTr("Z:/")
        anchors.left: nameLabel.left
        anchors.leftMargin: 0
        anchors.top: nameLabel.bottom
        anchors.topMargin: 5
        font.family: "Microsoft JhengHei UI"
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        Material.foreground: "#757575"
    }

    Image {
        id: actionImage
        width: 64
        height: 64
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        source: "icon/ic_folder_black_48dp_2x.png"
    }
}
