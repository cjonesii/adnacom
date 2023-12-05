#include <iostream>
#include <vector>
#include <string>

class Student {
public:
	std::string name;
	int age;
};

void clear_screen()
{
  std::cout << "\033[2J";    // clear the screen
  std::cout << "\033[1;1H";  // move cursor home
}

Student * findOldestStudent(const std::vector<Student *> &students)
{
	Student * oldest = students[0];
	for (const auto &student : students) {
		if (student->age > oldest->age) {
			oldest = student;
		}
	}
	return oldest;
}

void displayStudents(const std::vector<Student *> &students)
{
	for (const auto &student : students) {
		std::cout << "Name: " 
			<< student->name << ", Age: " 
			<< student->age << std::endl; 
	}
}

void addStudent(std::vector<Student *> &students)
{
	Student *newStudent = new Student; 
	std::cout << "Enter student name: ";
	std::cin >> newStudent->name;
	std::cout << "Enter student age: ";
	std::cin >> newStudent->age;
	students.push_back(newStudent);
}

int main(int argc, char *argv[])
{
	std::cout << "Students List" << std::endl;
	std::vector<Student *> students;
	char choice;

	do {
		std::cout << "1. Add a student\n" 
							<< "2. Display all students\n"
							<< "3. Find the oldest student\n"
							<< "4. Exit\nEnter your choice: ";
		std::cin >> choice;

		switch (choice) {
			case '1':
				addStudent(students);
			break;
			case '2':
				displayStudents(students);
			break;
			case '3':
				Student *oldestStudent;
				oldestStudent = findOldestStudent(students);
				std::cout << "Oldest Student: " 
									<< oldestStudent->name 
									<< ", Age: " << oldestStudent->age 
									<< std::endl;
			break;
			case '4':
				std::cout << "Exiting program." << std::endl;
			break;
			default:
				clear_screen();
				std::cout << "Invalid choice." << std::endl;
				std::cout << std::endl;
			;
		}
	} while (choice != '4');

	return 0;
}