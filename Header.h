#pragma once
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;



class Admin
{
protected:
	string User_Name;
	string User_Name_File;
	string Password;
	string Password_File;

	string First_Name;
	string Last_Name;
	int departmentChoice;
	//string Student_Department_Name;

	string Teacher_Department_Name;
	int std_number;
	string Registration_Date;
	char genderChoice;
	string gender;
	string Gender_Choice;
	string Contact_Number;
	string Qualification;
	string Address;
	char feeStatus;
	string marks;
	int studentCount;
	int teacherCount;

	string Blood_Gorup;
	int teacher_ID;
	int student_ID;

	ifstream read_File;
	ofstream write_File;

	ifstream read_Student_Id;
	ofstream write_Student_Id;

	ifstream read_Teacher_Id;
	ofstream write_Teacher_Id;

	ifstream readView;


public:
	Admin();

	virtual void sign_In() {};
	virtual void addTeacher() {};
	virtual void addStudent() {};
	virtual void viewAllStudents() {};
	virtual void viewAllTeacher() {};
	virtual void editStudent() {};
	virtual void editTeacher() {};


};
class SignIn :public Admin
{
public:
	void sign_In();
};
class Add_Teachers :public Admin
{
public:

	void addTeacher();
};
class Add_Student :public Admin {

	void addStudent();


};

class Edit_Student :public Admin
{
public:
	void editStudent();

};

class Edit_Teacher :public Admin
{
public:
	void editTeacher();

};

class View :public Admin
{
public:
	void viewAllStudents();


	void viewAllTeacher();
};




//Teacher Class
class Teacher :public Admin
{
protected:


	ifstream readCourse;
	ofstream  writeCourse;

	ifstream readDepartment;
	ofstream  writeDepartment;

	ifstream readGrade;
	ofstream  writeGrade;

	ifstream readMarks;
	ofstream  writeMarks;

	ifstream readAttendance;
	ofstream  writeAttendance;

	ifstream readTeacher;
	ofstream writeTeacher;

	string rollNumber;
	string TeacherId;
	string CoursesStore[10];
	bool check = false;
	bool attendanceCheck;
	char presence;
	char presence1;
	char presence2;
	int Day;
	int Day1;
	int Day2;
	int month;
	int month1;
	int month2;
	int year;
	int year1;
	int year2;
	bool checkId;
	string StudentdepartmentName;
	string TeacherdepartmentName;
	string readId;
	bool marksCheck;
	int marks;
	int marks1;
	int marks2;
	bool registerCheck;
	char choice;
	string readFile;
	string courseRead[3];
	string studentRollno;
	bool gradeCheck;
	char Grade;
	char Grade1;
	char Grade2;
	string CheckStudent;
	string course;
	string readTemp;



public:


	Teacher();


	virtual void signIn() {};
	virtual void teacher_time_table() {};
	virtual void teacher_menu() {};
	virtual void assignMarks() {};
	virtual void assign_attendance() {};
	virtual void assign_grades() {};
	virtual void timeTable() {};
};



//Sign In
class Signin :public Teacher
{

	void signIn();
};


//attandance
class attendance :public Teacher
{
public:


	void assign_attendance();
};


class Marks :public Teacher
{
protected:


public:


	void assignMarks();
};


class Grades :public Teacher {


public:


	void assign_grades();
};
class TimeTable :public Teacher
{

public:


	void timeTable();
};



//Student Class 

class Student :public Admin
{
protected:
	ifstream read_File;
	ofstream write_File;


	ifstream readStudentID;
	ofstream writeStudentID;

	ifstream readAttendance;
	ofstream writeAttendance;

	ifstream readMarks;
	ifstream writeMarks;

	ifstream readGrades;
	ofstream writeGrades;

	ifstream readStudentData;

	ifstream readRegister;
	ofstream writeRegister;

	ifstream readCourseFile;
	ofstream writeCourseFile;

	string User_Name;
	string Password;

	//For Course Registration
	bool registerCheck = false;
	string StudentdepartmentName;
	char choice;
	string CoursesStore[5];
	string RegisteredCourses[3];
	bool matchCheck = false;

	//For Finding The Student
	string rollNumber;
	string readRollNumber;

	//For Storing Data Which is Read From Files 
	string course[3], grade[3];
	string Attendance[9];
	string courseRead[3];
	int marks[3];
	string feeStatus;
	string coursestore[3];




public:

	Student();

	virtual  void sing_In() {};
	virtual void viewAttendance() {};
	virtual void viewMarks() {};
	virtual void viewGrades() {};
	virtual void assignCourses() {};
	virtual void viewRegisteredCourse() {};
	virtual void viewFeeStatus() {};

};
class Sign_in :public Student
{
public:

	void sign_In();
};
class View_marks : public Student
{

public:

	void viewMarks();
};

class ViewGrades : public Student {


public:

	void viewGrades();
};

class ViewAttendance : public Student {

public:
	void viewAttendance();
};


class ViewFeeStatus : public Student
{

public:
	void viewFeeStatus();
};

class AssignCourse :public Student
{
public:

	void assignCourses();
};

class ViewAssignCourse :public Student
{
public:


	void viewRegisteredCourse();
};


void mainMenu();

void adminMenu();

void teacherMenu();

void Student_Menu();

void Captcha();
