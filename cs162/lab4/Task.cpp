//      
//		Name: Ladinu Chandrasinghe
//		Assignment: Lab 3 - Task List w/ classes
//		Class: CS162
//      
//              Copyright (C) <2011> by <ladinu@gmail.com>
//
//		Permission is hereby granted, free of charge, to any person obtaining a copy
//		of this software and associated documentation files (the "Software"), to deal
//		in the Software without restriction, including without limitation the rights
//		to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//		copies of the Software, and to permit persons to whom the Software is
//		furnished to do so, subject to the following conditions:
//		
//		The above copyright notice and this permission notice shall be included in
//		all copies or substantial portions of the Software.
//		
//		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//		IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//		FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//		AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//		LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//		OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//		THE SOFTWARE.  
//

#include "Task.h"

// Default task properties
Task::Task()
{
	courseName = new char [strlen("no name")+1];
	taskInfo = new char [strlen("no info")+1];
	dueDate = new char [strlen("no date")+1];
	
	strcpy(courseName, "no name");
	strcpy(taskInfo, "no info");
	strcpy(dueDate, "no date");
}

// Init constructor
Task::Task(const char name[], const char info[], const char date[])
{
	courseName = new char [strlen(name)+1];
	taskInfo = new char [strlen(info)+1];
	dueDate = new char [strlen(date)+1];

	strcpy(courseName, name);
	strcpy(taskInfo, info);
	strcpy(dueDate, date);
}

// get methods
void Task::getCourseName (char retStr[]) const
{
	strcpy(retStr, courseName);
	return;		
}

void Task::getTaskinfo (char retStr[]) const
{
	strcpy(retStr, taskInfo);
	return;
}

void Task::getDuedate (char retStr[]) const
{
	strcpy(retStr, dueDate);
	return;
}

// set methods
void Task::setCourseName (const char name[])
{
	if (courseName)
		delete [] courseName;

	courseName = new char [strlen(name) + 1];
	strcpy(courseName, name);
	
	return;
}

void Task::setTaskinfo (const char info[])
{
	if (taskInfo)
		delete [] taskInfo;
	
	taskInfo = new char [strlen(info)+1];
	strcpy(taskInfo, info);

	return;
}

void Task::setDuedate (const char date[])
{
	if (dueDate)
		delete [] dueDate;

	dueDate = new char [strlen(date)+1];

	strcpy(dueDate, date);
	return;
}

void Task::copy (Task &aTask)
{
	setCourseName(aTask.courseName);
	setTaskinfo(aTask.taskInfo);
	setDuedate(aTask.dueDate);

	return;
}

//Overloaded stream for output
ostream &operator<< (ostream &stream, Task &aTask)
{
	stream << aTask.courseName << ";"
			 << aTask.taskInfo << ";" 
			 << aTask.dueDate;

	return stream;
}

Task::~Task() {

	if (courseName) {
		delete [] courseName;
		courseName = NULL;
	}

	if (taskInfo) {
		delete [] taskInfo;
		courseName = NULL;
	}

	if (dueDate) {
		delete [] dueDate;
		dueDate = NULL;
	}
}













