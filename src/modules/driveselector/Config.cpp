/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2020 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is Free Software: see the License-Identifier above.
 *
 */

#include <QObject>
#include "DllMacro.h"
#include "utils/PluginFactory.h"

#include "Config.h"

#include "utils/CalamaresUtilsSystem.h"
#include "utils/Logger.h"
#include "utils/Variant.h"



Config::Config( QObject* parent )
    : QObject( parent )
{
    
}

void
Config::setConfigurationMap( const QVariantMap& configurationMap )
{

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

