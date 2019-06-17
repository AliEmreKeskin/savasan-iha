#ifndef WIDGETALT_CPP
#define WIDGETALT_CPP
#endif

#include "widgetalt.h"
#include "ui_WidgetALT.h"

WidgetALT::WidgetALT( QWidget *parent ) : QWidget( parent ),
    m_ui( new Ui::WidgetALT ),
    m_alt ( 0 )
{
    m_ui->setupUi( this );
    m_alt = m_ui->graphicsALT;
}

WidgetALT::~WidgetALT()
{
    if ( m_ui ) delete m_ui; m_ui = 0;
}
