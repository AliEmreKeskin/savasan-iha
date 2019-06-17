#ifndef WIDGETADI_CPP
#define WIDGETADI_CPP
#endif

#include "widgetadi.h"
#include "ui_WidgetADI.h"

WidgetADI::WidgetADI( QWidget *parent ) : QWidget( parent ), m_ui( new Ui::WidgetADI ), m_adi ( 0 )
{
    m_ui->setupUi( this );
    m_adi = m_ui->graphicsADI;
}

WidgetADI::~WidgetADI()
{
    if ( m_ui ) delete m_ui; m_ui = 0;
}
