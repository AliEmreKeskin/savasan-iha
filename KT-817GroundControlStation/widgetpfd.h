#ifndef WIDGETPFD_H
#define WIDGETPFD_H

#include <QWidget>
#include <qfi_PFD.h>

namespace Ui
{
    class WidgetPFD;
}

class WidgetPFD : public QWidget
{
    Q_OBJECT

public:

    explicit WidgetPFD( QWidget *parent = 0 );

    virtual ~WidgetPFD();

    inline void update()
    {
        m_pfd->update();
    }

    inline void setRoll( float roll )
    {
        m_pfd->setRoll( roll );
    }

    inline void setPitch( float pitch )
    {
        m_pfd->setPitch( pitch );
    }

    inline void setFlightPathMarker( float aoa, float sideslip )
    {
        m_pfd->setFlightPathMarker( aoa, sideslip );
    }

    inline void setSlipSkid( float slipSkid )
    {
        m_pfd->setSlipSkid( slipSkid );
    }

    inline void setDevH( float devH )
    {
        m_pfd->setBarH( devH );
        m_pfd->setDotH( devH );
    }

    inline void setDevV( float devV )
    {
        m_pfd->setBarV( devV );
        m_pfd->setDotV( devV );
    }

    inline void setAltitude( float altitude )
    {
        m_pfd->setAltitude( altitude );
    }

    inline void setPressure( float pressure )
    {
        m_pfd->setPressure( pressure, qfi_PFD::IN );
    }

    inline void setAirspeed( float airspeed )
    {
        m_pfd->setAirspeed( airspeed );
    }

    inline void setMachNo( float machNo )
    {
        m_pfd->setMachNo( machNo );
    }

    inline void setHeading( float heading )
    {
        m_pfd->setHeading( heading );
    }

    inline void setTurnRate( float turnRate )
    {
        m_pfd->setTurnRate( turnRate );
    }

    inline void setClimbRate( float climbRate )
    {
        m_pfd->setClimbRate( climbRate );
    }

    inline void setIdentifier( const QString &ident, bool isVisible )
    {
        m_pfd->setIdent( ident, isVisible );
    }

    inline void setDistance( float dist, bool isVisible )
    {
        m_pfd->setDistance( dist, isVisible );
    }

private:

    Ui::WidgetPFD *m_ui;
    qfi_PFD       *m_pfd;
};

#endif // WIDGETPFD_H
