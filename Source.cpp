#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iomanip>
#include"Header.h"
using namespace std;


Admin::Admin()
{
	User_Name = "";
	User_Name_File = "";
	Password = "";
	Password_File = "";

	First_Name = "";
	Last_Name = "";
	departmentChoice = 0;
	Teacher_Department_Name = "";

	//Student_Department_Name = "";

	std_number = 1000;
	gender = "";
	Registration_Date = "";
	genderChoice = '\0';
	Contact_Number = "";
	Qualification = "";
	Address = "";
	feeStatus = '\0';
	marks = "";
	studentCount = 0;
	teacherCount = 0;
	Blood_Gorup = "";

}

void SignIn::sign_In()
{
	bool check = false;
	string username;
	string password;

	while (true)
	{
		cout << "\t\t\t\tEnter UserName: ";
		cin >> User_Name;
		cout << "\t\t\t\tEnter Password : ";
		cin >> Password;

		read_File.open("Admin.txt");
		while (!read_File.eof())
		{
			read_File >> username;
			read_File >> password;
			if (username == User_Name && password == Password)
			{
				check = true;
				break;
			}
		}
		if (check == true)
		{
			break;
		}
		else
		{
			cout << "\t\t\t\tYou Entered Wrong Information ! \n";
			cout << "          Try Again\n";
		}
		read_File.close();
	}
}


void Add_Teachers::addTeacher()
{
	string departmentName;
	string idname, id;

	cout << "\n\t1) Add_Teacher Portal" << endl;

	cout << "Enter Teacher First Name: ";
	cin >> First_Name;
	cout << "Enter Teacher Last Name: ";
	cin >> Last_Name;

	cout << "Choose Department             \n";
	cout << " 1) Computer Science student  \n";
	cout << " 2) Electrical Engineering   \n";
	cout << " 3) Software Engineering     \n";
	cout << " 4)Business                \n";
	cout << " 5) Social Sciences         \n";

	cout << "You Choose: ";
	cin >> departmentChoice;

	if (departmentChoice == 1)
	{
		Teacher_Department_Name = "Computer Science";
	}

	else if (departmentChoice == 2)
	{
		Teacher_Department_Name = "Electrical Engineering";

	}

	else if (departmentChoice == 3)
	{
		Teacher_Department_Name = "Software Engineering";
	}

	else if (departmentChoice == 4)
	{
		Teacher_Department_Name = "Business";
	}

	else if (departmentChoice == 5)
	{
		Teacher_Department_Name = "Social Sciences";
	}

	read_File.open("TeacherId.txt");
	if (!read_File.is_open()) {

		write_File.open("TeacherId.txt");
		write_File << std_number << endl;
		write_File.close();
	}
	read_File.close();


	read_File.open("TeacherId.txt");
	while (!read_File.eof())
	{
		read_File >> std_number;
	}
	std_number += 1;
	read_File.close();


	cout << "Your ID is: ";
	if (departmentChoice == 1)
	{
		Teacher_Department_Name = "Computer Science";
		departmentName = "CS-";
		cout << departmentName << std_number << endl;
	}

	else if (departmentChoice == 2)
	{
		Teacher_Department_Name = "Electrical Engineering";
		departmentName = "EE-";
		cout << departmentName << std_number << endl;
	}

	else if (departmentChoice == 3)
	{
		Teacher_Department_Name = "Software Engineering";
		departmentName = "SE-";
		cout << departmentName << std_number << endl;
	}

	else if (departmentChoice == 4)
	{
		departmentName = "B-";
		cout << departmentName << std_number << endl;
		Teacher_Department_Name = "Business";
	}

	else if (departmentChoice == 5)
	{
		Teacher_Department_Name = "Social Science";
		departmentName = "SS-";
		cout << departmentName << std_number << endl;
	}





	id = to_string(std_number);
	User_Name = departmentName + id;
	cout << "Your User Name is : " << User_Name << endl;


	cout << "\nEnter Password: ";
	cin >> Password;

	cout << "Enter Registration Date: ";
	cin >> Registration_Date;


	cout << "1-Male\n";
	cout << "2-Female\n";
	while (true)
	{
		cout << "Enter Gender: ";
		cin >> genderChoice;
		if (genderChoice == '1' || genderChoice == '2')
		{
			if (genderChoice == '1')
			{
				gender = "Male";
			}
			else if (genderChoice == '2')
			{
				gender = "Female";
			}
			break;
		}
	}


	cout << "Enter Contact Number: ";
	cin >> Contact_Number;
	cout << "Enter Qualification: ";
	cin >> Qualification;
	cout << "Enter Address: ";
	cin >> Address;




	//data write in file
	write_File.open("Teacher.txt", ios::app);

	//Write Teacher ID
	write_File << departmentName << std_number << endl;
	write_File << Teacher_Department_Name << endl;


	write_File << First_Name << endl;
	write_File << Last_Name << endl;
	write_File << Address << endl;
	write_File << Contact_Number << endl;


	//writting  teacher id






	write_File << Registration_Date << endl;
	write_File << User_Name << endl;

	write_File << Password << endl;
	write_File << gender << endl;
	write_File << Qualification << endl;

	write_File << endl;

	write_File.close();

	//write standerd number of teacher id in file






	write_Teacher_Id.open("TeacherId.txt", ios::app);
	write_Teacher_Id << std_number << endl;
	write_Teacher_Id.close();

	write_File.open("TeacherData.txt", ios::app);
	write_File << User_Name << endl;
	write_File << Password << endl;
	write_File << endl;
	write_File.close();

}

