#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QPainter>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include "Student.h"
#include "Group.h"
#include <QPainterPath>
#include "Section.h"
#include "Time.h"
#include "Session.h"
#include "Course.h"
#include "Place.h"
#include "Teacher.h"
#include "Year.h"
#include "Semestre.h"
#include <QMouseEvent>  // For mouse events, if you are using them
#include <QEvent>
#include "funcs.h"

// Helper function to clear layout contents
void remove(QLayout *layout) {
    QLayoutItem *child;
    while (layout->count() != 0) {
        child = layout->takeAt(0);
        if (child->layout() != 0) {
            remove(child->layout());
        } else if (child->widget() != 0) {
            delete child->widget();
        }
        delete child;
    }
}

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stackedWidget = ui->stackedWidget;
    stackedWidget->setCurrentIndex(0);
    createRoleSelectionPage();
    createLoginPage();


}

MainWindow::~MainWindow(){
    delete ui;
    CleanALL();
}
QWidget *MainWindow::createRoleSelectionPage() {
    QWidget *page = ui->page;
    QHBoxLayout *layout = ui->horizontalLayout;

    // Creating QFrame as clickable containers
     setClickableContainer(ui->Adminbtn,"Administrator");
    setClickableContainer(ui->teacherbtn,"Teacher");
     setClickableContainer(ui->studentbtn,"Student");

    return page;
}

QWidget *MainWindow::createLoginPage() {
    QWidget *page = ui->page_2;
    QVBoxLayout *layout = ui->Form;

    usernameEdit = ui->usernameinput;
    passwordEdit = ui->PasswordInput;
    ui->user->setBuddy(usernameEdit);
    ui->password->setBuddy(passwordEdit);
    QPushButton *loginButton = ui->Login;
    QPushButton *backButton = ui->Return;

    connect(loginButton, &QPushButton::clicked, this, &MainWindow::login);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goBack);


    return page;
}

