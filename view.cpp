#include "view.h"

View::View(Controller &ctrl, QWidget *parent) : controller(ctrl), QMainWindow(parent)
{   
    // Central Widget - Content Pane
    // 'new' label has to have pointer to the left
    // GroupBox - Panel (and the panel have panel-layouts that can be added onto)

    QGroupBox *centralWidget            = new QGroupBox();
    // Vertical Box Centers addtions
    centralWidgetLayout    = new QVBoxLayout();
    centralWidget->setLayout (centralWidgetLayout);
    setCentralWidget(centralWidget);
	
	setWindowTitle(QString::fromStdString(controller.VERSION));

    // Header Labels

    QGroupBox *labelsGroupHBox              = new QGroupBox();
    // Horizontal Box Left Justifies addtions
    QHBoxLayout *labelsGroupHBoxLayout      = new QHBoxLayout();
    labelsGroupHBox->setMaximumHeight(LABELS_HGROUP_HEIGHT);
    labelsGroupHBox->setLayout(labelsGroupHBoxLayout);
    // Add the additions into the central
    centralWidgetLayout->addWidget (labelsGroupHBox);

    playerNameLabel                         = new QLabel();
    playerNameLabel->setObjectName("header-label");
	playerNameLabel->setMinimumWidth(190);
	playerNameLabel->setMaximumWidth(190);
    labelsGroupHBoxLayout->addWidget(playerNameLabel);
    labelsGroupHBoxLayout->addSpacing(190);

    QLabel *discardDeckLabel                = new QLabel("Discard Deck");
    discardDeckLabel->setObjectName("header-label");
    labelsGroupHBoxLayout->addWidget(discardDeckLabel);
    labelsGroupHBoxLayout->addSpacing(390);

    QLabel *playCardLabel                   = new QLabel("Play Card");
    playCardLabel->setObjectName("header-label");
    labelsGroupHBoxLayout->addWidget(playCardLabel);
    labelsGroupHBoxLayout->addSpacing(390);

    QLabel *playerDiscardDeckLabel          = new QLabel("Player Discard Deck");
    playerDiscardDeckLabel->setObjectName("header-label");
    labelsGroupHBoxLayout->addWidget(playerDiscardDeckLabel);
    labelsGroupHBoxLayout->addStretch(1);

    // Discard Deck and Play Labels

    QGroupBox *discardDeckGroupHBox         = new QGroupBox();
    QHBoxLayout *discardDeckGroupHBoxLayout = new QHBoxLayout();
    discardDeckGroupHBox->setMinimumHeight(DISCARD_DECK_HGROUP_HEIGHT);
    discardDeckGroupHBox->setMaximumHeight(DISCARD_DECK_HGROUP_HEIGHT);
    discardDeckGroupHBox->setLayout(discardDeckGroupHBoxLayout);
    centralWidgetLayout->addWidget(discardDeckGroupHBox);

    // Discard Deck Image
    /*
    cardImageReader                         = new QImageReader(":/resources/images/starback.png");
    cardImageReader->setAutoTransform(true);
    // Image not pointer because not creating image, the image is recieved from the ImageReader
    cardImage = cardImageReader->read();
    // Converting the image into pixmap to communicate
    cardPixmapImage                         = QPixmap::fromImage(cardImage);
    cardImageLabel                          = new QLabel();
    // Titling for CSS
    cardImageLabel->setObjectName("card-image-label");
    // cardImageLabel->setPixmap(cardPixmapImage);
    cardImageLabel->setMaximumWidth(100);
    discardDeckGroupHBoxLayout->addWidget(cardImageLabel);
    */
    QLabel *cardImageLabel = new QLabel();
    cardImageLabel->setObjectName("card-image-label");
    cardImageLabel->setMaximumWidth(CARD_IMAGE_LABEL_WIDTH);
    discardDeckGroupHBoxLayout->addWidget(cardImageLabel);
    // Play Image
    /*
    cardImageReader                         = new QImageReader(":/resources/images/AH.png");
    cardImageReader->setAutoTransform(true);
    cardImage = cardImageReader->read();
    cardPixmapImage                         = QPixmap::fromImage(cardImage);
    cardImageLabel                          = new QLabel();
    cardImageLabel->setObjectName("play-card-image-label");
    // cardImageLabel->setPixmap(cardPixmapImage);
    cardImageLabel->setMaximumWidth(100);
    discardDeckGroupHBoxLayout->addWidget(cardImageLabel);
    */

    playCardImageLabel = new QLabel();
    playCardImageLabel->setObjectName("play-card-image-label");
    playCardImageLabel->setMaximumWidth(CARD_IMAGE_LABEL_WIDTH);
    discardDeckGroupHBoxLayout->addWidget(playCardImageLabel);
    
	// Player Discard Deck Image
    /*
    cardImageReader                         = new QImageReader(":/resources/images/starback.png");
    cardImageReader->setAutoTransform(true);
    cardImage                               = cardImageReader->read();
    cardPixmapImage                         = QPixmap::fromImage(cardImage);
    cardImageLabel                          = new QLabel();
    cardImageLabel->setObjectName("card-image-label");
    // cardImageLabel->setPixmap(cardPixmapImage);
    cardImageLabel->setMaximumWidth(100);
    discardDeckGroupHBoxLayout->addWidget(cardImageLabel);
    */

    cardImageLabel = new QLabel();
    cardImageLabel->setObjectName("card-image-label");
    cardImageLabel->setMaximumWidth(CARD_IMAGE_LABEL_WIDTH);
    discardDeckGroupHBoxLayout->addWidget(cardImageLabel);

	// Card Count

	QGroupBox *countLabelsGroupHBox              = new QGroupBox();
    QHBoxLayout *countLabelsGroupHBoxLayout      = new QHBoxLayout();
	countLabelsGroupHBox->setMaximumHeight(LABELS_HGROUP_HEIGHT);
	countLabelsGroupHBox->setLayout(countLabelsGroupHBoxLayout);
	centralWidgetLayout->addWidget(countLabelsGroupHBox);
	countLabelsGroupHBoxLayout->addSpacing(440);

	discardCountLabel						     = new QLabel("0");
    discardCountLabel->setObjectName("header-label");
    countLabelsGroupHBoxLayout->addWidget(discardCountLabel);
	countLabelsGroupHBoxLayout->addSpacing(410);

	bullshitPhaseLabel = new QLabel("Play Phase");
	bullshitPhaseLabel->setObjectName("header-label");
	bullshitPhaseLabel->setMinimumWidth(155);
	bullshitPhaseLabel->setMaximumWidth(155);
	bullshitPhaseLabel->setAlignment(Qt::AlignCenter);
	countLabelsGroupHBoxLayout->addWidget(bullshitPhaseLabel);
	countLabelsGroupHBoxLayout->addSpacing(410);

    playerDiscardCountLabel					     = new QLabel("0");
	playerDiscardCountLabel->setObjectName("header-label");
	countLabelsGroupHBoxLayout->addWidget(playerDiscardCountLabel);

	countLabelsGroupHBoxLayout->addStretch();

    //Current Player's Hand

    playerHandGroupBox						= new QGroupBox();
    playerHandGroupBox->setMinimumHeight(PLAYER_HAND_HGROUP_HEIGHT + 50);
    playerHandGroupBox->setMaximumHeight(PLAYER_HAND_HGROUP_HEIGHT + 50);
    playerHandGroupHBoxLayout				= new QHBoxLayout();
    playerHandGroupBox->setLayout(playerHandGroupHBoxLayout);

	playerHandScrollArea = new QScrollArea();

	
    centralWidgetLayout->addStretch();

	cardImages = new QIcon**[SUITS];

	for (int row = 0; row < SUITS; row++)
	{
		cardImages[row] = new QIcon*[CARDS];
	}

	for (int row = 0; row < SUITS; row++)
	{
		for (int col = 0; col < CARDS; col++)
		{
			// Retrieve the Card Image
			QString cardImageName = getCardImageName(row + 1, col + 1);
			QImageReader *imageReader = new QImageReader(cardImageName);
			imageReader->setAutoTransform(true);
			QImage cardImage = imageReader->read();
			QPixmap pixmapImage = QPixmap::fromImage(cardImage);
			QIcon *icon = new QIcon(pixmapImage);
			cardImages[row][col] = icon;
		}
	}

    // Buttons

    buttonsGroupBox							= new QGroupBox();
    buttonsGroupBox->setMinimumHeight(BUTTONS_GROUPBOX_HEIGHT);
    buttonsGroupBox->setMaximumHeight(BUTTONS_GROUPBOX_HEIGHT);
    buttonsGroupHBoxLayout					= new QHBoxLayout();
    buttonsGroupBox->setLayout(buttonsGroupHBoxLayout);
	centralWidgetLayout->addWidget(buttonsGroupBox);

    QPushButton *newGameButton              = new QPushButton("New Game");
    newGameButton->setMinimumWidth(VIEW_BUTTONS_WIDTH);
    newGameButton->setMinimumHeight(VIEW_BUTTONS_HEIGHT);
    newGameButton->setEnabled(true);
	// Add mouse event handler
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(onNewGameButtonClicked()));
    newGameButton->setObjectName("button-label");
    buttonsGroupHBoxLayout->addWidget(newGameButton);

    endTurnButton							= new QPushButton("End Turn");
    endTurnButton->setMinimumWidth(VIEW_BUTTONS_WIDTH);
    endTurnButton->setMinimumHeight(VIEW_BUTTONS_HEIGHT);
    endTurnButton->setEnabled(false);
    endTurnButton->setObjectName("button-label");
    buttonsGroupHBoxLayout->addWidget(endTurnButton);

	connect(endTurnButton, SIGNAL(clicked()), this, SLOT(onEndTurnButtonClicked()));

    bullshitButton				           = new QPushButton("Bullshit!");
    bullshitButton->setMinimumWidth(VIEW_BUTTONS_WIDTH);
    bullshitButton->setMinimumHeight(VIEW_BUTTONS_HEIGHT);
    bullshitButton->setEnabled(false);
    bullshitButton->setObjectName("button-label");
    buttonsGroupHBoxLayout->addWidget(bullshitButton);

	connect(bullshitButton, SIGNAL(clicked()), this, SLOT(onBullshitButtonClicked()));


	passButton						        = new QPushButton("Pass");
    passButton->setMinimumWidth(VIEW_BUTTONS_WIDTH);
    passButton->setMinimumHeight(VIEW_BUTTONS_HEIGHT);
    passButton->setEnabled(false);
    passButton->setObjectName("button-label");
    buttonsGroupHBoxLayout->addWidget(passButton);

	connect(passButton, SIGNAL(clicked()), this, SLOT(onPassButtonClicked()));

    // New Game View

    newGameView = new NewGameView();

    // Message View

    messageView = new MessageView();
}

