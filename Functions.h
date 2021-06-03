#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <vector>

//function prototypes
int getNumCourses(void);
std::vector <std::string> getCourseNames(std::vector<std::string>, int);
std::vector <int> getCourseGrades(std::vector<int>, std::vector<std::string>);
int findAverage(std::vector<int>);
bool disciplineIssue(void);

bool isHonorRoll(std::vector<int>, int, bool);