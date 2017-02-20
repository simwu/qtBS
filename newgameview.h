#ifndef NEWGAMEVIEW_H
#define NEWGAMEVIEW_H

#include"constants.h"
#include"messageview.h"

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

class NewGameView : public QDialog
{
    Q_OBJECT

    public:
        explicit NewGameView(QWidget *parent = 0);
        ~NewGameView();

        QString* getPlayerNames();
        int getNumberOfPlayers();

    private slots:

        void onNGVStartButtonClicked();
        void onNGVCancelButtonClicked();

    private:
        QLineEdit **playerNamesQLineEdits;
        MessageView *messageView;
        QString *playerNames;
        int numberOfPlayers;
};

#endif // NEWGAMEVIEW_H
