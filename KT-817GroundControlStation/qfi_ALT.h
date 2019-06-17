#ifndef QFI_ALT_H
#define QFI_ALT_H

////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

////////////////////////////////////////////////////////////////////////////////

/** Barometric Altimeter widget. */
class qfi_ALT : public QGraphicsView
{
    Q_OBJECT

public:

    /** Constructor. */
    qfi_ALT( QWidget *parent = 0 );

    /** Destructor. */
    virtual ~qfi_ALT();

    /** Reinitiates widget. */
    void reinit();

    /** Refreshes (redraws) widget. */
    void update();

    /** @param altitude [ft] */
    void setAltitude( float altitude );

    /** @param pressure [inHg] */
    void setPressure( float aressure );

protected:

    void resizeEvent( QResizeEvent *event );

private:

    QGraphicsScene *m_scene;

    QGraphicsSvgItem *m_itemFace_1;
    QGraphicsSvgItem *m_itemFace_2;
    QGraphicsSvgItem *m_itemFace_3;
    QGraphicsSvgItem *m_itemHand_1;
    QGraphicsSvgItem *m_itemHand_2;
    QGraphicsSvgItem *m_itemCase;

    float m_altitude;
    float m_pressure;

    float m_scaleX;
    float m_scaleY;

    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalAltCtr;

    const int m_face1Z;
    const int m_face2Z;
    const int m_face3Z;
    const int m_hand1Z;
    const int m_hand2Z;
    const int m_caseZ;

    void init();

    void reset();

    void updateView();
};

////////////////////////////////////////////////////////////////////////////////

#endif // QFI_ALT_H
