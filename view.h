#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <iostream>;
using namespace std;

#include "controller.h"
#include "newgameview.h"
#include "messageview.h"
#include <QMainWindow>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QImageReader>
#include <QImage>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QSizePolicy>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

class View : public QMainWindow
{
    Q_OBJECT

    public:
        explicit View(Controller &ctrl, QWidget *parent = 0);
        ~View();

        void displayMessage(QString message);

    private slots:
        void onNewGameButtonClicked();
		void onCardButtonClicked();
		void onEndTurnButtonClicked();

		void onBullshitButtonClicked();

		void onPassButtonClicked();

    private:
        Controller &controller;
		QVBoxLayout *centralWidgetLayout;
		QGroupBox *playerHandGroupBox;
        QScrollArea *playerHandScrollArea;
		QHBoxLayout *playerHandGroupHBoxLayout;
		QPushButton *endTurnButton;
		QPushButton *bullshitButton;
		QPushButton *passButton;
		QLabel *discardCountLabel;
		QLabel *bullshitPhaseLabel;
		QLabel *playerDiscardCountLabel;
		QGroupBox *buttonsGroupBox;
		QHBoxLayout *buttonsGroupHBoxLayout;
        // QImageReader -> QImage-> QPixmap -> QLabel
        // QImageReader goes into hard drive to find image and puts it into memory
        QImageReader *cardImageReader;
        // QImage has the properties of the file, image manipulation: change size, width, scaling
        QImage cardImage;
        // QPixMap is like QImage, does printing, adds to a label - object here is being created
        QPixmap cardPixmapImage;
        QLabel *playCardImageLabel;
        QLabel *playerNameLabel;

        NewGameView *newGameView;
        MessageView *messageView;

        QString *playerNames;
        int numberOfPlayers;
        string *names;

		QIcon ***cardImages;

		QString getCardImageName(int suitNumber, int cardNumber);
		QString	getObjectName(int cardNumber);
		int getCardNumber(QString objectName);

        void newGame();
        void play(int currentPlayer);
};

#endif // VIEW_H