View::~View()
{

}

void View::onNewGameButtonClicked()
{
    QRect screenGeometry    = QApplication::desktop()->screenGeometry();
    int x                   = (screenGeometry.width() - NEW_GAME_VIEW_WIDTH) / 2;
    int y                   = (screenGeometry.height() - NEW_GAME_VIEW_HEIGHT) / 2;
    newGameView->move(x, y);
    newGameView->exec();

    numberOfPlayers = newGameView->getNumberOfPlayers();

    if (numberOfPlayers >= MIN_PLAYERS)
    {
        names = new string[MAX_PLAYERS];
        playerNames = newGameView->getPlayerNames();

        for (int index = 0; index < numberOfPlayers; index++)
        {
            names[index] = playerNames[index].toStdString();
        }

		endTurnButton->setEnabled(false);

        newGame();
    }
}



void View::onCardButtonClicked()
{
	if (!controller.isBullshitInProgress())
	{
		QString buttonName = sender()->objectName();
		controller.play(getCardNumber(buttonName));

		// Update the Player Discard Number
		playerDiscardCountLabel->setText(QString::fromStdString(to_string(controller.getPlayerDiscardNumber())));

		/// Rebuild the Player's Hand
		play(controller.getCurrentPlayer());

		// Enable the End Turn Button
		endTurnButton->setEnabled(true);
	}
}

