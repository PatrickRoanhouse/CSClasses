//      
//		Name: Ladinu Chandrasinghe
//		Assignment: Lab 5 - Sorted/Linked Task List
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
   courseName = NULL;
   taskInfo = NULL;
   dueDate = NULL;

	copyStr(courseName, "unset courseName");
	copyStr(taskInfo, "unset info");
   copyStr(dueDate, "unset dueDate");
}

// Init constructor
Task::Task(const char name[], const char info[], const char date[])
{
   courseName = NULL;
   taskInfo = NULL;
   dueDate = NULL;

   copyStr(courseName, name);
   copyStr(taskInfo, info);
   copyStr(dueDate, date);
}

// get methods
void Task::getCourseName (char retStr[]) const
{
      // #TODO: fix unsafe copy
	strcpy(retStr, courseName);
	return;		
}

void Task::getTaskinfo (char retStr[]) const
{

      // #TODO: fix unsafe copy
	strcpy(retStr, taskInfo);
	return;
}

void Task::getDuedate (char retStr[]) const
{
      // #TODO: fix unsafe copy
	strcpy(retStr, dueDate);
	return;
}

// set methods
void Task::setCourseName (const char name[])
{

	copyStr(courseName, name);
	
	return;
}

void Task::setTaskinfo (const char info[])
{
	copyStr(taskInfo, info);
	return;
}

void Task::setDuedate (const char date[])
{
	copyStr(dueDate, date);
	return;
}

void Task::copy (Task &aTask)
{
	setCourseName(aTask.courseName);
	setTaskinfo(aTask.taskInfo);
	setDuedate(aTask.dueDate);

	return;
}

// copyStr function: safer method to implement strcpy
void Task::copyStr (char *&dataMember, const char inputStr[])
{
  int len = strlen(inputStr) + 1;

  if ( len <= STR_CAP ) {

    if (dataMember) 
      delete [] dataMember;
    
    dataMember = new char [len];
    strcpy(dataMember, inputStr);
  }

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













