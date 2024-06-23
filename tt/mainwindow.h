#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QFrame>
#include "Course.h"
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void handleRoleSelection(const QString &role); // Updated to take a QString parameter
    void login();
    void goBack();
    void on_Home_51_clicked();

    void on_GotoNotification_clicked();

    void on_GoToHome_clicked();

    void on_GoToMessages_clicked();

    void on_GoToClassRoom_clicked();

    void on_Home_54_clicked();

    void on_LogOut_clicked();

private:
    void createCourseWindow(Course * course);
    QStackedWidget *stackedWidget;
    QWidget *createRoleSelectionPage();
    QWidget *createLoginPage();
    void setClickableContainer(QFrame * f,const QString &role);
    void showError(const QString &message);
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QString userRole;
};

#endif // MAINWINDOW_H
