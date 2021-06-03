/***
* Muhammad Ibrahim
* 9 February 2021
* Honor Roll Procedural
***/

#include "Functions.h";

using namespace std;

int main()
{
	vector <string> courseNames;
	vector <int> courseGrades;


	//Input
	//student's full name
	string name;
	cout << "Enter your full name: ";
	getline(cin, name);

	//get the courses information
	int numCourses = getNumCourses();
	courseNames = getCourseNames(courseNames, numCourses);
	courseGrades = getCourseGrades(courseGrades, courseNames);

	int avg = findAverage(courseGrades);

	//output
	cout << endl << endl << endl
		<< name << endl << endl
		<< setw(0) << "Class" << setw(27) << "Grade" << endl;
	for (int i = 0; i < courseNames.size(); i++) {
		cout << setw(0) << courseNames[i] << setw(32 - courseNames[i].length()) << courseGrades[i] << endl;
	}
	cout << "Average: " << avg << endl
		<< "Disciplinary Infraction: ";
	bool b = disciplineIssue();
	if (b)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	//determine if student is eligible
	if (isHonorRoll(courseGrades, avg, b)) {
		cout << "Congratulations, " << name << ", you have made the honor roll." << endl << endl;
	}
	else
		cout << "I'm sorry, " << name << ", but you didn't qualify for the honor roll." << endl << endl;
}