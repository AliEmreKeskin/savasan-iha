#ifndef WIDGETPFD_CPP
#define WIDGETPFD_CPP
#endif

#include "widgetpfd.h"
#include "ui_WidgetPFD.h"

WidgetPFD::WidgetPFD( QWidget *parent ) :
    QWidget( parent ),
    m_ui( new Ui::WidgetPFD ),
    m_pfd ( 0 )
{
    m_ui->setupUi( this );
    m_pfd = m_ui->graphicsPFD;
}

WidgetPFD::~WidgetPFD()
{
    if ( m_ui ) delete m_ui; m_ui = 0;
}
