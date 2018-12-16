#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct Student {
	int id;
	string name;
	int age;
	char gender;
	int level;
	vector<string> courses;
	vector<string> grades;
};

struct Staff {
	int id;
	string name;
	int age;
	char gender;
	string jobTitle;
};

struct Course {
	string code;
	string title;
};


vector<Student> students;
vector<Staff> staff;
vector<Course> courses;

void showCourseOptions();
void showStudentOptions();
void showStaffOptions();

int main()
{
	cout << "SCHOOL MANAGEMENT SYSTEM" << endl << endl;
	cout << "Options:" << endl;
	cout << "1. Courses" << endl;
	cout << "2. Students" << endl;
	cout << "3. Staff" << endl;
	cout << "4. Exit" << endl;
	int c;
	cout << "Enter option: ";
	cin >> c;
	cout << endl;
	switch (c)
	{
	case 1:
		showCourseOptions();
		break;

	case 2:
		showStudentOptions();
		break;

	case 3:
		showStaffOptions();
		break;

	case 4:
		system("pause");
		return 0;
	}

	main();
}

int getCourse(string code) {
	for (int i = 0; i < courses.size(); i++)
	{
		if (strcmpi(courses[i].code.c_str(), code.c_str()) == 0)
			return i;
	}
	return -1;
}
void showCourseOptions() {
	cout << "Course Options:" << endl;
	cout << "1. Add course" << endl;
	cout << "2. Edit course" << endl;
	cout << "3. Delete course" << endl;
	cout << "4. Back" << endl;

	int c;
	cout << "Enter option: ";
	cin >> c;
	cin.ignore();
	cout << endl;
	Course course;
	switch (c) {
	case 1:
		cout << "Enter course code: ";
		getline(cin, course.code);
		cout << "Enter course title: ";
		getline(cin, course.title);
		courses.push_back(course);
		cout << "Course added." << endl;
		break;

	case 2:
	{
		cout << "Enter course code: ";
		getline(cin, course.code);
		int index = getCourse(course.code);
		if (index == -1) {
			cout << "Course not found." << endl;
		}
		else {
			cout << "Enter new course code: ";
			getline(cin, course.code);
			cout << "Enter new course title: ";
			getline(cin, course.title);
			courses[index] = course;
		}
		break;
	}

	case 3:
	{
		cout << "Enter course code: ";
		getline(cin, course.code);
		int index = getCourse(course.code);
		if (index == -1) {
			cout << "Course not found." << endl;
		}
		else {
			courses.erase(courses.begin() + index);
			cout << "Course deleted." << endl;
		}
		break;
	}

	case 4:
		return;
	}

	cout << endl;
	showCourseOptions();
}