void Add_Student::addStudent()
{
	string departmentName;
	string batchname;
	string id;

	cout << "\n\t1) Add_Student Portal" << endl;
	cout << "Enter Student First Name: ";

	cin >> First_Name;
	cout << "Enter Student Last Name: ";
	cin >> Last_Name;


	cout << "Choose Department             \n";
	cout << " 1) Computer Science student  \n";
	cout << " 2) Electrical Engineering   \n";
	cout << " 3) Software Engineering     \n";
	cout << " 4)Business                \n";
	cout << " 5) Social Sciences         \n";
	cout << "You Choose: ";
	cin >> departmentChoice;




	if (departmentChoice == 1)
	{
		departmentName = "Computer Science";
	}

	else if (departmentChoice == 2)
	{
		departmentName = "Electrical Engineering";

	}

	else if (departmentChoice == 3)
	{
		departmentName = "Software Engineering";
	}

	else if (departmentChoice == 4)
	{
		departmentName = "Business";
	}

	else if (departmentChoice == 5)
	{
		departmentName = "Social Sciences";
	}


	//making uniqe roll no

	read_Student_Id.open("StudentId.txt");
	if (!read_Student_Id.is_open())
	{
		write_Student_Id.open("StudentId.txt");
		write_Student_Id << std_number << endl;
		write_Student_Id.close();
	}
	read_Student_Id.close();

	read_Student_Id.open("StudentId.txt");
	while (!read_Student_Id.eof())
	{
		read_Student_Id >> std_number;
	}
	std_number += 1;
	read_Student_Id.close();


	cout << "Your ID IS : 22F-" << std_number << endl;


	batchname = "22F-";
	id = to_string(std_number);
	User_Name = batchname + id;

	cout << "Your User Name is : " << User_Name << endl;

	cout << "\nEnter Password: ";
	cin >> Password;
	cout << "Enter Registration Date: ";
	cin >> Registration_Date;
	cout << "1-Male\n";
	cout << "2-Female\n";
	while (true)
	{
		cout << "Enter Gender: ";
		cin >> genderChoice;
		if (genderChoice == '1' || genderChoice == '2')
		{
			if (genderChoice == '1')
			{
				gender = "Male";
			}
			else if (genderChoice == '2')
			{
				gender = "Female";
			}
			break;
		}
	}
	cout << "Enter Contact Number: ";
	cin >> Contact_Number;
	cout << "Enter Qualification: ";
	cin >> Qualification;
	cout << "Enter Address: ";
	cin >> Address;
	cout << "1-Paid\n";
	cout << "2-Unpaid\n";
	while (true)
	{
		cout << "Enter Fee Status : ";
		cin >> feeStatus;
		if (feeStatus == '1' || feeStatus == '2')
		{
			break;
		}
	}
	cout << "Enter Blood Group : ";
	cin >> Blood_Gorup;
	cout << "Enter Marks : ";
	cin >> marks;


	//data write in file
	write_File.open("Student.txt", ios::app);
	write_File << "22F-" << std_number << endl;
	write_File << departmentName << endl;

	write_File << First_Name << endl;
	write_File << Last_Name << endl;
	write_File << Address << endl;
	write_File << Contact_Number << endl;
	write_File << feeStatus << endl;

	write_File << Registration_Date << endl;



	write_File << User_Name << endl;

	write_File << Password << endl;


	write_File << gender << endl;

	write_File << Qualification << endl;

	write_File << Blood_Gorup << endl;
	write_File << marks << endl;
	write_File << endl;
	write_File.close();


	//write roll number in file

	write_Student_Id.open("StudentId.txt", ios::app);
	write_Student_Id << std_number << endl;
	write_Student_Id.close();

	write_File.open("StudentData.txt", ios::app);
	write_File << User_Name << endl;
	write_File << Password << endl;
	write_File << endl;
	write_File.close();

}



void Edit_Student::editStudent()
{
	bool checkId = false;
	bool check = false;
	string studentRollno;
	string readId;
	string storeData[5];
	string tempData[5];
	char choice;
	string rollNumber;
	string readData;


	while (true)
	{

		cout << "Enter Roll no. : ";
		cin >> studentRollno;

		if (studentRollno.length() != 8)
		{
			while (true)
			{
				cout << "Incorrect Roll Number!\n";
				cout << "Enter Correct Roll no. : ";
				cin >> studentRollno;
				if (studentRollno.length() == 8)
				{
					break;
				}
			}
		}

		rollNumber = studentRollno;

		studentRollno = studentRollno.substr(4, 7);

		read_Student_Id.open("StudentId.txt");
		while (!read_Student_Id.eof())
		{
			read_Student_Id >> readId;
			if (readId == studentRollno)
			{
				checkId = true;
				break;
			}
		}
		read_Student_Id.close();
		if (checkId == false)
		{
			cout << "Student Not Found!" << endl;
		}
		else
		{
			break;
		}
	}


	read_File.open("Student.txt");

	while (!read_File.eof())
	{
		getline(read_File, readData);
		if (readData == rollNumber)
		{
			getline(read_File, readData);
			for (int i = 0; i < 5; ++i) {
				getline(read_File, storeData[i]);
			}
			break;
		}
	}
	read_File.close();


	for (int i = 0; i < 5; ++i)
	{

		tempData[i] = storeData[i];

	}

	while (true)
	{
		cout << "\n1) Edit First Name  " << endl;
		cout << "2) Edit Last Name   " << endl;
		cout << "3) Edit Address      " << endl;
		cout << "4) Edit Contact Number " << endl;
		cout << "5) Edit Fee Status  " << endl;
		cout << "6) For Exit            " << endl;

		cout << "Enter Choice : ";
		cin >> choice;



		switch (choice)
		{
		case '1':
		{
			cout << "Enter New First Name : ";
			cin >> storeData[0];
			break;
		}
		case '2':
		{
			cout << "Enter New Last Name : ";
			cin >> storeData[1];
			break;
		}
		case '3':
		{
			cout << "Enter New Address : ";
			cin >> storeData[2];
			break;
		}
		case '4':
		{
			cout << "Enter New Contact Number : ";
			cin >> storeData[3];
			break;
		}
		case '5':
		{
			cout << "Enter Fee Status : ";
			cin >> storeData[4];
			break;
		}
		case '6':
		{
			check = true;
			break;
		}
		default:
		{
			cout << "Invalid Input!\n";
			break;
		}
		}
		if (check == true)
		{
			break;
		}
		cout << "Your Data Successfully Edited!\n";


	}

	write_File.open("StudentTempData.txt");
	read_File.open("Student.txt");

	while (!read_File.eof())
	{
		getline(read_File, readData);

		for (int i = 0; i < 5; ++i)
		{
			if (readData == tempData[i])
			{
				readData = storeData[i];
				break;
			}
		}

		write_File << readData << endl;
	}
	write_File.close();
	read_File.close();


	write_File.open("Student.txt");
	read_File.open("StudentTempData.txt");
	while (!read_File.eof())
	{
		getline(read_File, readData);
		write_File << readData << endl;
	}
	write_File.close();
	read_File.close();
}


void Edit_Teacher::editTeacher()
{
	bool checkId = false;
	bool check = false;
	string TeacherRollno;
	string readId;
	string storeData[4];
	string tempData[4];
	char choice;
	string TeacherID;
	string readData;


	while (true)
	{
		cout << "Enter Teacher ID : ";
		cin >> TeacherRollno;
		if (TeacherRollno.length() != 7)
		{
			while (true)
			{
				cout << "Incorrect Roll Number!\n\n";
				cout << "Enter Correct Roll no. : ";
				cin >> TeacherRollno;
				if (TeacherRollno.length() == 7)
				{
					break;
				}
			}
		}
		TeacherID = TeacherRollno;
		TeacherRollno = TeacherRollno.substr(3, 6);

		read_Teacher_Id.open("Teacher.txt");
		while (!read_Teacher_Id.eof())
		{
			read_Teacher_Id >> readId;
			if (readId == TeacherID)
			{
				checkId = true;
				break;
			}
		}
		read_Teacher_Id.close();
		if (checkId == false)
		{
			cout << "Teacher Not Found!" << endl;
		}
		else
		{
			break;
		}
	}


	read_File.open("Teacher.txt");

	while (!read_File.eof())
	{

		getline(read_File, readData);
		if (readData == TeacherID)
		{

			getline(read_File, readData);

			for (int i = 0; i < 4; ++i) {

				getline(read_File, storeData[i]);
			}
			break;
		}
	}
	read_File.close();


	for (int i = 0; i < 4; ++i)
	{

		tempData[i] = storeData[i];

	}

	while (true)
	{

		cout << "\n1) Edit First Name  " << endl;
		cout << "2) Edit Last Name   " << endl;
		cout << "3) Edit Address      " << endl;
		cout << "4) Edit Contact Number " << endl;
		cout << "5) For Exit            " << endl;

		cout << "Enter Choice : ";
		cin >> choice;



		switch (choice)
		{
		case '1':
		{
			cout << "Enter New First Name : ";
			cin >> storeData[0];
			break;
		}
		case '2':
		{
			cout << "Enter New Last Name : ";
			cin >> storeData[1];
			break;
		}
		case '3':
		{
			cout << "Enter New Address : ";
			cin >> storeData[2];
			break;
		}
		case '4':
		{
			cout << "Enter New Contact Number : ";
			cin >> storeData[3];
			break;
		}
		case '5':
		{
			check = true;
			break;
		}
		default:
		{
			cout << "Invalid Input!\n";
			break;
		}
		}
		if (check == true)
		{
			break;
		}

		cout << "Your Data Successfully Edited!\n";
	}

	write_File.open("TeacherTempData.txt");
	read_File.open("Teacher.txt");

	while (!read_File.eof())
	{
		getline(read_File, readData);

		for (int i = 0; i < 4; ++i)
		{
			if (readData == tempData[i])
			{
				readData = storeData[i];
				break;
			}
		}
		write_File << readData << endl;
	}
	write_File.close();
	read_File.close();



	write_File.open("Teacher.txt");
	read_File.open("TeacherTempData.txt");
	while (!read_File.eof())
	{
		getline(read_File, readData);
		write_File << readData << endl;
	}
	write_File.close();
	read_File.close();
}




