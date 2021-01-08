#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QWidget>
class User;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    QWidget *m_currentWidget;

private slots:
    void slotOpenAuthorization();
    void slotOpenRegistration();
    void slotOpenWorkWidget(User*);
};
#endif // MAINWIDGET_H
