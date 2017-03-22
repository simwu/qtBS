#include "messageview.h"

MessageView::MessageView(QWidget *parent)
{

    // Need to give it a size in order to be able to center it in View onNewGameButtonClicked slot
    setFixedSize(MESSAGE_VIEW_WIDTH, MESSAGE_VIEW_HEIGHT);

    // Central Widget

    QGroupBox *centralWidget                    = new QGroupBox();
    QVBoxLayout *centralWidgetLayout            = new QVBoxLayout();
    centralWidget->setLayout (centralWidgetLayout);
    setLayout(centralWidgetLayout);

    // Header Label

    messageLabel                                = new QLabel();
    messageLabel->setObjectName("header-label");
    messageLabel->setWordWrap(true);
    centralWidgetLayout->addWidget(messageLabel);

    // Buttons

    QGroupBox *messageButtonsGroupBox           = new QGroupBox();
    messageButtonsGroupBox->setMinimumHeight(MESSAGE_BUTTON_GROUP_HEIGHT);
    messageButtonsGroupBox->setMaximumHeight(MESSAGE_BUTTON_GROUP_HEIGHT);
    QHBoxLayout *messageButtonsGroupBoxLayout   = new QHBoxLayout();
    messageButtonsGroupBox->setLayout(messageButtonsGroupBoxLayout);
    centralWidgetLayout->addWidget (messageButtonsGroupBox);

    QPushButton *messageOKButton                = new QPushButton("OK");
    messageOKButton->setMinimumWidth(MESSAGE_BUTTON_WIDTH);
    messageOKButton->setMinimumHeight(MESSAGE_BUTTON_HEIGHT);
    messageOKButton->setEnabled(true);
    connect(messageOKButton, SIGNAL(clicked()), this, SLOT(onOKButtonClicked()));
    messageButtonsGroupBoxLayout->addWidget(messageOKButton);
}

void MessageView::setMessage (QString message)
{
    messageLabel->setText(message);
}

void MessageView::onOKButtonClicked()
{
    hide();
}
