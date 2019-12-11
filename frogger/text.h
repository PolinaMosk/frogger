#ifndef TEXT_H
#define TEXT_H


#include <QGraphicsTextItem>

class Text : public QGraphicsTextItem
{
public:
  Text(QGraphicsTextItem* parent = nullptr);
  void changeAndShow();
  int level;
};


#endif // TEXT_H
