#ifndef SLIDEINGGAMEMAINWINDOW_H
#define SLIDEINGGAMEMAINWINDOW_H

#include <QMainWindow>
#include "tuple.h"
#include "coardinatedpushbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SlideingGameMainWindow; }
QT_END_NAMESPACE

class SlideingGameMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SlideingGameMainWindow(QWidget *parent = nullptr);
    ~SlideingGameMainWindow();

private slots:
    void slide();
    void on_newGame_pushButton_clicked();

private:
    Ui::SlideingGameMainWindow *ui;
    tuple<unsigned int, unsigned int> holeCoardinates;
    std::vector<coardinatedPushButton*> buttons;

    void shuffle();
    void manageUi() const;
    bool isPuzzleCompleated() const;
    void showCompleatedMessage();
};
#endif // SLIDEINGGAMEMAINWINDOW_H