void View::onPassButtonClicked()
{
	controller.pass();

	if (controller.isBullshitInProgress())
	{
		playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(controller.getCurrentChallenger())));

		play(controller.getCurrentChallenger());
	}
	else if (controller.gameIsInProgress())
	{
		bullshitButton->setEnabled(false);
		passButton->setEnabled(false);
		endTurnButton->setEnabled(false);

		int cardNumber = controller.getCurrentCardNumber();
		QPixmap pixmap = (*cardImages[HEARTS - 1][cardNumber - 1]).pixmap(QSize(CARD_IMAGE_LABEL_WIDTH, PLAYER_HAND_HGROUP_HEIGHT));
		playCardImageLabel->setPixmap(pixmap);

		bullshitPhaseLabel->setText("Play Phase");

		discardCountLabel->setText(QString::fromStdString(to_string(controller.getDiscardNumber())));
		playerDiscardCountLabel->setText(QString::fromStdString(to_string(controller.getPlayerDiscardNumber())));

		playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(controller.getCurrentPlayer())));

		play(controller.getCurrentPlayer());
	}
	else
	{
		playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(controller.getCurrentPlayer())));

		bullshitPhaseLabel->setText("Game over");

		// Remove the challenger's player hand.  MUST NULLIFY THESE POINTERS TO PREVENT PLAY() FROM DELETING THEM AGAIN!
		// DELETE WILL DO NOTHING IF THE POINTER IS NULL! BUT IT WILL TRY TO DELETE THE OBJECT AGAIN IF THE POINTER CONTAINS THE OLD OBJECT'S ADDRESS, CAUSING A CRASH
		delete playerHandGroupHBoxLayout;
		delete playerHandGroupBox;
		delete playerHandScrollArea;

		playerHandGroupHBoxLayout = nullptr;
		playerHandGroupBox = nullptr;
		playerHandScrollArea = nullptr;

		bullshitButton->setEnabled(false);
		passButton->setEnabled(false);
	}
}

