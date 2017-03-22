#ifndef MESSAGEVIEW_H
#define MESSAGEVIEW_H

#include "constants.h"

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>

class MessageView : public QDialog
{
    Q_OBJECT

    public:
        MessageView(QWidget *parent = 0);

        void setMessage (QString message);

    private slots:
        void onOKButtonClicked();

    private:
        QLabel  *messageLabel;
};

#endif // MESSAGEVIEW_H
