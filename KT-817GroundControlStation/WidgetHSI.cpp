#ifndef WIDGETHSI_CPP
#define WIDGETHSI_CPP
#endif

#include "widgethsi.h"
#include "ui_WidgetHSI.h"

WidgetHSI::WidgetHSI( QWidget *parent ) :
    QWidget( parent ),
    m_ui( new Ui::WidgetHSI ),
    m_hsi ( 0 )
{
    m_ui->setupUi( this );
    m_hsi = m_ui->graphicsHSI;
}

WidgetHSI::~WidgetHSI()
{
    if ( m_ui ) delete m_ui; m_ui = 0;
}