void View::onEndTurnButtonClicked()
{

	bullshitPhaseLabel->setText("Challenge Phase");

	controller.beginChallengePhase();

	playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(controller.getCurrentChallenger())));

	play(controller.getCurrentChallenger());

	bullshitButton->setEnabled(true);
	passButton->setEnabled(true);
	endTurnButton->setEnabled(false);
}

void View::onBullshitButtonClicked()
{
	controller.bullshit();

	if (controller.gameIsInProgress())
	{
		bullshitButton->setEnabled(false);
		passButton->setEnabled(false);
		endTurnButton->setEnabled(false);

		int cardNumber = controller.getCurrentCardNumber();
		QPixmap pixmap = (*cardImages[HEARTS - 1][cardNumber - 1]).pixmap(QSize(CARD_IMAGE_LABEL_WIDTH, PLAYER_HAND_HGROUP_HEIGHT));
		playCardImageLabel->setPixmap(pixmap);

		bullshitPhaseLabel->setText("Play Phase");

		discardCountLabel->setText(QString::fromStdString(to_string(controller.getDiscardNumber())));
		playerDiscardCountLabel->setText(QString::fromStdString(to_string(controller.getPlayerDiscardNumber())));

		playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(controller.getCurrentPlayer())));

		play(controller.getCurrentPlayer());
	}
	else
	{
		playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(controller.getCurrentPlayer())));
		
		bullshitPhaseLabel->setText("Game over");

		// Remove the challenger's player hand.  MUST NULLIFY THESE POINTERS TO PREVENT PLAY() FROM DELETING THEM AGAIN!
		// DELETE WILL DO NOTHING IF THE POINTER IS NULL! BUT IT WILL TRY TO DELETE THE OBJECT AGAIN IF THE POINTER CONTAINS THE OLD OBJECT'S ADDRESS, CAUSING A CRASH
		delete playerHandGroupHBoxLayout;
		delete playerHandGroupBox;
		delete playerHandScrollArea;

		playerHandGroupHBoxLayout	= nullptr;
		playerHandGroupBox			= nullptr;
		playerHandScrollArea		= nullptr;

		bullshitButton->setEnabled(false);
		passButton->setEnabled(false);
	}
}

void View::newGame()
{
    // Tell the controller to setup a new game
    controller.newGame(names, numberOfPlayers);

	bullshitPhaseLabel->setText("Play Phase");
	discardCountLabel->setText("0");
	playerDiscardCountLabel->setText("0");

    // Begin game play
	play(controller.getCurrentPlayer());
}


