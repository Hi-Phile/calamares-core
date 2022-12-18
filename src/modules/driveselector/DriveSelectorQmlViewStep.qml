import io.calamares.core 1.0
import io.calamares.ui 1.0

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Page {
title: i18nc("@title:window", "Select Drive")
    //cenetered top text 
    Label {
        id: topText
        text: i18nc("@label", "Select the drive you want to install to.")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        font.pointSize: 20
        font.bold: true
    }
    Text {
        text: DriveSelectorQmlViewStep.driveList
    }
    ComboBox {
        model: driveList
        textRole: "rootPath"
        currentIndex: 1
        onCurrentIndexChanged: {
            // update the selectedDrive property when the user selects a different drive
            DriveSelectorQmlViewStep.selectedDrive = model.get(currentIndex).rootPath
        }
    }
}