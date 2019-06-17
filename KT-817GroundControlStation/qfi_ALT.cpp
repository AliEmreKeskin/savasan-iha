#ifndef QFI_ALT_CPP
#define QFI_ALT_CPP
#endif

#ifdef WIN32
#   include <float.h>
#endif

#include <math.h>
#include "qfi_ALT.h"

qfi_ALT::qfi_ALT( QWidget *parent ) :
    QGraphicsView ( parent ),

    m_scene ( 0 ),

    m_itemFace_1 ( 0 ),
    m_itemFace_2 ( 0 ),
    m_itemFace_3 ( 0 ),
    m_itemHand_1 ( 0 ),
    m_itemHand_2 ( 0 ),
    m_itemCase   ( 0 ),

    m_altitude (  0.0f ),
    m_pressure ( 28.0f ),

    m_scaleX ( 1.0f ),
    m_scaleY ( 1.0f ),

    m_originalHeight ( 580 ),
    m_originalWidth  ( 600 ),

    m_originalAltCtr ( 120.0f , 120.0f ),

    m_face1Z ( -50 ),
    m_face2Z ( -40 ),
    m_face3Z ( -30 ),
    m_hand1Z ( -20 ),
    m_hand2Z ( -10 ),
    m_caseZ  (  10 )
{
    reset();

    m_scene = new QGraphicsScene( this );
    setScene( m_scene );

    m_scene->clear();

    init();
}

////////////////////////////////////////////////////////////////////////////////

qfi_ALT::~qfi_ALT()
{
    if ( m_scene )
    {
        m_scene->clear();
        delete m_scene;
        m_scene = 0;
    }

    reset();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::setAltitude( float altitude )
{
    m_altitude = altitude;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::setPressure( float pressure )
{
    m_pressure = pressure;

    if ( m_pressure < 28.0f ) m_pressure = 28.0f;
    if ( m_pressure > 31.5f ) m_pressure = 31.5f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;

    reset();

    m_itemFace_1 = new QGraphicsSvgItem( ":/qfi/images/alt/alt_face_1.svg" );
    m_itemFace_1->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace_1->setZValue( m_face1Z );
    m_itemFace_1->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemFace_1->setTransformOriginPoint( m_originalAltCtr );
    m_scene->addItem( m_itemFace_1 );

    m_itemFace_2 = new QGraphicsSvgItem( ":/qfi/images/alt/alt_face_2.svg" );
    m_itemFace_2->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace_2->setZValue( m_face2Z );
    m_itemFace_2->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemFace_2 );

    m_itemFace_3 = new QGraphicsSvgItem( ":/qfi/images/alt/alt_face_3.svg" );
    m_itemFace_3->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace_3->setZValue( m_face3Z );
    m_itemFace_3->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemFace_3->setTransformOriginPoint( m_originalAltCtr );
    m_scene->addItem( m_itemFace_3 );

    m_itemHand_1 = new QGraphicsSvgItem( ":/qfi/images/alt/alt_hand_1.svg" );
    m_itemHand_1->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand_1->setZValue( m_hand1Z );
    m_itemHand_1->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemHand_1->setTransformOriginPoint( m_originalAltCtr );
    m_scene->addItem( m_itemHand_1 );

    m_itemHand_2 = new QGraphicsSvgItem( ":/qfi/images/alt/alt_hand_2.svg" );
    m_itemHand_2->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand_2->setZValue( m_hand2Z );
    m_itemHand_2->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemHand_2->setTransformOriginPoint( m_originalAltCtr );
    m_scene->addItem( m_itemHand_2 );

    m_itemCase = new QGraphicsSvgItem( ":/qfi/images/alt/alt_case.svg" );
    m_itemCase->setCacheMode( QGraphicsItem::NoCache );
    m_itemCase->setZValue( m_caseZ );
    m_itemCase->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemCase );

    centerOn( width() / 2.0f , height() / 2.0f );

    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::reset()
{
    m_itemFace_1 = 0;
    m_itemFace_2 = 0;
    m_itemFace_3 = 0;
    m_itemHand_1 = 0;
    m_itemHand_2 = 0;
    m_itemCase   = 0;

    m_altitude =  0.0f;
    m_pressure = 28.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_ALT::updateView()
{
    int altitude = ceil( m_altitude + 0.5 );

    float angleH1 = m_altitude * 0.036f;
    float angleH2 = ( altitude % 1000 ) * 0.36f;
    float angleF1 = ( m_pressure - 28.0f ) * 100.0f;
    float angleF3 = m_altitude * 0.0036f;

    m_itemHand_1->setRotation(   angleH1 );
    m_itemHand_2->setRotation(   angleH2 );
    m_itemFace_1->setRotation( - angleF1 );
    m_itemFace_3->setRotation(   angleF3 );

    m_scene->update();
}