void View::play(int currentPlayer)
{
	// MUST DELETE THE OLD LAYOUT OBJECTS OTHERWISE THEY WILL BE REDRAWN
	delete playerHandGroupHBoxLayout;
	delete playerHandGroupBox;
	delete playerHandScrollArea;

	playerHandGroupBox = new QGroupBox();
	playerHandGroupBox->setMinimumHeight(PLAYER_HAND_HGROUP_HEIGHT + 50);
	playerHandGroupBox->setMaximumHeight(PLAYER_HAND_HGROUP_HEIGHT + 50);
	playerHandGroupHBoxLayout = new QHBoxLayout();
	playerHandGroupBox->setLayout(playerHandGroupHBoxLayout);

	centralWidgetLayout->removeWidget(playerHandScrollArea);

 	playerHandScrollArea = new QScrollArea();
	playerHandScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Tell the current Player to play
	playerNameLabel->setText(QString::fromStdString(controller.getPlayerName(currentPlayer)));

	// Get the current Player's hand
	list<Card*> *playerHand = controller.getPlayersHand(currentPlayer);

	int cardNumber = 0;

	for (Card *card : *playerHand)
	{
		QPushButton *button = new QPushButton();
		button->setObjectName(getObjectName(cardNumber + 1));
		button->setMinimumWidth(CARD_IMAGE_LABEL_WIDTH);
		button->setMaximumWidth(CARD_IMAGE_LABEL_WIDTH);
		button->setMinimumHeight(PLAYER_HAND_HGROUP_HEIGHT);
		button->setMaximumHeight(PLAYER_HAND_HGROUP_HEIGHT);

		button->setIcon(*cardImages[card->getSuitNumber() - 1][card->getCardNumber() - 1]);

		// Icon needs size to give the button its size
		button->setIconSize(QSize(CARD_IMAGE_LABEL_WIDTH - 3, PLAYER_HAND_HGROUP_HEIGHT - 3));

		// Add mouse event handler
		connect(button, SIGNAL(clicked()), this, SLOT(onCardButtonClicked()));

		playerHandGroupHBoxLayout->addWidget(button);

		cardNumber++;

		centralWidgetLayout->addStretch();
	}

	playerHandScrollArea->setWidget(playerHandGroupBox);

	centralWidgetLayout->removeWidget(buttonsGroupBox);
	centralWidgetLayout->addWidget(playerHandScrollArea);
	centralWidgetLayout->addWidget(buttonsGroupBox);

	if (playerHand->size() == 0)
	{
		endTurnButton->animateClick();

		endTurnButton->setEnabled(false);
	}
}


void View::displayMessage(QString message)
{
    if (message.length() > 0 )
    {
        messageView->setMessage(message);

        QRect screenGeometry    = QApplication::desktop()->screenGeometry();
        int x                   = (screenGeometry.width() - MESSAGE_VIEW_WIDTH) / 2;
        int y                   = (screenGeometry.height() - MESSAGE_VIEW_HEIGHT) / 2;
        messageView->move(x, y);
        messageView->exec();
    }
}

QString View::getCardImageName(int suitNumber, int cardNumber)
{
	string imageName = "";
	string suitName = "";
	string cardName = "";

	switch (suitNumber)
	{
		case SPADES:
		{
			suitName = "S";
			break;
		}
		case CLUBS:
		{
			suitName = "C";
			break;
		}
		case HEARTS:
		{
			suitName = "H";
			break;
		}
		case DIAMONDS:
		{
			suitName = "D";
			break;
		}
	}

	switch (cardNumber)
	{
		case ACE:
		{
			cardName = "A";
			break;
		}
		case JACK:
		{
			cardName = "J";
			break;
		}
		case QUEEN:
		{
			cardName = "Q";
			break;
		}
		case KING:
		{
			cardName = "K";
			break;
		}
		default:
		{
			cardName = to_string(cardNumber);
			break;
		}
	}

	imageName = IMAGE_PATH + cardName + suitName + ".png";
	return QString::fromStdString(imageName);
}

QString	View::getObjectName(int cardNumber)
{
	// string name = to_string(cardNumber);
	// QString objectName = QString::fromStdString(name);
	// return QString::fromStdString(name);;
	return QString::fromStdString(to_string(cardNumber));
}

int View::getCardNumber(QString objectName)
{
	return objectName.toInt();
}