#ifndef QFI_HSI_H
#define QFI_HSI_H

#include <QGraphicsView>
#include <QGraphicsSvgItem>

/** Horizontal Situation Indicator widget. */
class qfi_HSI : public QGraphicsView
{
    Q_OBJECT

public:

    /** Constructor. */
    qfi_HSI( QWidget *parent = 0 );

    /** Destructor. */
    virtual ~qfi_HSI();

    /** Reinitiates widget. */
    void reinit();

    /** Refreshes (redraws) widget. */
    void update();

    /** @param heading [deg] */
    void setHeading( float heading );

protected:

    void resizeEvent( QResizeEvent *event );

private:

    QGraphicsScene *m_scene;

    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemCase;

    float m_heading;

    float m_scaleX;
    float m_scaleY;

    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalHsiCtr;

    const int m_faceZ;
    const int m_caseZ;

    void init();

    void reset();

    void updateView();
};

////////////////////////////////////////////////////////////////////////////////

#endif // QFI_HSI_H
