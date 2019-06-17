#ifndef WIDGETASI_CPP
#define WIDGETASI_CPP
#endif

#include "widgetasi.h"
#include "ui_WidgetASI.h"

WidgetASI::WidgetASI( QWidget *parent ) : QWidget( parent ), m_ui( new Ui::WidgetASI ), m_asi ( 0 )
{
    m_ui->setupUi( this );
    m_asi = m_ui->graphicsASI;
}

WidgetASI::~WidgetASI()
{
    if ( m_ui ) delete m_ui; m_ui = 0;
}