int getStudent(int id) {
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].id == id)
			return i;
	}
	return -1;
}
void showStudentOptions() {
	cout << "Course Options:" << endl;
	cout << "1. Add student" << endl;
	cout << "2. Edit student" << endl;
	cout << "3. Delete student" << endl;
	cout << "4. Assign course to student" << endl;
	cout << "5. Record grades" << endl;
	cout << "6. Print academic record" << endl;
	cout << "7. Back" << endl;

	int c;
	cout << "Enter option: ";
	cin >> c;
	cout << endl;
	Student student;
	switch (c)
	{
	case 1:
		cout << "Enter student ID: ";
		cin >> student.id;
		cout << "Enter student name: ";
		cin.ignore();
		getline(cin, student.name);
		cout << "Enter student age: ";
		cin >> student.age;
		cout << "Enter student gender (m/f): ";
		cin.ignore();
		cin >> student.gender;
		cout << "Enter student level: ";
		cin >> student.level;

		students.push_back(student);
		cout << "Student added." << endl;
		break;

	case 2:
	{
		cout << "Enter student ID: ";
		cin >> student.id;
		int index = getStudent(student.id);
		if (index == -1) {
			cout << "Student not found." << endl;
		}
		else {
			cout << "Enter new id: ";
			cin >> student.id;
			cout << "Enter new name: ";
			cin.ignore();
			getline(cin, student.name);
			cout << "Enter age: ";
			cin >> student.age;
			cout << "Enter gender (m/f): ";
			cin.ignore();
			cin >> student.gender;
			cout << "Enter level: ";
			cin >> student.level;

			students[index] = student;
			cout << "Student edited." << endl;
		}
		break;
	}

	case 3:
	{
		cout << "Enter student ID: ";
		cin >> student.id;
		int index = getStudent(student.id);
		if (index == -1) {
			cout << "Student not found." << endl;
		}
		else {
			students.erase(students.begin() + index);
			cout << "Student deleted." << endl;
		}
		break;
	}

	case 4:
	{
		cout << "Enter student ID: ";
		cin >> student.id;
		int index = getStudent(student.id);
		if (index == -1) {
			cout << "Student not found." << endl;
		}
		else {
			cin.ignore();
			cout << "Enter course code to add: ";
			string courseCode;
			getline(cin, courseCode);
			int i = getCourse(courseCode);
			if (i == -1) {
				cout << "Course not found." << endl;
			}
			else {
				student = students[index];
				student.courses.push_back(courses[i].code);
				student.grades.push_back(" ");
				students[index] = student;
				cout << "Course added." << endl;
			}
		}
		break;
	}

	case 5:
	{
		cout << "Enter student ID: ";
		cin >> student.id;
		int index = getStudent(student.id);
		if (index == -1) {
			cout << "Student not found." << endl;
		}
		else {
			cin.ignore();
			cout << "Enter course code: ";
			string courseCode;
			getline(cin, courseCode);
			int i = getCourse(courseCode);
			if (i == -1) {
				cout << "Course not found." << endl;
			}
			else {
				student = students[index];
				cout << "Enter grade: ";
				getline(cin, student.grades[i]);
				students[index] = student;
				cout << "Grade recorded." << endl;
			}
		}
		break;
	}

	case 6:
	{
		cout << "Enter student ID: ";
		cin >> student.id;
		int index = getStudent(student.id);
		if (index == -1) {
			cout << "Student not found." << endl;
		}
		else {
			student = students[index];
			cout << "Name of student: " << student.name;
			cout << endl;
			cout << "COURSE CODE" << "\t" << "GRADE" << endl;
			for (int i = 0; i < student.courses.size(); i++)
			{
				cout << student.courses[i] << "\t\t" << student.grades[i] << endl;
			}
			cout << endl;
			system("pause");
		}
		break;
	}
	case 7:
		return;
	}

	cout << endl;
	showStudentOptions();
}

int getStaff(int id) {
	for (int i = 0; i < staff.size(); i++)
	{
		if (staff[i].id == id)
			return i;
	}
	return -1;
}
void showStaffOptions() {
	cout << "Staff Options:" << endl;
	cout << "1. Add staff" << endl;
	cout << "2. Edit staff" << endl;
	cout << "3. Delete staff" << endl;
	cout << "4. Back" << endl;

	int c;
	cout << "Enter option: ";
	cin >> c;
	cout << endl;
	Staff s;
	switch (c)
	{
	case 1:
		cout << "Enter staff id: ";
		cin >> s.id;
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, s.name);
		cout << "Enter age:";
		cin >> s.age;
		cout << "Enter gender (m/f): ";
		cin.ignore();
		cin >> s.gender;
		cout << "Enter job title: ";
		cin.ignore();
		getline(cin, s.jobTitle);

		staff.push_back(s);
		cout << "Staff added." << endl;
		break;

	case 2:
	{
		cout << "Enter staff id: ";
		cin >> s.id;
		int index = getStaff(s.id);
		if (index == -1) {
			cout << "Staff not found." << endl;
		}
		else {
			cout << "Enter new id: ";
			cin >> s.id;
			cout << "Enter name: ";
			cin.ignore();
			getline(cin, s.name);
			cout << "Enter age:";
			cin >> s.age;
			cout << "Enter gender (m/f): ";
			cin.ignore();
			cin >> s.gender;
			cout << "Enter job title: ";
			cin.ignore();
			getline(cin, s.jobTitle);

			staff[index] = s;
			cout << "Staff details edited." << endl;
		}
		break;
	}

	case 3:
	{
		cout << "Enter staff id: ";
		cin >> s.id;
		int index = getStaff(s.id);
		if (index == -1) {
			cout << "Staff not found." << endl;
		}
		else {
			staff.erase(staff.begin() + index);
			cout << "Staff deleted." << endl;
		}
		break;
	}

	case 4:
		return;
	}

	cout << endl;
	showStaffOptions();
}
