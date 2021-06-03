#include "Functions.h"

using namespace std;

//method to get the number of courses
int getNumCourses() {
	//list of courses while error checking for strings
	int numCourses;
	cout << "Enter the number of courses you're taking (number between 1 and 8 inclusive): ";
	//error checking the course number
	while (!(cin >> numCourses) || (numCourses < 1 || numCourses > 8)) {
		string garbage;
		cin.clear();
		getline(cin, garbage);
		cout << "Invalid input. "
			<< "Enter a numeric value between 1 and 8 inclusive: ";
	}

	return numCourses;
}

//method to fill the course name vector
vector <string> getCourseNames(vector<string> vstring, int vectorSize) {
	//gather course names
	cout << "Please enter the names of each of your courses (If the course name is larger than 20 characters it will be truncated):" << endl;
	cin.ignore(INT_MAX, '\n');
	//fill the vector with the truncated course names
	for (int i = 0; i < vectorSize; i++) {
		string course;
		cout << "Course " << i + 1 << ": ";
		getline(cin, course);
		//truncate the course name
		if (course.length() > 20)
			course = course.substr(0, 20) + "...";
		//add the course name to the vector
		vstring.push_back(course);
	}

	return vstring;
}

//method to fill the course grades vector
vector<int> getCourseGrades(vector<int> vint, vector<string> vstring) {
	//ask for the grade of each course one by one
	cout << "Enter your grades for each of your courses. Must be a whole number between 0 and 120 inclusive." << endl;
	for (int i = 0; i < vstring.size(); i++) {
		cout << "What is your grade for " << vstring[i] << "? ";
		int grade;
		bool b = true;
		while (b) {
			string input;
			getline(cin, input);

			size_t pos;
			grade = 0;

			//try catch to get the grade input
			try
			{
				grade = stoi(input, &pos);

				if (pos < input.length() || (grade < 0 || grade > 120))
				{
					cout << "Must be a whole number between 0 and 120\n";
					continue;
				}
				else if (grade >= 0 && grade <= 120) {
					b = false;
				}
			}
			catch (exception&)
			{
				cout << "Must be a whole number between 0 and 120\n";
			}
		}
		//add the grade to the vector
		vint.push_back(grade);
	}
	return vint;
}

//method to find the average of the grades
int findAverage(vector <int> grades) {
	double sum = 0;
	for (int i = 0; i < grades.size(); i++) {
		sum += grades[i];
	}
	double size = grades.size();
	double dAvg = sum / size;

	//rounding
	int avg = round(dAvg);
	return avg;
}

//method to determine discipline issue
bool disciplineIssue() {
	bool hasDisciplineIssue;
	srand((unsigned)time(0));

	int num = (rand() % 20) + 1;
	if (num == 1) {
		hasDisciplineIssue = true;
	}
	else {
		hasDisciplineIssue = false;
	}
	return hasDisciplineIssue;
}

//method to determine if the student is in the honor roll
bool isHonorRoll(vector <int> grades, int avg, bool discipline) {
	if (!discipline && avg >= 90 && grades.size() >= 5)
		return true;
	else
		return false;

}