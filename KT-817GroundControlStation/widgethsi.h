#ifndef WIDGETHSI_H
#define WIDGETHSI_H

#include <QWidget>
#include <qfi_HSI.h>

namespace Ui
{
    class WidgetHSI;
}

class WidgetHSI : public QWidget
{
    Q_OBJECT

public:

    explicit WidgetHSI( QWidget *parent = 0 );

    ~WidgetHSI();

    inline void update()
    {
        m_hsi->update();
    }

    inline void setHeading( float heading )
    {
        m_hsi->setHeading( heading );
    }

private:

    Ui::WidgetHSI *m_ui;
    qfi_HSI       *m_hsi;
};

#endif // WIDGETHSI_H