void MainWindow::setClickableContainer(QFrame * f,const QString &role) {
    QFrame *frame = f;
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setStyleSheet("QFrame { background-color: #426137; \nborder-radius: 35%;\nmargin:7px;opacity: 0.6; }"
                         "QFrame:hover { background-color: #25361f; \nborder-radius: 35%;\nmargin:7px;opacity:1;}");

    QLabel *label = new QLabel(role, frame);
    label->setStyleSheet(QString("color:#ebebb0;"));
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    label->setFont(font);

    label->setAlignment(Qt::AlignCenter);
    QHBoxLayout *layout = new QHBoxLayout(frame);
    layout->addWidget(label);
    frame->setLayout(layout);

    frame->installEventFilter(this);

    // Using property to identify the role
    frame->setProperty("role", role);
    return ;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::MouseButtonRelease) {
        QFrame *frame = qobject_cast<QFrame *>(watched);
        if (frame) {
            QString role = frame->property("role").toString();
            handleRoleSelection(role);
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void MainWindow::handleRoleSelection(const QString &role) {
    userRole = role;
    qDebug() << "Role selected:" << userRole;
    stackedWidget->setCurrentIndex(1);  // Switch to the login page
}
void MainWindow::showError(const QString &message) {
    // Display the error message to the user
    // You can use a QMessageBox or any other method
    QMessageBox::critical(this, "Login Error", message);
}
void MainWindow::login() {
    qDebug() << "Logging in as:" << userRole;
    QString username=usernameEdit->text();
    std::string userN=username.toStdString();
    QString password=passwordEdit->text();
    std::string Passwd=password.toStdString();
    qDebug() << "Username:" << username;
    qDebug() << "Password:" << passwordEdit;
    if (userN.size() < 13 || userN.substr(userN.length() - 13) != "@ensia.edu.dz") {
        showError("Invalid username. Please use your university email.");
        return;
    }
    std::string baseUsername = RemoveSuffix(userN, "@ensia.edu.dz");
    if (userRole == "Student") {
        if (!FoundLine("StudentsUsers.txt", baseUsername)) {
            showError("New User?! Please Register first.");
            return;
        }

        if (verifyPassword("StudentsUsers.txt", baseUsername, Passwd)) {
            qDebug() << "Login successful!";
            ui->SideBareTrue_5->setHidden(true);
            stackedWidget->setCurrentIndex(2);
            ui->AppInterface->setCurrentIndex(0);
            Student S=GetObjectByAttribute<Student>("Students.txt",4,userN);

            ui->Age->setText(QString::fromStdString(std::to_string(S.getAge())));
            ui->Email->setText(QString::fromStdString(S.getEmail()));
            Group G=GetObject<Group>(S.getGroup());

            ui->Group->setText(QString::fromStdString(std::to_string(G.getGroupNumber())));
            Section Sec= GetObject<Section>(G.getSection());
            ui->Section->setText(QString::fromStdString(std::to_string(Sec.getSectionNumber())));
            Year Y=GetObject<Year>(Sec.getYear());
            ui->Year->setText(QString::fromStdString(std::to_string(Y.getYearNumber())));
            ui->SchoolID->setText(QString::fromStdString(std::to_string(S.getID())));
            ui->Phone->setText(QString::fromStdString(S.getPhoneN()));
            ui->Name->setText(QString::fromStdString(S.getFirstN()+" "+S.getFamilyN()));
            QPixmap profilePixmap;
            profilePixmap.load(QString::fromStdString(S.getPhoto()));

            QLabel* profileLabel=ui->ProfilePhoto;
            // Scale the pixmap to fit the QLabel
            profilePixmap = profilePixmap.scaled(profileLabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
            // Add a border and shadow effect
            profileLabel->setStyleSheet("QLabel { border: 0; border-radius: 50%; }");
            // profilePixmap.fill(Qt::transparent);

            // QPainter painter(&profilePixmap);
            // painter.setRenderHint(QPainter::Antialiasing);
            // QPainterPath path;
            // path.addEllipse(0, 0, profileLabel->width(), profileLabel->height());
            // painter.setClipPath(path);
            // painter.drawPixmap(0, 0, profilePixmap);
            // painter.end();
            profileLabel->setPixmap(profilePixmap.scaled(profileLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            Time currentT=getcurrentTime();
            Time nextT=currentT+1;
            Session NextS=S.getSession(&nextT);
            Course NextC=GetObject<Course>(NextS.getCourse());
            Place NextP=GetObject<Place>(NextS.getPlace());
            ui->nextSession->setText(QString::fromStdString(NextC.getName()+" in : "+NextP.getName()));
            for(auto  scourse :S.getCourses()){
                Course course =GetObject<Course>(scourse->getCourse());
                if (QString::fromStdString( course.getName())!= ui->CourseName->text()){
                    createCourseWindow(&course);
                }
            }

        } else {
            showError("Invalid username or password.");
        }
    } else if (userRole == "Teacher") {
        if (!FoundLine("TeachersUsers.txt", baseUsername)) {
            showError("New User?! Please Register first.");
            return;
        }

        if (verifyPassword("TeachersUsers.txt", baseUsername, Passwd)) {
            qDebug() << "Login successful!";
            stackedWidget->setCurrentIndex(3);
            ui->AppInterface->setCurrentIndex(1);
        } else {
            showError("Invalid username or password.");
        }
    } else if (userRole == "Administrator") {
        if (!FoundLine("AdministratorsUsers.txt", baseUsername)) {
            showError("New User?! Please Register first.");
            return;
        }

        if (verifyPassword("AdministratorsUsers.txt", baseUsername, Passwd)) {
            qDebug() << "Login successful!";
            stackedWidget->setCurrentIndex(3);
            ui->AppInterface->setCurrentIndex(2);



        } else {
            showError("Invalid username or password.");
        }
    } else {
        showError("Invalid Role.");
    }


}
void MainWindow::goBack() {
    usernameEdit->clear();
    passwordEdit->clear();
    stackedWidget->setCurrentIndex(0);  // Switch back to the role selection page
}



void MainWindow::on_GotoNotification_clicked()
{
    ui->MainW->setCurrentIndex(1);
}



void MainWindow::on_GoToHome_clicked()
{
    ui->MainW->setCurrentIndex(0);

}


void MainWindow::on_GoToMessages_clicked()
{
    ui->MainW->setCurrentIndex(2);

}


void MainWindow::on_GoToClassRoom_clicked()
{
    ui->MainW->setCurrentIndex(3);

}




void MainWindow::on_LogOut_clicked()
{
    goBack();
}


void MainWindow::on_Home_51_clicked()
{

}

void MainWindow::on_Home_54_clicked()
{

}
void MainWindow::createCourseWindow(Course * course){
    QWidget *NewCourse= new QWidget(ui->Course);
    QLayout* NewLayout =NewCourse->layout();
    for (int i = 0; i < 2; ++i) {
        QLayoutItem *item = NewLayout->itemAt(i);
        if (item->widget()) {
            QLabel *label = qobject_cast<QLabel*>(item->widget());
            if (label) {
                if (i==0)label->setText(QString::fromStdString(course->getName()));
                if (i==1)label->setText("You Have No Tasks TODAY!");                // Modify the QLabel text
            }
        }
    }
    QLayout *classroomLayout=ui->Classroom->layout();
    classroomLayout->addWidget(NewCourse);

}
