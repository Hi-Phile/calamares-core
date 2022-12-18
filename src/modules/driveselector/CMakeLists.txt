set(MODULE_NAME driveselector)

if(NOT WITH_QML)
    calamares_skip_module( "driveselector (QML is not supported in this build)" )
    return()
endif()

find_package(Qt5 ${QT_VERSION} CONFIG COMPONENTS DBus Network)
if(NOT TARGET Qt5::DBus OR NOT TARGET Qt5::Network)
    calamares_skip_module( "driveselector (missing DBus or Network)" )
    return()
endif()

calamares_add_plugin(${MODULE_NAME}
    TYPE viewmodule
    EXPORT_MACRO PLUGINDLLEXPORT_PRO
    SOURCES
        DriveSelectorQmlViewStep.cpp
        Config.cpp
    RESOURCES
        DriveSelectorQmlViewStep.qrc
    LINK_PRIVATE_LIBRARIES
        Qt5::DBus
    SHARED_LIB
)