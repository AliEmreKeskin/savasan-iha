#ifndef QFI_HSI_CPP
#define QFI_HSI_CPP
#endif

#ifdef WIN32
#   include <float.h>
#endif

#include <math.h>
#include "qfi_HSI.h"

qfi_HSI::qfi_HSI( QWidget *parent ) :
    QGraphicsView ( parent ),

    m_scene ( 0 ),

    m_itemFace ( 0 ),
    m_itemCase ( 0 ),

    m_heading ( 0.0f ),

    m_scaleX ( 1.0f ),
    m_scaleY ( 1.0f ),

    m_originalHeight ( 580 ),
    m_originalWidth  ( 600 ),

    m_originalHsiCtr ( 120.0f , 120.0f ),

    m_faceZ ( -20 ),
    m_caseZ (  10 )
{
    reset();

    m_scene = new QGraphicsScene( this );
    setScene( m_scene );

    m_scene->clear();

    init();
}

qfi_HSI::~qfi_HSI()
{
    if ( m_scene )
    {
        m_scene->clear();
        delete m_scene;
        m_scene = 0;
    }

    reset();
}

void qfi_HSI::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

void qfi_HSI::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::setHeading( float heading )
{
    m_heading = heading;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;

    reset();

    m_itemFace = new QGraphicsSvgItem( ":/qfi/images/hsi/hsi_face.svg" );
    m_itemFace->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace->setZValue( m_faceZ );
    m_itemFace->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemFace->setTransformOriginPoint( m_originalHsiCtr );
    m_scene->addItem( m_itemFace );

    m_itemCase = new QGraphicsSvgItem( ":/qfi/images/hsi/hsi_case.svg" );
    m_itemCase->setCacheMode( QGraphicsItem::NoCache );
    m_itemCase->setZValue( m_caseZ );
    m_itemCase->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemCase );

    centerOn( width() / 2.0f , height() / 2.0f );

    updateView();
}

void qfi_HSI::reset()
{
    m_itemFace = 0;
    m_itemCase = 0;

    m_heading = 0.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::updateView()
{
    m_itemFace->setRotation( - m_heading );

    m_scene->update();
}
