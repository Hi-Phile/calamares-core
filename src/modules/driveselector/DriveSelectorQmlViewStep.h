/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2019-2020 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is Free Software: see the License-Identifier above.
 *
 */

#ifndef DRIVESELECTORQMLVIEWSTEP_H
#define DRIVESELECTORQMLVIEWSTEP_H

#include <QObject>
#include "viewpages/QmlViewStep.h"
#include "utils/PluginFactory.h"
#include "DllMacro.h"
#include "Config.h"

class DriveSelectorQmlViewStep : public Calamares::QmlViewStep
{
public:
    explicit DriveSelectorQmlViewStep(QObject *parent = nullptr);
    // expose all drives to QML
    QVariantList m_driveList;
    QString selectedDrive() const;
    QString prettyName() const override;

private:
    // idk
};

CALAMARES_PLUGIN_FACTORY_DECLARATION( DriveSelectorQmlViewStepFactory )

#endif // DRIVESELECTORQMLVIEWSTEP_H
