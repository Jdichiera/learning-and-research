#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "database.h"
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    database(new Database)
{
    ui->setupUi(this);
    GotoPage(Page::LOGINSTUDENT);
    ui->labelStudentLoginBadpass->hide();
    ui->labelFacultyLoginBadpass->hide();
}

QString MainWindow::ExpandCourseType(QString _type)
{
    QString expandedString;
    if(_type.toUpper() == "O"){
        expandedString = "(O)nline";
    }
    else {
        expandedString = "(T)raditional";
    }
    return expandedString;
}

QString MainWindow::ExpandCourseStatus(QString _status)
{
    QString expandedString;
    QString status = _status.toUpper();
    if(status == "P"){
        expandedString = "(P)ass";
    }
    else if (status == "F"){
        expandedString = "(F)ail";
    }
    else if (status == "I"){
        expandedString = "(I)n Progress";
    }
    else if (status == "D"){
        expandedString = "(D)ropped";
    }
    return expandedString;
}

void MainWindow::GotoPage(Page page)
{
    ui->stackedWidget->setCurrentIndex(page);
}

void MainWindow::GUISetStudent()
{
    qInfo() << "GUI Set Student";
    ui->inputStudentId->setText(QString::number(student->getUserId()));
    ui->inputStudentFirstName->setText(student->getFirstName());
    ui->inputStudentLastName->setText(student->getLastName());
    ui->inputStudentEmail->setText(student->getEmail());
    ui->inputStudentGPA->setText(QString::number(student->getGpa()));
}

void MainWindow::GUISetCurrentRegistration()
{
    qInfo() << "GUI Set Registration";
    AcademicRecord academicRecord = student->getAcademicRecord();
    ui->tableCurrentRegistration->setRowCount(academicRecord.getCourseList().size());
    int column = 0;
    int row = 0;
    for(auto course : academicRecord.getCourseList()){
        if(course.getCourseStatus() == "i"){
            ui->tableCurrentRegistration->setItem(row,0,new QTableWidgetItem(course.getSemester()));
            ui->tableCurrentRegistration->setItem(row,1,new QTableWidgetItem(QString::number(course.getCourseId())));
            ui->tableCurrentRegistration->setItem(row,2,new QTableWidgetItem(course.getCourseName()));
            ui->tableCurrentRegistration->setItem(row,3,new QTableWidgetItem(ExpandCourseType(course.getCourseType())));
            ui->tableCurrentRegistration->setItem(row,4,new QTableWidgetItem(course.getRegistrationDate()));
            ui->tableCurrentRegistration->setItem(row,5,new QTableWidgetItem(QString::number(course.getCourseCredits())));
            ui->tableCurrentRegistration->setItem(row,6,new QTableWidgetItem(QString::number(course.getCourseGrade())));
            row++;
        }
    }
}

void MainWindow::GUISetOpenCoursesTab(std::vector<Course> _openCourses)
{
    int row = 0;
    // ID, name, desc, cred, type, sem
    ui->tableCourseHistory->setRowCount(_openCourses.size());
    for(auto course : _openCourses){
        qInfo() << course.getCourseId();
        ui->tableCourseHistory->setItem(row, 0, new QTableWidgetItem(QString::number(course.getCourseId())));
        ui->tableCourseHistory->setItem(row, 1, new QTableWidgetItem(course.getCourseName()));
        ui->tableCourseHistory->setItem(row, 2, new QTableWidgetItem(QString::number(course.getCourseCredits())));
        ui->tableCourseHistory->setItem(row, 3, new QTableWidgetItem(ExpandCourseType(course.getCourseType())));
        ui->tableCourseHistory->setItem(row, 4, new QTableWidgetItem(course.getSemester()));
        ui->tableCourseHistory->setItem(row, 5, new QTableWidgetItem(course.getCourseDescription()));
        row++;
    }
}

