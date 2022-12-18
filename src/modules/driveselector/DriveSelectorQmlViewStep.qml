import QtQuick 2.0
import Calamares 1.0

Page {
title: i18nc("@title:window", "Select Drive")

Column {
    spacing: Calamares.defaultSpacing

    Label {
        text: i18nc("@label", "Please select the drive you want to install %1 on:", Calamares.branding.productName)
    }

    ComboBox {
        model: driveList
        textRole: "rootPath"
        currentIndex: -1
        onCurrentIndexChanged: {
            // update the selectedDrive property when the user selects a different drive
            DriveSelectorQmlViewStep.selectedDrive = model.get(currentIndex).rootPath
    }
}
}
}