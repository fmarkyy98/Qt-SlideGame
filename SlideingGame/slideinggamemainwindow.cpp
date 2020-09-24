#include <QTime>
#include <QMessageBox>
#include "slideinggamemainwindow.h"
#include "ui_slideinggamemainwindow.h"

//___________________________________________________________________________________________________________________________________________________
#define SLIDE_MACRO(OPERATOR1, OPERATOR2, OPERATOR3, OPERATOR4, SLIDE)                                                                               \
{                                                                                                                                                     \
    for(coardinatedPushButton* const item : buttons)                                                                                                   \
    {                                                                                                                                                   \
        if(originalX OPERATOR1 item->x && item->x OPERATOR2 holeCoardinates.fst && originalY OPERATOR3 item->y && item->y OPERATOR4 holeCoardinates.snd) \
        {                                                                                                                                                 \
            SLIDE;                                                                                                                                         \
        }                                                                                                                                                   \
    }                                                                                                                                                        \
    holeCoardinates.fst = originalX;                                                                                                                          \
    holeCoardinates.snd = originalY;                                                                                                                           \
}//_____________________________________________________________________________________________________________________________________________________________\

static const int bordSize = 4;

SlideingGameMainWindow::SlideingGameMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SlideingGameMainWindow)
{
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    holeCoardinates.fst = holeCoardinates.snd = 3;

    buttons.push_back(ui->coardinatedPushButton_1);
    buttons.push_back(ui->coardinatedPushButton_2);
    buttons.push_back(ui->coardinatedPushButton_3);
    buttons.push_back(ui->coardinatedPushButton_4);
    buttons.push_back(ui->coardinatedPushButton_5);
    buttons.push_back(ui->coardinatedPushButton_6);
    buttons.push_back(ui->coardinatedPushButton_7);
    buttons.push_back(ui->coardinatedPushButton_8);
    buttons.push_back(ui->coardinatedPushButton_9);
    buttons.push_back(ui->coardinatedPushButton_10);
    buttons.push_back(ui->coardinatedPushButton_11);
    buttons.push_back(ui->coardinatedPushButton_12);
    buttons.push_back(ui->coardinatedPushButton_13);
    buttons.push_back(ui->coardinatedPushButton_14);
    buttons.push_back(ui->coardinatedPushButton_15);

    for(unsigned int i = 0; i < buttons.size(); ++i)
    {
        buttons[i]->x = i % bordSize;
        buttons[i]->y = i / bordSize;
    }

    for(coardinatedPushButton* const item : buttons)
    {
        connect(item, SIGNAL(clicked()), this, SLOT(slide()));
    }

    shuffle();
}

SlideingGameMainWindow::~SlideingGameMainWindow()
{
    delete ui;
}

void SlideingGameMainWindow::manageUi() const
{
    for(coardinatedPushButton* const item : buttons)
    {
        item->setGeometry(item->x * 80 + 10, item->y * 80 + 40, 71, 71);
    }
}

void swapButtonCoardinat(coardinatedPushButton& a, coardinatedPushButton& b)
{
    int sx = a.x,  sy = a.y;
       a.x = b.x, a.y = b.y;
       b.x = sx,  b.y = sy;
}

void SlideingGameMainWindow::shuffle()
{
    for(coardinatedPushButton* const item : buttons)
    {
        swapButtonCoardinat(*item, *buttons[qrand() % buttons.size()]);
    }
    manageUi();
}

bool SlideingGameMainWindow::isPuzzleCompleated() const
{
    for(unsigned int i = 0; i < buttons.size(); ++i)
    {
        if(buttons[i]->x != i % bordSize || buttons[i]->y != i / bordSize)
        {
            return false;
        }
    }
    return true;
}

void SlideingGameMainWindow::showCompleatedMessage()
{
    QMessageBox msg;
    msg.setText("Nyertél!!!");
    msg.exec();
    shuffle();
}

void SlideingGameMainWindow::on_newGame_pushButton_clicked()
{
    shuffle();
}

void SlideingGameMainWindow::slide()
{
    coardinatedPushButton* cbtn = (coardinatedPushButton*)sender();
    const unsigned int originalX = cbtn->x;
    const unsigned int originalY = cbtn->y;
    if(originalX == holeCoardinates.fst && originalY < holeCoardinates.snd)
    {
        SLIDE_MACRO(==, ==, <=, <, ++item->y);
    }
    else if(originalX == holeCoardinates.fst && originalY > holeCoardinates.snd)
    {
        SLIDE_MACRO(==, ==, >=, >, --item->y);
    }
    else if(originalX < holeCoardinates.fst && originalY == holeCoardinates.snd)
    {
        SLIDE_MACRO(<=, <, ==, ==, ++item->x);
    }
    else if(originalX > holeCoardinates.fst && originalY == holeCoardinates.snd)
    {
        SLIDE_MACRO(>=, >, ==, ==, --item->x);
    }
    manageUi();
    if(isPuzzleCompleated())
    {
        showCompleatedMessage();
    }
}
