/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2020 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is Free Software: see the License-Identifier above.
 *
 */

#ifndef DRIVESELECTOR_CONFIG_H
#define DRIVESELECTOR_CONFIG_H

#include "Job.h"

#include "ThemeInfo.h"

#include <QObject>

class Config : public QObject
{
Q_OBJECT
Q_PROPERTY(QString selectedDrive READ selectedDrive WRITE setSelectedDrive NOTIFY selectedDriveChanged)
Q_PROPERTY( QVariantList driveList MEMBER m_driveList NOTIFY driveListChanged )


public:
    Config( QObject* parent = nullptr );QObject cleans up the model pointer
    void setConfigurationMap( const QVariantMap& );
    // Calamares::JobList createJobs() const;

signals:
    void selectedDriveChanged();
    void driveListChanged();

public slots:
    void setSelectedDrive(const QString& drive);

private:
    QString m_selectedDrive;
};

#endif