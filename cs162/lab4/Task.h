//      
//		Name: Ladinu Chandrasinghe
//		Assignment: Lab 4 - Task List with dynamic arrays
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

#ifndef TASK_H
#define TASK_H 

#ifndef STR_CAP
#define STR_CAP 256
#endif

#include <iostream>
#include <cstring>
using namespace std;

class Task 
{
	
	friend ostream &operator<< (ostream &stream, Task &aTask);
	
	public:
		// Constructors
		Task ();
		Task (const char name[], const char info[], const char date[]);
			
		// Readonly methods
		void getCourseName (char retStr[]) const;
		void getTaskinfo (char retStr[]) const;
		void getDuedate (char retStr[]) const;

		// Mutator methods
		void setCourseName (const char name[]);
		void setTaskinfo (const char info[]);
		void setDuedate (const char date[]);

		void copy(Task &aTask);

		~Task();

	private:
		char *courseName;
		char *taskInfo;
		char *dueDate;
};


#endif