void MainWindow::GUISetRegistrationTab(std::vector<Course> _openCourses)
{
    // TODO : Only show courses that can be registered for - If the student is registerd already it should not show up
    // If the student is maxed out in classes no classes should show and a message is displayed
    // If the student is on academic probation no classes should show and a message is displayed
    qInfo() << "Set Registration Tab";
    int row = 0;
    // Semester, ID, Course, Type, Cred, Desc
    ui->tableRegister->setRowCount(_openCourses.size());
    for(auto course : _openCourses){
        ui->tableRegister->setItem(row, 0, new QTableWidgetItem(course.getSemester()));
        ui->tableRegister->setItem(row, 1, new QTableWidgetItem(QString::number(course.getCourseId())));
        ui->tableRegister->setItem(row, 2, new QTableWidgetItem(course.getCourseName()));
        ui->tableRegister->setItem(row, 3, new QTableWidgetItem(ExpandCourseType(course.getCourseType())));
        ui->tableRegister->setItem(row, 4, new QTableWidgetItem(QString::number(course.getCourseCredits())));
        ui->tableRegister->setItem(row, 5, new QTableWidgetItem(course.getCourseDescription()));
        // TODO : semester not showing
        row++;
    }
}

void MainWindow::GUISetCourseHistoryTab()
{
    // TODO : Split into current and previous history
    qInfo() << "Set History Tab";
    int row = 0;
    std::vector<Course> record = student->getAcademicRecord().getCourseList();
    ui->tableCourseHistory->setRowCount(record.size());

    for(auto course : student->getAcademicRecord().getCourseList()){
        ui->tableCourseHistory->setItem(row, 0, new QTableWidgetItem(course.getSemester()));
        ui->tableCourseHistory->setItem(row, 1, new QTableWidgetItem(QString::number(course.getCourseId())));
        ui->tableCourseHistory->setItem(row, 2, new QTableWidgetItem(course.getCourseName()));
        // TODO : Prettify type
        ui->tableCourseHistory->setItem(row, 3, new QTableWidgetItem(ExpandCourseType(course.getCourseType())));
        // TODO : Prettify status
        ui->tableCourseHistory->setItem(row, 4, new QTableWidgetItem(ExpandCourseStatus(course.getCourseStatus())));
        ui->tableCourseHistory->setItem(row, 5, new QTableWidgetItem(course.getRegistrationDate()));
        // TODO : Detect in progress andalter completion date
        ui->tableCourseHistory->setItem(row, 6, new QTableWidgetItem(course.getCompletionDate()));
        ui->tableCourseHistory->setItem(row, 7, new QTableWidgetItem(QString::number(course.getCourseCredits())));
        ui->tableCourseHistory->setItem(row, 8, new QTableWidgetItem(QString::number(course.getCourseGrade())));
        row++;
    }
}

std::vector<Course> MainWindow::GetOpenCourses()
{
    std::vector<Course> openCourses;
    qInfo() << "Get open courses";
    QSqlQuery courseQuery;
    QSqlQuery semesterQuery;
    QString courseQueryString = QString("SELECT id, name, description, credits, type, semester FROM college.course WHERE active = 1");
    QString semesterQueryString = "";

    int courseId = 0;
    QString courseName = "";
    QString courseDescription = "";
    int courseCredits = 0;
    QString courseType = "";
    int semesterId = 0;
    QString courseSemester = "";
    Course tempCourse(courseId,"0","0",courseName,"0", courseDescription,courseCredits, courseType, 0.00, courseSemester);

    database->OpenConnection();
    courseQuery.exec(courseQueryString);
    courseQuery.first();
    while(courseQuery.next()){
        tempCourse.setCourseId(courseQuery.value(0).toInt());
        tempCourse.setCourseName(courseQuery.value(1).toString());
        tempCourse.setCourseDescription(courseQuery.value(2).toString());
        tempCourse.setCourseCredits(courseQuery.value(3).toInt());
        tempCourse.setCourseType(courseQuery.value(4).toString());
        semesterId  = courseQuery.value(5).toInt();
        semesterQueryString = QString("Select name FROM college.semester WHERE id = %1").arg(semesterId);
        semesterQuery.exec(semesterQueryString);
        semesterQuery.first();
        tempCourse.setSemester(semesterQuery.value(0).toString());
        openCourses.push_back(tempCourse);
    }
    database->CloseConnection();
    return openCourses;
}

