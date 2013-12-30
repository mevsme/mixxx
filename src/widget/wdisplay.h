/***************************************************************************
                          wdisplay.h  -  description
                             -------------------
    begin                : Fri Jun 21 2002
    copyright            : (C) 2002 by Tue & Ken Haste Andersen
    email                : haste@diku.dk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef WDISPLAY_H
#define WDISPLAY_H

#include <QVector>
#include <QPixmap>
#include <QPaintEvent>
#include <QString>

#include "widget/wwidget.h"
#include "widget/wpixmapstore.h"

class WDisplay : public WWidget {
   Q_OBJECT
  public:
    WDisplay(QWidget *parent=NULL);
    virtual ~WDisplay();

    void setup(QDomNode node);

  protected:
    void paintEvent(QPaintEvent*);

    int numPixmaps() const {
        return m_pixmaps.size();
    }

  private:

    void setPixmap(QVector<QPixmapPointer>* pPixmaps, int iPos,
                   const QString& filename);

    void setPixmapBackground(const QString& filename);

    void setPositions(int iNoPos);

    virtual int getActivePixmapIndex() const;

    // Free existing pixmaps.
    void resetPositions();

    // Associated background pixmap
    QPixmapPointer m_pPixmapBack;

    // List of associated pixmaps.
    QVector<QPixmapPointer> m_pixmaps;

    // Whether disabled pixmaps are loaded.
    bool m_bDisabledLoaded;

    // List of disabled pixmaps.
    QVector<QPixmapPointer> m_disabledPixmaps;
};

#endif
