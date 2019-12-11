#include "text.h"
#include <QFont>

Text::Text(QGraphicsTextItem* parent)
{
    level = 1;
    setPlainText(QString("Level: ") + QString::number(level));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 24));
}

void Text::changeAndShow()
{
    level++;
    if (level == 6)
    {
        setPlainText(QString("Game over!"));
    } else setPlainText(QString("Level: ") + QString::number(level));
}