bool MainWindow::AttemptLogin(QString _username, QString _password)
{
    bool credentialsValid = false;
    if(database->CheckCredentials(_username, _password)){
         credentialsValid = true;
    }
    return credentialsValid;
}

void MainWindow::GetStudentObject(QString _username)
{
    QString queryString = "SELECT * FROM college.user WHERE username = '" + _username + "'";
    QSqlQuery query;
    if(query.exec(queryString)){
        query.first();
        int id = query.value(0).toInt();
        QString userName = query.value(1).toString();
        QString firstName = query.value(3).toString();
        QString lastName = query.value(4).toString();
        QString email = query.value(5).toString();
        double gpa = query.value(6).toDouble();
        AcademicRecord academicRecord = GetAcademicRecord(id);
        student->setUserId(id);
        student->setUsername(userName);
        student->setFirstName(firstName);
        student->setLastName(lastName);
        student->setEmail(email);
        for(auto course : academicRecord.getCourseList()){
            student->AddCourse(course);
        }
        student->CalculateCourseLoad();
        student->CalculateGpa();
        GUISetStudent();
        GUISetCurrentRegistration();
    }
    else {
        qInfo() << query.lastError();
    }

}

AcademicRecord MainWindow::GetAcademicRecord(int _studentId)
{
    AcademicRecord academicRecord;
    int courseId = 0;
    QString registrationDate = "";
    QString completionDate= "";
    QString courseName = "";
    QString courseStatus = "";
    QString courseDescription = "";
    int courseCredits = 1;
    QString courseType = "";
    double courseGrade = 1.00;
    int semesterId = 0;
    QString courseSemester = "";
    Course tempCourse(courseId, registrationDate, completionDate, courseName,
                      courseStatus, courseDescription, courseCredits, courseType,
                      courseGrade, courseSemester);
    QSqlQuery recordQuery;
    QSqlQuery courseQuery;
    QSqlQuery semesterQuery;
    QString recordQueryString = QString("SELECT courseid, status, grade, registration, completion from college.registration WHERE studentid = %1").arg(_studentId);
    recordQuery.exec(recordQueryString);
    recordQuery.lastError();
    recordQuery.first();
    while(recordQuery.next()){
        courseId = recordQuery.value(0).toInt();
        courseStatus = recordQuery.value(1).toString();
        courseGrade = recordQuery.value(2).toDouble();
        registrationDate = recordQuery.value(3).toString();
        completionDate = recordQuery.value(4).toString();
        // Get course info
        QString courseQueryString = QString("SELECT name, description, credits, type, semester from college.course WHERE id = %1").arg(courseId);
        courseQuery.exec(courseQueryString);
        courseQuery.first();
        courseName = courseQuery.value(0).toString();
        courseDescription = courseQuery.value(1).toString();
        courseCredits = courseQuery.value(2).toInt();
        courseType = courseQuery.value(3).toString();
        semesterId = courseQuery.value(4).toInt();
        // Get semester name
        QString semesterQueryString = QString("SELECT name from college.semester WHERE id = %1").arg(semesterId);
        semesterQuery.exec(semesterQueryString);
        semesterQuery.first();
        courseSemester = semesterQuery.value(0).toString();
        tempCourse.setCourseId(courseId);
        tempCourse.setCourseStatus(courseStatus);
        tempCourse.setCourseGrade(courseGrade);
        tempCourse.setRegistrationDate(registrationDate);
        tempCourse.setCompletionDate(completionDate);
        tempCourse.setCourseName(courseName);
        tempCourse.setCourseDescription(courseDescription);
        tempCourse.setCourseCredits(courseCredits);
        tempCourse.setCourseType(courseType);
        tempCourse.setSemester(courseSemester);
        academicRecord.addClass(tempCourse);
    }
    return academicRecord;
}