void View::viewAllStudents()
{

	string arr[14];
	int count = 0;
	string readcount;
	string readData;
	char choice;
	string rollNumber;
	bool check = false;

	read_File.open("StudentId.txt");
	if (read_File.is_open())
	{

		cout << "\t\t\t1-Display Data of All Students\n";
		cout << "\t\t\t2-Display Data of Specific Student\n";

		cout << "\t\t\tEnter Choice : ";
		cin >> choice;

		if (choice == '1')
		{

			while (read_File >> readcount)
			{
				count++;
			}
			read_File.close();

			count = count - 1;
			cout << "\t\t\t\tTotal Students Added Are : " << count << endl;

			cout << "\n\t\t\t\tSTUDENTS RECORDS\n";

			read_File.open("Student.txt");
			while (count > 0)
			{
				read_File.ignore();
				for (int i = 0; i < 14; i++)
				{
					getline(read_File, arr[i]);
				}
				//c++;

				cout << arr[0] << endl;
				cout << arr[2] + arr[3] << endl;
				cout << arr[1] << endl;
				cout << "\t\t\t\t" << setw(20) << "+----------------------+" << endl;
				for (int i = 4; i < 14; i++) {
					cout << "\t\t\t\t" << "| " << setw(20) << setfill(' ') << left << arr[i] << " |" << endl;
					cout << "\t\t\t\t" << setw(20) << "+----------------------+" << endl;
				}

				count--;
			}
			read_File.close();

		}
		else if (choice == '2')
		{



			while (true)
			{
				cout << "Enter Roll no. : ";
				cin >> rollNumber;

				if (rollNumber.length() != 8)
				{
					while (true)
					{
						cout << "Incorrect Roll Number!\n\n";
						cout << "Enter Correct Roll no. : ";
						cin >> rollNumber;
						if (rollNumber.length() == 8)
						{
							break;
						}
					}
				}
				if (rollNumber.length() == 8)
				{
					break;
				}

			}

			readView.open("Student.txt");


			while (!readView.eof())
			{
				getline(readView, readData);

				if (readData == rollNumber)
				{
					arr[0] = readData;
					for (int i = 1; i < 14; i++)
					{
						getline(readView, arr[i]);
					}
					check = true;

					break;
				}
			}
			readView.close();


			if (check == true)
			{
				cout << arr[0] << endl;
				cout << arr[2] + arr[3] << endl;
				cout << arr[1] << endl;
				cout << "\t\t\t\t" << setw(20) << setfill(' ') << "+----------------------+" << endl;
				for (int i = 4; i < 14; i++)
				{
					cout << "\t\t\t\t" << "| " << setw(20) << setfill(' ') << left << arr[i] << " |" << endl;
					cout << "\t\t\t\t" << setw(20) << setfill(' ') << "+----------------------+" << endl;
				}

			}
			else
			{
				cout << "Student Not Found!" << endl;
			}

		}


	}

	else
	{
		cout << "No Student is Added Yet!\n";
	}

	system("pause");
}


void View::viewAllTeacher()
{
	string readcount;
	int count = 0;
	string arr[11];
	string read;
	int size = 0;
	read_File.open("TeacherId.txt");
	if (read_File.is_open())
	{
		while (read_File >> readcount)
		{
			count++;
		}
		read_File.close();

		count = count - 1;
		cout << "\t\t\t\tTotal Teacher Added Are : " << count << endl;

		cout << "\n\t\t\t\tTEACHERS RECORDS\n";

		read_File.open("Teacher.txt");
		while (count > 0)
		{
			read_File.ignore();
			for (int i = 0; i < 11; i++)
			{
				getline(read_File, arr[i]);
			}


			cout << " Name          : " << arr[2] + arr[3] << endl;
			cout << " Gender        : " << arr[9] << endl;
			cout << " Qualification : " << arr[10] << endl;
			cout << " Contact NO.   : " << arr[5] << endl;
			cout << " UserName      : " << arr[7] << endl << endl;

			count--;
		}
	}
	else
	{
		cout << "No Teacher is Added Yet!\n";
	}

	read_File.close();

	system("pause");

}





//Teacher Class

Teacher::Teacher()
{
	choice = '\0';
	checkId = false;
	StudentdepartmentName = "";
	TeacherdepartmentName = "";
	for (int i = 0; i < 3; ++i)
	{
		courseRead[i] = "";
	}
	studentRollno = "";
	readId = "";
	marksCheck = false;
	marks = 0;
	marks1 = 0;
	marks2 = 0;
	readFile = "";
	course = "";
	rollNumber = "";
	CheckStudent = "";
	registerCheck = false;
	TeacherId = "";

	for (int i = 0; i < 10; ++i)
	{
		CoursesStore[i] = "";
	}

	check = false;
	attendanceCheck = false;
	presence = '\0';
	presence1 = '\0';
	presence2 = '\0';
	Day = 0;
	Day1 = 0;
	Day2 = 0;
	month = 0;
	month1 = 0;
	month2 = 0;
	year = 0;
	year1 = 0;
	year2 = 0;


	gradeCheck = false;
	Grade = '\0';
	Grade1 = '\0';
	Grade2 = '\0';
	readTemp = "";
}






//Sign In

void Signin::signIn()
{

	bool check = false;
	string username;
	string password;

	while (check == false)
	{
		cout << "Enter UserName: ";
		cin >> User_Name;
		cout << "Enter Password : ";
		cin >> Password;

		read_File.open("TeacherData.txt");
		while (!read_File.eof())
		{
			read_File >> username;
			read_File >> password;
			if (username == User_Name && password == Password)
			{
				check = true;
				break;
			}
			else
			{
				check = false;
			}
		}
		if (check == true)
		{
			break;
		}
		else
		{
			cout << "You Entered Wrong Information ! \n";
			cout << "          Try Again\n";
		}
		read_File.close();
	}
	write_File.open("Teachertemp.txt");
	write_File << User_Name;
	write_File.close();
}



//attandance



