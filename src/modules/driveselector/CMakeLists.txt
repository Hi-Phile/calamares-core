set(MODULE_NAME driveselector)

calamares_add_plugin(${MODULE_NAME}
    TYPE viewmodule
    EXPORT_MACRO PLUGINDLLEXPORT_PRO
    SOURCES
        DriveSelectorQmlViewStep.cpp
    RESOURCES
        DriveSelectorQmlViewStep.qrc
)