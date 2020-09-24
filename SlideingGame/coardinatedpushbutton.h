#ifndef COARDINATEDPUSHBUTTON_H
#define COARDINATEDPUSHBUTTON_H

#include <QPushButton>

class coardinatedPushButton : public QPushButton
{
    Q_OBJECT

public:
    unsigned int x = 0;
    unsigned int y = 0;

    coardinatedPushButton(QWidget *parent = nullptr);
    ~coardinatedPushButton();
};
#endif // COARDINATEDPUSHBUTTON_H