void attendance::assign_attendance()
{
	ifstream readDepartment;
	ofstream  writeDepartment;
	char moreChoice;

	while (true)
	{

		checkId = false;
		while (true)
		{
			cout << "Enter Roll no. : ";
			cin >> studentRollno;

			if (studentRollno.length() != 8)
			{
				while (true)
				{
					cout << "Incorrect Roll Number!\n\n";
					cout << "Enter Correct Roll no. : ";
					cin >> studentRollno;
					if (studentRollno.length() == 8)
					{
						break;
					}
				}
			}

			/*rollNumber = studentRollno;

			studentRollno = studentRollno.substr(4, 7);*/
			read_Student_Id.open("Student.txt");
			while (!read_Student_Id.eof())
			{
				read_Student_Id >> readId;

				if (readId == studentRollno)
				{
					read_Student_Id.close();
					checkId = true;
					break;
				}
			}
			if (checkId == true)
			{
				break;
			}
			else
			{
				cout << "Student Not Found!\n\n";
				read_Student_Id.close();
			}

		}




		readDepartment.open("Student.txt");
		if (!readDepartment.is_open())
		{
			cout << "Failed to open Student.txt\n";
		}
		else
		{
			while (readDepartment >> readFile)
			{
				if (readFile == studentRollno)
				{
					readDepartment.ignore();
					getline(readDepartment, StudentdepartmentName);
					break;
				}
			}
			readDepartment.close();
		}

		readDepartment.open("Teachertemp.txt");
		readDepartment >> readTemp;
		readDepartment.close();


		readDepartment.open("Teacher.txt");
		while (!readDepartment.eof())
		{
			readDepartment >> readFile;
			if (readFile == readTemp)
			{
				readDepartment.ignore();
				getline(readDepartment, TeacherdepartmentName);
				break;
			}
		}
		readDepartment.close();



		if (StudentdepartmentName == TeacherdepartmentName)
		{
			bool registerCheck = false;
			readCourse.open("RegisteredCourse.txt");
			if (!readCourse.is_open())
			{
				writeCourse.open("RegisteredCourse.txt");
				writeCourse.close();
			}
			readCourse.close();

			readCourse.open("RegisteredCourse.txt");
			while (!readCourse.eof())
			{
				readCourse >> course;
				if (course == studentRollno)
				{

					readCourse.ignore();
					for (int i = 0; i < 3; ++i)
					{
						getline(readCourse, courseRead[i]);
					}
					registerCheck = true;
				}

			}
			readCourse.close();

			if (registerCheck == true)
			{
				readAttendance.open("Attendance.txt");
				if (!readAttendance.is_open())
				{
					writeAttendance.open("Attendance.txt");
					writeAttendance.close();
				}
				readAttendance.close();

				readAttendance.open("Attendance.txt");
				while (!readAttendance.eof())
				{
					readAttendance >> CheckStudent;
					if (studentRollno == CheckStudent)
					{
						attendanceCheck = true;
						break;
					}

				}
				readAttendance.close();


				if (attendanceCheck == true)
				{
					cout << "Attendance Already Marked!\n";

				}
				else
				{
					bool check = false;
					int count = 0;
					while (check == false)
					{
						cout << "Student's Registerd Courses \n" << endl;
						cout << "1- " << courseRead[0] << endl;
						cout << "2- " << courseRead[1] << endl;
						cout << "3- " << courseRead[2] << endl;
						cout << "4-         For exit \n";
						char choice;
						cout << "\nEnter Course You Want To Mark Attendence : ";
						cin >> choice;

						switch (choice)
						{
						case '1':
						{
							while (true)
							{
								cout << "Enter Attendance of " << courseRead[0] << " : ";
								cin >> presence;
								if (presence == 'P' || presence == 'L' || presence == 'A')
								{
									count++;
									break;
								}
							}
							cout << "\t\tEnter Date\n";
							cout << "Enter Day : ";
							cin >> Day;
							cout << "Enter Month : ";
							cin >> month;
							cout << "Enter Year : ";
							cin >> year;
							break;
						}
						case '2':
						{
							while (true)
							{
								cout << "Enter Attendance of " << courseRead[1] << " : ";
								cin >> presence1;
								if (presence1 == 'P' || presence1 == 'L' || presence1 == 'A')
								{
									count++;
									break;
								}

							}
							cout << "\t\tEnter Date\n";
							cout << "Enter Day : ";
							cin >> Day1;
							cout << "Enter Month : ";
							cin >> month1;
							cout << "Enter Year : ";
							cin >> year1;

							break;
						}
						case '3':
						{
							while (true)
							{
								cout << "Enter Attendance of " << courseRead[2] << " : ";
								cin >> presence2;
								if (presence2 == 'P' || presence2 == 'L' || presence2 == 'A')
								{
									count++;
									break;
								}

							}
							cout << "\t\tEnter Date\n";
							cout << "Enter Day : ";
							cin >> Day2;
							cout << "Enter Month : ";
							cin >> month2;
							cout << "Enter Year : ";
							cin >> year2;

							break;
						}
						case'4':
						{
							check = true;
							break;
						}
						default:
						{
							cout << "Invalid Input!\n";
							break;
						}
						}
					}

					if (count > 0)
					{
						writeAttendance.open("Attendance.txt", ios::app);
						writeAttendance << studentRollno << endl;
						writeAttendance << courseRead[0] << endl;
						writeAttendance << Day << " - " << month << " - " << year << endl;
						writeAttendance << presence << endl;
						writeAttendance << courseRead[1] << endl;
						writeAttendance << Day1 << " - " << month1 << " - " << year1 << endl;
						writeAttendance << presence1 << endl;
						writeAttendance << courseRead[2] << endl;
						writeAttendance << Day2 << " - " << month2 << " - " << year2 << endl;
						writeAttendance << presence2 << endl;
						writeAttendance << endl;
						writeAttendance.close();
					}
				}

			}
			else
			{
				cout << "Student Not Registered!\n";
			}


		}
		else
		{
			cout << "Student Is From Other Department!\n";
		}

		cout << "Do you Want To Mark Attendance of More Students\n";
		cout << "1) Yes\n";
		cout << "2) No\n";
		cout << "Enter Choice : ";
		cin >> moreChoice;

		//breaking the main loop
		if (moreChoice == '1')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}




void Marks::assignMarks()
{
	char moreChoice;

	while (true)
	{
		checkId = false;
		while (true)
		{
			cout << "Enter Roll no. : ";
			cin >> studentRollno;

			if (studentRollno.length() != 8)
			{
				while (true)
				{
					cout << "Incorrect Roll Number!\n\n";
					cout << "Enter Correct Roll no. : ";
					cin >> studentRollno;
					if (studentRollno.length() == 8)
					{
						break;
					}
				}
			}

			read_Student_Id.open("Student.txt");
			while (!read_Student_Id.eof())
			{
				read_Student_Id >> readId;

				if (readId == studentRollno)
				{
					checkId = true;
					read_Student_Id.close();
					break;
				}
			}
			if (checkId == true)
			{
				break;
			}
			else
			{
				cout << "Student Not Found!\n\n";
			}
			read_Student_Id.close();

		}


		readDepartment.open("Student.txt");
		while (!readDepartment.eof())
		{
			readDepartment >> readFile;
			if (readFile == studentRollno)
			{
				readDepartment.ignore();
				getline(readDepartment, StudentdepartmentName);

				break;
			}
		}
		readDepartment.close();


		readDepartment.open("Teachertemp.txt");
		readDepartment >> readTemp;
		readDepartment.close();


		readDepartment.open("Teacher.txt");
		while (!readDepartment.eof())
		{
			readDepartment >> readFile;
			if (readFile == readTemp)
			{
				readDepartment.ignore();
				getline(readDepartment, TeacherdepartmentName);
				break;
			}
		}
		readDepartment.close();


		if (StudentdepartmentName == TeacherdepartmentName)
		{
			bool registerCheck = false;
			readCourse.open("RegisteredCourse.txt");
			if (!readCourse.is_open())
			{
				writeCourse.open("RegisteredCourse.txt");
				writeCourse.close();
			}
			readCourse.close();

			readCourse.open("RegisteredCourse.txt");

			while (!readCourse.eof())
			{
				readCourse >> course;
				if (course == studentRollno)
				{
					readCourse.ignore();
					for (int i = 0; i < 3; ++i)
					{
						getline(readCourse, courseRead[i]);
					}
					registerCheck = true;
					break;
				}

			}
			readCourse.close();


			if (registerCheck == true)
			{
				readMarks.open("Marks.txt");
				if (!readMarks.is_open())
				{
					writeMarks.open("Marks.txt");
					writeMarks.close();
				}
				readMarks.close();

				readMarks.open("Marks.txt");
				while (!readMarks.eof())
				{
					readMarks >> CheckStudent;
					if (studentRollno == CheckStudent)
					{
						marksCheck = true;
						break;
					}

				}
				readMarks.close();


				if (marksCheck == true)
				{
					cout << "Marks Already Assigned!\n";

				}
				else
				{
					bool check = false;
					int count = 0;
					while (check == false)
					{
						cout << "Student's Registerd Courses \n" << endl;
						cout << "1- " << courseRead[0] << endl;
						cout << "2- " << courseRead[1] << endl;
						cout << "3- " << courseRead[2] << endl;
						cout << "4-         For exit \n";
						char choice;
						cout << "\nEnter Course You Want To Giving Marks : ";
						cin >> choice;



						switch (choice)
						{
						case '1':
						{
							while (true)
							{
								cout << "Enter Marks of " << courseRead[0] << " : ";
								cin >> marks;

								count++;
								break;

							}

							break;
						}
						case '2':
						{
							while (true)
							{
								cout << "Enter Marks of " << courseRead[1] << " : ";
								cin >> marks1;

								count++;
								break;


							}


							break;
						}
						case '3':
						{
							while (true)
							{
								cout << "Enter Marks of " << courseRead[2] << " : ";
								cin >> marks2;

								count++;
								break;


							}


							break;
						}
						case'4':
						{
							check = true;
							break;
						}
						default:
						{
							cout << "Invalid Input!\n";
							break;
						}
						}
					}

					if (count > 0)
					{
						writeMarks.open("Marks.txt", ios::app);
						writeMarks << studentRollno << endl;
						writeMarks << courseRead[0] << endl;
						writeMarks << marks << endl;
						writeMarks << courseRead[1] << endl;
						writeMarks << marks1 << endl;
						writeMarks << courseRead[2] << endl;
						writeMarks << marks2 << endl;
						writeMarks << endl;
						writeMarks.close();
					}
				}
			}
			else
			{
				cout << "Student Not Registered!\n";
			}

		}
		else
		{
			cout << "Student Is From Other Department!\n";

		}

		cout << "Do you Want To Giving Marks to More Students\n";
		cout << "1) Yes\n";
		cout << "2) No\n";
		cout << "Enter Choice : ";
		cin >> moreChoice;

		//breaking the main loop
		if (moreChoice == '1')
		{
			continue;
		}
		else
		{
			break;
		}

	}

}





void Grades::assign_grades()
{
	char moreChoice;

	while (true)
	{

		checkId = false;
		while (true)
		{
			cout << "Enter Roll no. : ";
			cin >> studentRollno;

			if (studentRollno.length() != 8)
			{
				while (true)
				{
					cout << "Incorrect Roll Number!\n\n";
					cout << "Enter Correct Roll no. : ";
					cin >> studentRollno;
					if (studentRollno.length() == 8)
					{
						break;
					}
				}
			}

			/*rollNumber = studentRollno;

			studentRollno = studentRollno.substr(4, 7);*/

			read_Student_Id.open("Student.txt");
			while (!read_Student_Id.eof())
			{
				read_Student_Id >> readId;

				if (readId == studentRollno)
				{
					checkId = true;
					read_Student_Id.close();
					break;
				}
			}
			if (checkId == true)
			{
				break;
			}
			else
			{
				cout << "Student Not Found!\n\n";
			}
			read_Student_Id.close();

		}

		/*cout << studentRollno << endl;
		cout << readId << endl;*/

		readDepartment.open("Student.txt");
		while (!readDepartment.eof())
		{
			readDepartment >> readFile;
			if (readFile == studentRollno)
			{
				readDepartment.ignore();
				getline(readDepartment, StudentdepartmentName);

				break;
			}
		}
		readDepartment.close();


		readDepartment.open("Teachertemp.txt");
		readDepartment >> readTemp;
		readDepartment.close();


		readDepartment.open("Teacher.txt");
		while (!readDepartment.eof())
		{
			readDepartment >> readFile;
			if (readFile == readTemp)
			{
				readDepartment.ignore();
				getline(readDepartment, TeacherdepartmentName);
				break;
			}
		}
		readDepartment.close();

		/*cout << StudentdepartmentName << endl;
		cout << TeacherdepartmentName << endl;*/


		if (StudentdepartmentName == TeacherdepartmentName)
		{
			bool registerCheck = false;
			readCourse.open("RegisteredCourse.txt");
			if (!readCourse.is_open())
			{
				writeCourse.open("RegisteredCourse.txt");
				writeCourse.close();
			}
			readCourse.close();


			readCourse.open("RegisteredCourse.txt");
			while (!readCourse.eof())
			{
				readCourse >> course;
				if (course == studentRollno)
				{
					readCourse.ignore();
					for (int i = 0; i < 3; ++i)
					{
						getline(readCourse, courseRead[i]);
					}
					registerCheck = true;
					break;
				}

			}
			readCourse.close();


			if (registerCheck == true)
			{
				readGrade.open("Attendance.txt");
				if (!readGrade.is_open())
				{
					writeGrade.open("Attendance.txt");
					writeGrade.close();
				}
				readGrade.close();

				readGrade.open("Grades.txt");
				while (!readGrade.eof())
				{
					readGrade >> CheckStudent;

					if (studentRollno == CheckStudent)
					{
						//cout << "Student FOund" << endl;
						gradeCheck = true;
						break;
					}
				}
				readGrade.close();

				if (gradeCheck == true)
				{
					cout << "Grades Already Assigned!\n";

				}
				else
				{
					bool check = false;
					int count = 0;
					while (check == false)
					{
						cout << "Student's Registerd Courses \n" << endl;
						cout << "1- " << courseRead[0] << endl;
						cout << "2- " << courseRead[1] << endl;
						cout << "3- " << courseRead[2] << endl;
						cout << "4-         For exit \n";
						char choice;
						cout << "\nEnter Course You Want To Grading : ";
						cin >> choice;

						switch (choice)
						{
						case '1':
						{
							while (true)
							{
								cout << "Enter Grade of " << courseRead[0] << " : ";
								cin >> Grade;
								if (Grade == 'B' || Grade == 'C' || Grade == 'A')
								{
									count++;
									break;
								}
							}

							break;
						}
						case '2':
						{
							while (true)
							{
								cout << "Enter Grade of " << courseRead[1] << " : ";
								cin >> Grade1;
								if (Grade1 == 'C' || Grade1 == 'B' || Grade1 == 'A')
								{
									count++;
									break;
								}

							}

							break;
						}
						case '3':
						{
							while (true)
							{
								cout << "Enter Grade of " << courseRead[2] << " : ";
								cin >> Grade2;
								if (Grade2 == 'C' || Grade2 == 'B' || Grade2 == 'A')
								{
									count++;
									break;
								}

							}

							break;
						}
						case'4':
						{
							check = true;
							break;
						}
						default:
						{
							cout << "Invalid Input!\n";
							break;
						}
						}
					}

					if (count > 0)
					{
						writeGrade.open("Grades.txt", ios::app);
						writeGrade << studentRollno << endl;
						writeGrade << courseRead[0] << endl;
						writeGrade << Grade << endl;
						writeGrade << courseRead[1] << endl;
						writeGrade << Grade1 << endl;
						writeGrade << courseRead[2] << endl;
						writeGrade << Grade2 << endl;
						writeGrade << endl;
						writeGrade.close();
					}
				}

			}
			else
			{
				cout << "Student Not Registered!\n";
			}


		}
		else
		{
			cout << "Student Is From Other Department!\n";
			// check2 = false;
		}

		cout << "Do you Want To Giving Grades to More Students\n";
		cout << "1) Yes\n";
		cout << "2) No\n";
		cout << "Enter Choice : ";
		cin >> moreChoice;
		//breaking the main loop
		if (moreChoice == '1')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}




void TimeTable::timeTable()
{
	readTeacher.open("TeacherTemp.txt");
	readTeacher >> TeacherId;
	readTeacher.close();

	readTeacher.open("Teacher.txt");
	while (!readTeacher.eof())
	{
		readTeacher >> readFile;
		if (readFile == TeacherId)
		{
			readTeacher.ignore();
			getline(readTeacher, TeacherdepartmentName);
			break;
		}
	}
	readTeacher.close();



	if (TeacherdepartmentName == "Computer Science")
	{
		CoursesStore[0] = " ";
		CoursesStore[1] = "PF";
		CoursesStore[2] = " ";
		CoursesStore[3] = "OOP";
		CoursesStore[4] = " ";
		CoursesStore[5] = "DS";
		CoursesStore[6] = " ";
		CoursesStore[7] = "DB";
		CoursesStore[8] = " ";
		CoursesStore[9] = "OS";

	}
	else if (TeacherdepartmentName == "Electrical Engineering")
	{
		CoursesStore[0] = " ";
		CoursesStore[1] = "DE";
		CoursesStore[2] = " ";
		CoursesStore[3] = "SD";
		CoursesStore[4] = " ";
		CoursesStore[5] = "AE";
		CoursesStore[6] = "DB";
		CoursesStore[7] = " ";
		CoursesStore[8] = "EF";
		CoursesStore[9] = " ";

	}
	else if (TeacherdepartmentName == "Software Engineering")
	{
		CoursesStore[0] = "PF";
		CoursesStore[1] = " ";
		CoursesStore[2] = "OP";
		CoursesStore[3] = " ";
		CoursesStore[4] = "DS";
		CoursesStore[5] = " ";
		CoursesStore[6] = "DB";
		CoursesStore[7] = " ";
		CoursesStore[8] = "OS";
		CoursesStore[9] = " ";

	}
	else if (TeacherdepartmentName == "Business")
	{
		CoursesStore[0] = "MS";
		CoursesStore[1] = " ";
		CoursesStore[2] = "Finance";
		CoursesStore[3] = " ";
		CoursesStore[4] = "Accounting";
		CoursesStore[5] = " ";
		CoursesStore[6] = "Marketing";
		CoursesStore[7] = " ";
		CoursesStore[8] = " ";
		CoursesStore[9] = "Advertisement";

	}
	else if (TeacherdepartmentName == "Social Sciences")
	{
		CoursesStore[0] = "History";
		CoursesStore[1] = " ";
		CoursesStore[2] = "Geography";
		CoursesStore[3] = " ";
		CoursesStore[4] = "PS";
		CoursesStore[5] = " ";
		CoursesStore[6] = "PS";
		CoursesStore[7] = " ";
		CoursesStore[8] = " Economics";
		CoursesStore[9] = " ";

	}

	for (int i = 0; i < (10 - 1); i++)
	{
		int r = i + (rand() % (10 - i));
		srand(time(0));
		string temp = CoursesStore[i];
		CoursesStore[i] = CoursesStore[r];
		CoursesStore[r] = temp;
	}

	for (int i = 0; i < (10 - 1); i++)
	{
		cout << CoursesStore[i] << endl;

	}

	cout << "\t\t+==========================================================================+" << endl;
	cout << "\t\t|--------------------------| Teacher Time Table |--------------------------|" << endl;
	cout << "\t\t|==========================================================================|" << endl;
	cout << "\t\t|  Time Slot  |  Monday  |  Tuesday  |  Wednesday  |  Thursday  |  Friday  |" << endl;
	cout << "\t\t|--------------------------------------------------------------------------|" << endl;
	cout << "\t\t| 08:00-09:00 |    " << CoursesStore[0] << "    |     " << CoursesStore[9] << "    |      " << CoursesStore[8] << "     |      " << CoursesStore[2] << "    |    " << CoursesStore[6] << "    |    " << endl;
	cout << "\t\t| 09:00-10:00 |    " << CoursesStore[1] << "    |     " << CoursesStore[8] << "    |      " << CoursesStore[6] << "     |      " << CoursesStore[0] << "    |    " << CoursesStore[5] << "    |    " << endl;
	cout << "\t\t| 10:00-11:00 |    " << CoursesStore[2] << "    |     " << CoursesStore[7] << "    |      " << CoursesStore[4] << "     |      " << CoursesStore[4] << "    |    " << CoursesStore[7] << "    |" << endl;
	cout << "\t\t| 11:00-12:00 |    " << CoursesStore[3] << "    |     " << CoursesStore[6] << "    |      " << CoursesStore[2] << "     |      " << CoursesStore[2] << "    |    " << CoursesStore[4] << "    |" << endl;
	cout << "\t\t| 12:00-01:00 |    " << CoursesStore[4] << "    |     " << CoursesStore[5] << "    |      " << CoursesStore[0] << "     |      " << CoursesStore[6] << "    |    " << CoursesStore[8] << "    |" << endl;
	cout << "\t\t| 01:00-02:00 |    " << CoursesStore[5] << "    |     " << CoursesStore[4] << "    |      " << CoursesStore[1] << "     |      " << CoursesStore[8] << "    |    " << CoursesStore[3] << "    |" << endl;
	cout << "\t\t| 02:00-03:00 |    " << CoursesStore[6] << "    |     " << CoursesStore[3] << "    |      " << CoursesStore[3] << "     |      " << CoursesStore[7] << "    |    " << CoursesStore[1] << "    |" << endl;
	cout << "\t\t| 03:00-04:00 |    " << CoursesStore[7] << "    |     " << CoursesStore[2] << "    |      " << CoursesStore[5] << "     |      " << CoursesStore[5] << "    |    " << CoursesStore[2] << "    |" << endl;
	cout << "\t\t| 04:00-05:00 |    " << CoursesStore[8] << "    |     " << CoursesStore[1] << "    |      " << CoursesStore[7] << "     |      " << CoursesStore[3] << "    |    " << CoursesStore[9] << "    |" << endl;
	cout << "\t\t| 05:00-06:00 |    " << CoursesStore[9] << "    |     " << CoursesStore[0] << "    |      " << CoursesStore[9] << "     |      " << CoursesStore[1] << "    |    " << CoursesStore[0] << "    |" << endl;
	cout << "\t\t+==========================================================================+" << endl;

	cout << "\n\t\t\t  -> Here Is The Weekly TimeTable Of Teacher " << TeacherId << " :) " << endl;
	cout << endl;
	system("pause");

}







//Student Class 



Student::Student()
{
	User_Name = "";
	Password = "";

	registerCheck = false;
	StudentdepartmentName = "";
	choice = '\0';
	matchCheck = false;

	string rollNumber = "";
	string readRollNumber = "";

	string feeStatus = "";

	//Initialize Array
	for (int i = 0; i < 9; ++i)
	{
		if (i < 3)
		{
			RegisteredCourses[i] = "";
			marks[i] = 0;
			coursestore[i] = "";
			courseRead[i] = "";
			course[i] = "";
			grade[i] = "";
		}
		if (i < 5)
		{
			CoursesStore[i] = "";
		}
		Attendance[i] = "";
	}
}



void Sign_in::sign_In()
{
	string username;
	string password;
	bool Check_Input = false;
	while (Check_Input == false)
	{
		cout << "\t\t\t\tEnter UserName: ";
		//cin.ignore();
		cin >> User_Name;
		cout << "\t\t\t\tEnter password: ";
		cin >> Password;


		read_File.open("StudentData.txt");
		while (!read_File.eof())
		{
			read_File >> username;
			read_File >> password;
			if (username == User_Name && password == Password)
			{
				Check_Input = true;
				break;
			}
			else
			{
				Check_Input = false;
			}
		}
		if (Check_Input == true)
		{
			read_File.close();
			break;
		}
		else
		{
			cout << "You Entered Wrong Information ! \n";
			cout << "          Try Again\n";
		}
		read_File.close();

	}
	write_File.open("StudentTemp.txt");
	write_File << User_Name << endl;
	write_File.close();
}


void View_marks::viewMarks() {

	read_File.open("StudentTemp.txt");
	read_File >> rollNumber;
	read_File.close();

	bool status = false;

	readMarks.open("Marks.txt");
	if (!readMarks.is_open())
	{
		writeMarks.open("Marks.txt");
		writeMarks.close();
	}
	readMarks.close();


	readMarks.open("Marks.txt");
	while (getline(readMarks, readRollNumber))
	{
		if (readRollNumber == rollNumber) {

			//status = true;

			for (int i = 0; i < 3; i++)
			{

				getline(readMarks, courseRead[i]);
				readMarks >> marks[i];
				readMarks.ignore();
			}

			break;
		}
	}
	readMarks.close();
	if (marks[0] != 0)
	{

		cout << "\t\t\t\t//////////////////////////////////////\n";
		cout << "\t\t\t\t||        Your Marks Are           ||\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "\t\t\t\t||" << courseRead[i] << " : " << marks[i] << "||" << endl;
		}
		cout << "\t\t\t\t//////////////////////////////////////\n";

	}
	else
	{
		cout << "Your Marks Are Not Uploaded Yet!\n";
	}
}




void ViewGrades::viewGrades() {

	read_File.open("StudentTemp.txt");
	read_File >> rollNumber;
	read_File.close();
	{

		readGrades.open("Grades.txt");
		if (!readGrades.is_open())
		{
			writeGrades.open("Grades.txt");
			writeGrades.close();
		}
		readGrades.close();
	}

	readGrades.open("Grades.txt");
	bool status = false;

	while (!readGrades.eof())
	{
		getline(readGrades, readRollNumber);

		if (readRollNumber == rollNumber)
		{
			//status = true;
			for (int i = 0; i < 3; ++i)
			{
				getline(readGrades, course[i]);
				getline(readGrades, grade[i]);
			}
			break;
		}
	}

	readGrades.close();

	if (grade[0] != "")
	{
		cout << "Grades for Roll Number " << rollNumber << ":" << endl;

		for (int i = 0; i < 3; ++i)
		{
			cout << "Course : " << course[i] << " | Grade : " << grade[i] << endl;
		}
	}
	else
	{
		cout << "Your Grades Are Not Uploaded Yet!\n";
	}

}




void ViewAttendance::viewAttendance() {

	read_File.open("StudentTemp.txt");
	read_File >> rollNumber;
	read_File.close();
	{

		readAttendance.open("Attendance.txt");
		if (!readAttendance.is_open())
		{
			writeAttendance.open("Attendance.txt");
			writeAttendance.close();
		}
		readAttendance.close();
	}


	readAttendance.open("Attendance.txt");

	while (!readAttendance.eof())
	{
		getline(readAttendance, readRollNumber);

		if (readRollNumber == rollNumber)
		{
			for (int i = 0; i < 9; ++i)
			{
				getline(readAttendance, Attendance[i]);

			}
			break;
		}
	}
	readAttendance.close();




	if (Attendance[0] != "")
	{
		cout << "Attendance for Roll Number " << rollNumber << ":" << endl;

		for (int i = 0; i < 9; ++i)
		{
			cout << Attendance[i] << endl;
		}
	}
	else
	{
		cout << "Your Ateendance is Not Marked Yet!\n";
	}

}




void ViewFeeStatus::viewFeeStatus() {

	read_File.open("StudentTemp.txt");
	read_File >> rollNumber;
	read_File.close();

	bool found = false;

	readStudentData.open("Student.txt");
	while (!readStudentData.eof()) {
		getline(readStudentData, readRollNumber);

		if (readRollNumber == rollNumber)
		{
			found = true;

			for (int i = 0; i < 6; i++)
			{
				getline(readStudentData, feeStatus);
			}

			break;
		}
	}
	readStudentData.close();

	if (found)
	{
		cout << "Fee status for Roll number " << rollNumber << ": " << feeStatus << endl;
	}
	else {
		cout << "Student not found!" << endl;
	}
}


void AssignCourse::assignCourses()
{
	registerCheck = false;

	read_File.open("StudentTemp.txt");
	read_File >> rollNumber;
	read_File.close();

	readRegister.open("RegisteredCourse.txt");
	if (!readRegister.is_open())
	{
		writeRegister.open("RegisteredCourse.txt");
		writeRegister.close();
	}
	readRegister.close();

	readRegister.open("RegisteredCourse.txt");
	while (!readRegister.eof())
	{
		readRegister >> readRollNumber;
		if (readRollNumber == rollNumber)
		{
			registerCheck = true;
			break;
		}
	}
	readRegister.close();


	if (registerCheck == false)
	{
		read_File.open("Student.txt");
		while (!read_File.eof())
		{
			read_File >> readRollNumber;
			if (readRollNumber == rollNumber)
			{
				read_File.ignore();
				getline(read_File, StudentdepartmentName);

				break;
			}
		}
		read_File.close();


		if (StudentdepartmentName == "Computer Science")
		{
			CoursesStore[0] = "Programming Fundamentals";
			CoursesStore[1] = "Object Oriented Programming";
			CoursesStore[2] = "Data Structures";
			CoursesStore[3] = "Data Base";
			CoursesStore[4] = "Operating System";
		}
		else if (StudentdepartmentName == "Electrical Engineering")
		{
			CoursesStore[0] = "Digital Electronics";
			CoursesStore[1] = "System Design";
			CoursesStore[2] = "Analogue Electrics";
			CoursesStore[3] = "Data Base";
			CoursesStore[4] = "Electromagnetic Fields";

		}
		else if (StudentdepartmentName == "Software Engineering")
		{
			CoursesStore[0] = "Programming Fundamentals";
			CoursesStore[1] = "Object Oriented Programming";
			CoursesStore[2] = "Data Structures";
			CoursesStore[3] = "Data Base";
			CoursesStore[4] = "Operating System";
		}
		else if (StudentdepartmentName == "Business")
		{
			CoursesStore[0] = "Management Studies";
			CoursesStore[1] = "Finance";
			CoursesStore[2] = "Accounting";
			CoursesStore[3] = "Marketing";
			CoursesStore[4] = "Advertisement";
		}
		else if (StudentdepartmentName == "Social Sciences")
		{
			CoursesStore[0] = "History";
			CoursesStore[1] = "Geography";
			CoursesStore[2] = "Political Structures";
			CoursesStore[3] = "Political Science";
			CoursesStore[4] = " Economics";

		}

		int count = 0;
		while (true)
		{

			cout << "Choose Any 3 Courses You Want To Register\n" << endl;
			cout << "1-" << CoursesStore[0] << endl;
			cout << "2-" << CoursesStore[1] << endl;
			cout << "3-" << CoursesStore[2] << endl;
			cout << "4-" << CoursesStore[3] << endl;
			cout << "5-" << CoursesStore[4] << endl;

			cout << "Enter Choice : ";
			cin >> choice;

			if (choice == '1')
			{
				RegisteredCourses[count] = CoursesStore[0];
				count += 1;
			}
			else if (choice == '2')
			{
				RegisteredCourses[count] = CoursesStore[1];
				count += 1;
			}
			else if (choice == '3')
			{
				RegisteredCourses[count] = CoursesStore[2];
				count += 1;
			}
			else if (choice == '4')
			{
				RegisteredCourses[count] = CoursesStore[3];
				count += 1;
			}
			else if (choice == '5')
			{
				RegisteredCourses[count] = CoursesStore[4];
				count += 1;
			}
			if (count == 3)
			{
				if (RegisteredCourses[0] == RegisteredCourses[1] || RegisteredCourses[1] == RegisteredCourses[2] || RegisteredCourses[2] == RegisteredCourses[0])
				{
					system("cls");
					cout << "\t\t\t\tYou Registered Same Course \n \t\t\t\tYou Need To Register Courses Again\n";
					matchCheck = true;
					count = 0;
				}
				else
				{
					matchCheck = false;
					cout << "\t\t\t\tCourse Registration Process is Complete\n";
					break;
				}
			}
		}

	}
	else
	{
		cout << "You Already Registered Courses\n";
	}
	writeRegister.open("RegisteredCourse.txt", ios::app);
	writeRegister << rollNumber << endl;
	for (int i = 0; i < 3; ++i)
	{
		writeRegister << RegisteredCourses[i] << endl;
	}
	writeRegister << endl;

	writeRegister.close();
}




void ViewAssignCourse::viewRegisteredCourse()
{
	read_File.open("StudentTemp.txt");
	read_File >> rollNumber;
	read_File.close();

	{
		readCourseFile.open("RegisteredCourse.txt");

		if (!readCourseFile.is_open())
		{
			writeCourseFile.open("RegisteredCourse.txt");
			writeCourseFile.close();
		}
		readCourseFile.close();

	}
	readCourseFile.open("RegisteredCourse.txt");

	while (getline(readCourseFile, readRollNumber))
	{

		if (readRollNumber == rollNumber)
		{
			for (int i = 0; i < 3; ++i)
			{
				getline(readCourseFile, coursestore[i]);

			}
			break;
		}

	}
	readCourseFile.close();


	if (coursestore[0] != "")
	{
		cout << "\t\t\t\tRegistered Courses" << endl;
		for (int i = 0; i < 3; ++i)
		{
			cout << "\t\t\t\t" << (i + 1) << ") " << coursestore[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "You Not Registered Any Course Yet!\n";
	}
}



void mainMenu()
{
	cout << "<-----------> Welcome To Flex <---------->" << endl;

	cout << " 1) Admin Flex Portal    " << endl;
	cout << " 2) Teacher Flex Portal  " << endl;
	cout << " 3) Student Flex Portal  " << endl;
	cout << " 4) Exit Your Program    " << endl;

}

void adminMenu()
{
	cout << "<----------> Admin Flex Portal <---------->" << endl;

	cout << " 1) Add New Teacher" << endl;
	cout << " 2) Add New Student" << endl;
	cout << " 3) Edit Student Details" << endl;
	cout << " 4) Edit Teacher Details" << endl;
	cout << " 5) View All Students Details" << endl;
	cout << " 6) View  All Teachers Details" << endl;
	cout << " 7) Log out From Account " << endl;
}

void teacherMenu()
{

	cout << "<---------->Teacher Flex Portal<---------->" << endl;

	cout << " 1) Mark Attendence    " << endl;
	cout << " 2) Assign Marks      " << endl;
	cout << " 3) Assign Grades     " << endl;
	cout << " 4) Display Time Table   " << endl;
	cout << " 5) Log out From Account " << endl;
}

void Student_Menu()
{

	cout << "<---------->Student Flex Portal<---------->" << endl;
	cout << " 1) View Marks  " << endl;
	cout << " 2)  View Grades " << endl;
	cout << " 3) View Fee Status " << endl;
	cout << " 4) View Attendence  " << endl;
	cout << " 5) Register Course " << endl;
	cout << " 6) View Register Course" << endl;
	cout << " 7) Log out From Account " << endl;
}


void Captcha()
{
	cout << "\nRecaptcha Time: \n";
	srand(time(0));
	int rand_recaptcha = rand() % 1000;
	cout << rand_recaptcha;
	cout << "\nEnter the above given numbers: ";
	int user_recaptcha;
	cin >> user_recaptcha;
	int count = 1;

	while (true)
	{
		if (user_recaptcha == rand_recaptcha)
		{
			break;
		}
		else
		{
			count++;
			cout << "Invalid input!\n Enter again:\n";
			cin >> user_recaptcha;
		}

		if (count >= 3 && user_recaptcha != rand_recaptcha)
		{
			cout << "You have entered an incorrect captcha 3 times.\nGenerating another captcha:\n";
			srand(time(0));
			rand_recaptcha = rand() % 1000;
			cout << rand_recaptcha;
			cout << " Enter the above given numbers: ";
			cin >> user_recaptcha;
			count = 0;
		}
	}
}

