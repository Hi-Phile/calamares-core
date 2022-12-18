#include "DriveSelectorQmlViewStep.h"

#include "locale/TranslationsModel.h"
#include "GlobalStorage.h"

#include "JobQueue.h"
#include <QList>
#include <QStorageInfo>

CALAMARES_PLUGIN_FACTORY_DEFINITION( DriveSelectorQmlViewStepFactory, registerPlugin< DriveSelectorQmlViewStep >(); )

DriveSelectorQmlViewStep::DriveSelectorQmlViewStep( QObject* parent )
: Calamares::QmlViewStep( parent )
{
// get all drives present
QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();
// put them in a list
// make empty list
m_driveList = new QVariantList();
for ( const QStorageInfo& drive : drives )
{
m_driveList.append(drive.rootPath());
}
Q_PROPERTY(QString selectedDrive READ selectedDrive WRITE setSelectedDrive NOTIFY selectedDriveChanged)
// expose the list to QML

}

QString
DriveSelectorQmlViewStep::prettyName() const
{
return tr( "Drive Selector" );
}

QString
DriveSelectorQmlViewStep::selectedDrive() const
{
    return m_selectedDrive;
}

void
DriveSelectorQmlViewStep::setSelectedDrive(const QString& drive)
{
    if (m_selectedDrive != drive) {
        m_selectedDrive = drive;
        emit selectedDriveChanged();
    }
    auto gs = Calamares::JobQueue::instance()->globalStorage();
    gs->insert("selectedDrive", m_selectedDrive);
}