void MainWindow::AddCourse()
{
    /*ACID transaction*/
//    QSqlDatabase::database().transaction();
//    QSqlQuery query;
//    query.exec("INSERT INTO college.course (name, description, credits, type, active, semester)"
//               "VALUES ('newCourse', 'desc', 3, 't', 1, 2)");
//    if(query.isActive()){
//        query.finish();
//    }
//    if(!QSqlDatabase::commit()){
//        QSqlDatabase::rollback();
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    if(student == NULL){
        student = new Student();
    }

    // Get the text from the username and password boxes
    QString username = ui->inputStudentLoginUsername->text();
    QString password = ui->inputStudentLoginPassword->text();

    // Clear the input boxes
    ui->inputStudentLoginUsername->clear();
    ui->inputStudentLoginPassword->clear();
    ui->labelStudentLoginBadpass->hide();

    database->OpenConnection();
    if(username == "root") {
        if(database->AdminLogin(username, password)){
            GotoPage(Page::SCREENDATABASE);
        }
    }
    else if(AttemptLogin(username, password)){
        // Check admin
        if(database->CheckAdmin(username)){
            // Get faculty info
            // Create faculty object
            // Goto faculty page
            database->CloseConnection();
            GotoPage(Page::SCREENFACULTY);
        }
        else {
            // get student info
            // Create student object
            // Goto student page
            GetStudentObject(username);
            database->CloseConnection();
            GotoPage(Page::SCREENSTUDENT);

        }
    }
    else {
        ui->labelStudentLoginBadpass->show();
        database->CloseConnection();
    }
}


// DB Login Page
void MainWindow::on_btnDbloginLogin_clicked()
{
    QString username = ui->inputDbloginUsername->text();
    QString password = ui->inputDbloginPassword->text();
    if(database->AdminLogin(username, password)){
        GotoPage(Page::SCREENDATABASE);
    }
    else {
        qInfo() << "Bad password";
    }
}
void MainWindow::on_btnDbloginBack_clicked()
{
    GotoPage(Page::LOGINSTUDENT);
}


// DB Admin Page
void MainWindow::on_btnDbAdminDropTable_clicked()
{
    ui->textDbAdminConsole->append("Drop tables");
    database->DropTables();
}

void MainWindow::on_btnDbAdminAddTables_clicked()
{
    ui->textDbAdminConsole->append("Add tables");
    database->CreateTables();
}

void MainWindow::on_btnDbAdminSeedTables_clicked()
{
    ui->textDbAdminConsole->append("Seed database");
    database->SeedDatabase();
}
void MainWindow::on_btnDbAdminLogout_clicked()
{
    GotoPage(Page::SCREENLOGOUT);
}

// Student Page
void MainWindow::on_btnUserLogout_clicked()
{
    student = NULL;
    GotoPage(Page::SCREENLOGOUT);
}

// Logout Page
void MainWindow::on_btnLogoutBacktologin_clicked()
{
    GotoPage(Page::LOGINSTUDENT);
}

void MainWindow::on_tabStudent_tabBarClicked(int index)
{
    if(index == 1){
        GUISetRegistrationTab(GetOpenCourses());
    }
    // Get list of classes
    if(index == 2){
        GUISetCourseHistoryTab();
    }
}

void MainWindow::on_btnLogOut_clicked()
{
    // TODO : Make logout function
    student = NULL;
    GotoPage(Page::SCREENLOGOUT);
}

void MainWindow::on_tableRegister_clicked(const QModelIndex &index)
{
    int row = index.row();
    QString semester = ui->tableRegister->item(row, 0)->text();
    int id = ui->tableRegister->item(row, 1)->text().toInt();
    QString name = ui->tableRegister->item(row, 2)->text();
    QString type = ui->tableRegister->item(row, 3)->text();
    int credits = ui->tableRegister->item(row, 4)->text().toInt();
    QString description = ui->tableRegister->item(row, 5)->text();
    Dialog dialog(this);
    dialog.SetName(name);
    dialog.SetCourseID(id);
    dialog.SetType(type);
    dialog.SetSemester(semester);
    dialog.SetCredits(credits);
    dialog.SetDescription(description);
    int result = dialog.exec();
}
