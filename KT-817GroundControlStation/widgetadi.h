#ifndef WIDGETADI_H
#define WIDGETADI_H

#include <QWidget>
#include <qfi_ADI.h>

namespace Ui
{
    class WidgetADI;
}

class WidgetADI : public QWidget
{
    Q_OBJECT

public:

    explicit WidgetADI( QWidget *parent = 0 );

    ~WidgetADI();

    inline void update()
    {
        m_adi->update();
    }

    inline void setRoll( float roll )
    {
        m_adi->setRoll( roll );
    }

    inline void setPitch( float pitch )
    {
        m_adi->setPitch( pitch );
    }

private:

    Ui::WidgetADI *m_ui;
    qfi_ADI       *m_adi;
};

#endif // WIDGETADI_H
