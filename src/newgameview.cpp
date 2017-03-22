#include "newgameview.h"

NewGameView::NewGameView(QWidget *parent)
{
    // Need to give it a size in order to be able to center it in View onNewGameButtonClicked slot
    setFixedSize(NEW_GAME_VIEW_HEIGHT, NEW_GAME_VIEW_WIDTH);

    // Central Widget

    QGroupBox *centralWidget                     = new QGroupBox();
    QVBoxLayout *centralWidgetLayout             = new QVBoxLayout();
    centralWidget->setLayout (centralWidgetLayout);
    setLayout(centralWidgetLayout);

    // Header Label

    QLabel *playersLabel                          = new QLabel("Players");
    playersLabel->setObjectName("header-label");
    centralWidgetLayout->addWidget(playersLabel);

    // Player Names

    QGroupBox *playerNamesGroupVBox               = new QGroupBox();
    QVBoxLayout *playerNamesGroupVBoxLayout       = new QVBoxLayout();
    playerNamesGroupVBox->setMaximumHeight(NEW_GAME_NAMES_VGROUP_HEIGHT);
    playerNamesGroupVBox->setLayout(playerNamesGroupVBoxLayout);
    centralWidgetLayout->addWidget (playerNamesGroupVBox);

    playerNamesQLineEdits                         = new QLineEdit*[MAX_PLAYERS];

    for (int index = 0; index < MAX_PLAYERS; index++)
    {
        QGroupBox *playerNamesGroupHBox           = new QGroupBox();
        QHBoxLayout *playerNamesGroupHBoxLayout   = new QHBoxLayout();
        playerNamesGroupHBox->setMaximumHeight(NEW_GAME_NAMES_HGROUP_HEIGHT);
        playerNamesGroupHBox->setLayout(playerNamesGroupHBoxLayout);
        playerNamesGroupVBoxLayout->addWidget(playerNamesGroupHBox);

        QLabel *playerNumberLabel                 = new QLabel(QString::number(index+1));
        playerNumberLabel->setObjectName("header-label");

        playerNamesQLineEdits[index]              = new QLineEdit();

        playerNamesGroupHBoxLayout->addWidget(playerNumberLabel);
        playerNamesGroupHBoxLayout->addWidget(playerNamesQLineEdits[index]);
    }

    // Buttons - ngv = New Game View

    QGroupBox *ngvButtonsGroupBox                 = new QGroupBox();
    ngvButtonsGroupBox->setMinimumHeight(NEW_GAME_BUTTONS_GROUP_HEIGHT);
    ngvButtonsGroupBox->setMaximumHeight(NEW_GAME_BUTTONS_GROUP_HEIGHT);
    QHBoxLayout *ngvButtonsGroupHBoxLayout        = new QHBoxLayout();
    ngvButtonsGroupBox->setLayout(ngvButtonsGroupHBoxLayout);
    centralWidgetLayout->addWidget (ngvButtonsGroupBox);

    QPushButton *ngvStartButton                   = new QPushButton("Start Game");
    ngvStartButton->setMinimumWidth(NEW_GAME_BUTTON_WIDTH);
    ngvStartButton->setMinimumHeight(NEW_GAME_BUTTON_HEIGHT);
    ngvStartButton->setEnabled(true);
    connect(ngvStartButton, SIGNAL(clicked()), this, SLOT(onNGVStartButtonClicked()));
    ngvButtonsGroupHBoxLayout->addWidget(ngvStartButton);

    QPushButton *ngvCancelButton                  = new QPushButton("Cancel");
    ngvCancelButton->setMinimumWidth(NEW_GAME_BUTTON_WIDTH);
    ngvCancelButton->setMinimumHeight(NEW_GAME_BUTTON_HEIGHT);
    ngvCancelButton->setEnabled(true);
    connect(ngvCancelButton, SIGNAL(clicked()), this, SLOT(onNGVCancelButtonClicked()));
    ngvButtonsGroupHBoxLayout->addWidget(ngvCancelButton);

    // Message View

    messageView = new MessageView();
}

NewGameView::~NewGameView()
{

}

void NewGameView::onNGVStartButtonClicked()
{
    playerNames         = new QString[MAX_PLAYERS];
    numberOfPlayers     = 0;
    int players         = 0;

    for (int index = 0; index < MAX_PLAYERS; index++)
    {
        if (playerNamesQLineEdits[index]->text().length() > 0)
        {
            playerNames[players] = playerNamesQLineEdits[index]->text();
            numberOfPlayers++;
            players++;
        }
    }
    if (numberOfPlayers < MIN_PLAYERS)
    {
        QString message = "Simon sayz 'Click OK, BIATCH' because there must be at least " + QString::number(MIN_PLAYERS) + " playas to play a game";
        messageView->setMessage(message);

        QRect screenGeometry    = QApplication::desktop()->screenGeometry();
        int x                   = (screenGeometry.width() - MESSAGE_VIEW_WIDTH) / 2;
        int y                   = (screenGeometry.height() - MESSAGE_VIEW_HEIGHT) / 2;
        messageView->move(x, y);
        messageView->exec();
    }
    else
    {
        hide();
    }
}

void NewGameView::onNGVCancelButtonClicked()
{
    hide();
}

QString* NewGameView::getPlayerNames()
{
    return playerNames;
}

int NewGameView::getNumberOfPlayers()
{
    return numberOfPlayers;
}
