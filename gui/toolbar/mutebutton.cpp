#include "mutebutton.h"

MuteButton::MuteButton(QWidget *parent) : QToolButton(parent) {
    mainWindow = (MainWindow*)parent;
    clientSettings = ClientSettings::getInstance();

    setIconSize(QSize(32, 32));
    setObjectName("muted");
    setCursor(Qt::PointingHandCursor);

    setStyleSheet("QToolButton {"
                  " background: #242024;"
                  "}");

    this->muted = clientSettings->getParameter("Audio/muted", false).toBool();
    this->setMuted(this->muted);

    connect(this, SIGNAL(clicked()), this, SLOT(clicked()));

    connect(this, SIGNAL(volumeMuted(bool)), mainWindow, SLOT(menuVolumeMuted(bool)));
    connect(mainWindow, SIGNAL(volumeMuted(bool)), this, SLOT(setMuted(bool)));
}

void MuteButton::clicked() {        
    this->muted = !this->muted;
    clientSettings->setParameter("Audio/muted", this->muted);       
    emit volumeMuted(muted);
}

void MuteButton::setMuted(bool muted) {
    if(muted) {                        
        setIcon(QIcon(BUTTON_MUTE));
        setToolTip("Unmute sounds");
    } else {
        setIcon(QIcon(BUTTON_UNMUTE));
        setToolTip("Mute sounds");
    }
}
