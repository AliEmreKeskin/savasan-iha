#ifndef QFI_ASI_H
#define QFI_ASI_H

////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

////////////////////////////////////////////////////////////////////////////////

/** Airspeed Indicator widget. */
class qfi_ASI : public QGraphicsView
{
    Q_OBJECT

public:

    /** Constructor. */
    qfi_ASI( QWidget *parent = 0 );

    /** Destructor. */
    virtual ~qfi_ASI();

    /** Reinitiates widget. */
    void reinit();

    /** Refreshes (redraws) widget. */
    void update();

    /** @param airspeed [kts] */
    void setAirspeed( float airspeed );

protected:

    void resizeEvent( QResizeEvent *event );

private:

    QGraphicsScene *m_scene;

    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemCase;

    float m_airspeed;

    float m_scaleX;
    float m_scaleY;

    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalAsiCtr;

    const int m_faceZ;
    const int m_handZ;
    const int m_caseZ;

    void init();

    void reset();

    void updateView();
};

////////////////////////////////////////////////////////////////////////////////

#endif // QFI_ASI_H
