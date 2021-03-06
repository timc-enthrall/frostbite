#ifndef GRIDWINDOW_H
#define GRIDWINDOW_H

#include <QTableWidget>
#include <QDockWidget>
#include <QLabel>

#include <mainwindow.h>
#include <custom/contextmenu.h>

class GridWindow : public QTableWidget {
    Q_OBJECT

public:
    explicit GridWindow(QString title, QWidget *parent = 0);
    ~GridWindow();

    QColor getBgColor();
    QColor getTextColor();

    QLabel* gridValueLabel(QWidget* parent);

    void track(QString skillName, QWidget* widget);  

private:
    MainWindow* mainWindow;
    GeneralSettings* settings;
    WindowFacade* wm;

    QStringList tracked;
    QFont font;
    QColor textColor;
    QColor backgroundColor;

    QString windowId;

    void loadSettings();    
    void invertColors(QWidget* widget);
    void setItemColors(QWidget* widget, QColor text, QColor background);

    void contextMenuEvent(QContextMenuEvent* event);
    void buildContextMenu();

    void updateFont();

    QAction* appearanceAct;
    QAction* fontAct;
    QAction* clearFontAct;
    ContextMenu* menu;

signals:

public slots:
    void addRemoveTracked(int, int);
    void updateSettings();
    void track(QString skillName);
    void clearTracked();
    void resize(int, int);
    void changeAppearance();
    void selectFont();
    void clearFont();
};

#endif // EXPWINDOW_H
