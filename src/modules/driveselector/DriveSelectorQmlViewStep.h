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

class DriveSelectorQmlViewStep : public Calamares::QmlViewStep
{
Q_OBJECT
Q_PROPERTY(QString selectedDrive READ selectedDrive WRITE setSelectedDrive NOTIFY selectedDriveChanged)

public:
    explicit DriveSelectorQmlViewStep(QObject *parent = nullptr);
    // expose all drives to QML
    QVariantList m_driveList;

    QString selectedDrive() const;
    QString prettyName() const override;

signals:
    void selectedDriveChanged();

public slots:
    void setSelectedDrive(const QString& drive);

private:
    QString m_selectedDrive;
};

CALAMARES_PLUGIN_FACTORY_DECLARATION( DriveSelectorQmlViewStepFactory )

#endif // DRIVESELECTORQMLVIEWSTEP_H
