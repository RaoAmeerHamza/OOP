#include<iostream>
#include"Header.h"

int main()
{
	Admin* adminObject = NULL;
	Teacher* teacherObject = NULL;
	Student* studentObject = NULL;
	char mainChoice;
	char adminChoice;
	char teacherChoice;
	char studentChoice;
	bool check = false;
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;

	//Display Main Menu
	while (true)
	{
		mainMenu();
		cout << "Enter Choice : ";
		cin >> mainChoice;
		if (mainChoice == '1')
		{
			cout << "\t\t\t\tYou Need To Login First\n";
			adminObject = new SignIn;
			adminObject->sign_In();
			Captcha();
			while (true)
			{
				std::system("cls");
				//Display Teacher Menu
				adminMenu();

				cout << "Enter Choice : ";
				cin >> adminChoice;
				switch (adminChoice)
				{
				case'1':
				{
					adminObject = new Add_Teachers();
					adminObject->addTeacher();
					break;

				}
				case'2':
				{
					adminObject = new Add_Student();
					adminObject->addStudent();
					break;

				}
				case'3':
				{
					adminObject = new Edit_Student;
					adminObject->editStudent();
					break;

				}
				case'4':
				{
					adminObject = new Edit_Teacher;
					adminObject->editTeacher();
					break;
				}
				case'5':
				{
					adminObject = new View;
					adminObject->viewAllStudents();
					break;
				}
				case'6':
				{
					adminObject = new View;
					adminObject->viewAllTeacher();
					break;
				}
				case'7':
				{
					check1 = true;
					cout << "You Loged Out\n";
					break;
				}
				default:
				{
					cout << "Invalid Input!\n";
					break;
				}
				}

				//Breaking Admin Loop
				if (check1 == true)
				{
					break;
				}
			}
		}
		else if (mainChoice == '2')
		{
			teacherObject = new Signin;
			teacherObject->signIn();
			Captcha();

			while (true)
			{
				//std::system("cls");

				//Display Teacher Menu
				teacherMenu();

				cout << "Enter Choice : ";
				cin >> teacherChoice;

				switch (teacherChoice)
				{
				case'1':
				{
					teacherObject = new attendance;
					teacherObject->assign_attendance();

					break;

				}
				case'2':
				{
					teacherObject = new Marks;
					teacherObject->assignMarks();
					break;

				}
				case'3':
				{
					teacherObject = new Grades;
					teacherObject->assign_grades();
					break;

				}
				case'4':
				{
					teacherObject = new TimeTable;
					teacherObject->timeTable();
					break;
				}
				case'5':
				{
					check2 = true;
					cout << "You Loged Out\n";
					break;
				}

				default:
				{
					cout << "Invalid Input!\n";
					break;
				}
				}

				//Breaking Teacher Loop
				if (check2 == true)
				{
					break;
				}
			}
		}
		else if (mainChoice == '3')     //Student Module
		{

			studentObject = new Sign_in;
			studentObject->sign_In();
			Captcha();


			while (true)
			{

				Student_Menu();
				//std::system("cls");

				//Display Teacher Menu


				cout << "Enter Choice : ";
				cin >> studentChoice;

				switch (studentChoice)
				{
				case'1':
				{
					studentObject = new View_marks;
					studentObject->viewMarks();

					break;

				}
				case'2':
				{
					studentObject = new ViewGrades;
					studentObject->viewGrades();
					break;

				}
				case'3':
				{
					studentObject = new ViewFeeStatus;
					studentObject->viewFeeStatus();
					break;

				}
				case'4':
				{
					studentObject = new ViewAttendance;
					studentObject->viewAttendance();
					break;
				}
				case'5':
				{
					studentObject = new AssignCourse;
					studentObject->assignCourses();
					break;
				}
				case'6':
				{
					studentObject = new ViewAssignCourse();
					studentObject->viewRegisteredCourse();
					break;
				}
				case'7':
				{
					check3 = true;
					cout << "You Loged Out\n";
					break;
				}
				default:
				{
					cout << "Invalid Input!\n";
					break;
				}
				}
				//Breaking Teacher Loop
				if (check3 == true)
				{
					break;
				}

			}
		}
		else if (mainChoice == '4')
		{
			check = true;
		}

		//Breaking Main Loop
		if (check == true)
		{
			break;
		}
	}


	std::system("pause");
	return 0;
}
