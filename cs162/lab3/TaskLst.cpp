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

#include "TaskLst.h"

TaskLst::TaskLst()
{
	size = 0;
}

TaskLst::TaskLst(const char fileName[])
{
	size = 0;
	load(fileName);
}

void  TaskLst::addItem(const char name[], const char info[], const char date[])
{
	if (size < LST_CAP) {
		taskLst[size].setCourseName(name);
		taskLst[size].setTaskinfo(info);
		taskLst[size].setDuedate(date);

		size++;
	}

	else {
		cout << "[!] Task list is full" << endl;
	}
	
	return;
}

void TaskLst::addItem ()
{
	char tmp_courseName[STR_CAP];
	char tmp_taskInfo[STR_CAP];
	char tmp_dueDate[STR_CAP];

	readStr(tmp_courseName, "\nEnter course name: ", STR_CAP);
	readStr(tmp_taskInfo, "Enter task info: ", STR_CAP);
	readStr(tmp_dueDate, "Enter due date: ", STR_CAP);
		
	addItem(tmp_courseName, tmp_taskInfo, tmp_dueDate);
	
	return;
}

void TaskLst::display()
{
	if (size > 0) {
		
		int i;

		for (i = 0; i < size; i++) {
			
			cout << "\t" << taskLst[i] << endl;
		}
	}

	else {
		cout << "[!] No items in list" << endl << endl;
	}
	
	return;
}

void TaskLst::search()
{
	
	bool noResult = true;
	char query[STR_CAP];
	char tmp_courseName[STR_CAP];

	readStr(query, "\nEnter course name: ", STR_CAP);
	
	for (int i = 0; i < size; i++)
	{
		taskLst[i].getCourseName(tmp_courseName);
		
		if ( strstr(tmp_courseName, query) != NULL)
		{
			cout << "\t" << taskLst[i] << endl;
			noResult = false;
		}
		
	}
	cout << endl;
	
	if (noResult)
	{
		cout << "[-] Course name `"
			 << query << "`" 
			 << "was not found" 
			 << endl << endl; 
	}

	return;
}

void TaskLst::load (const char fileName[])
{
	ifstream file;
	file.open(fileName);
	
	
	if (file.is_open())
	{
		char tmp_courseName[STR_CAP];
		char tmp_taskInfo[STR_CAP];
		char tmp_dueDate[STR_CAP];
	
		while ( file.good() )
		{
			// Read from file and add to taskList
			file.get( tmp_courseName, STR_CAP, ';' );
				file.ignore( STR_CAP, ';' );

			file.get( tmp_taskInfo, STR_CAP, ';' );
				file.ignore( STR_CAP, ';' );

			file.get( tmp_dueDate, STR_CAP, '\n' );
				file.ignore( STR_CAP, '\n' );
			
			// Add to list
			addItem(tmp_courseName, tmp_taskInfo, tmp_dueDate);
		}
		
		file.close();
	}

	else {
		cout << "[!] ERROR: Could not read data from " << fileName<< endl;
	}

	return;
}

void TaskLst::commit(const char fileName[])
{
	
	ofstream outFile;
	outFile.open(fileName);
	
	if (!outFile)
	{
		cout << "[!] ERROR: could not open file to save data" << endl;
		cout << "[!] Data was not saved..." << endl;
	}
	
	else
	{
		int i;
	
		for (i = 0; i < size; i++)
		{
			if (i == (size - 1) ) {
				outFile << taskLst[i];
			}

			else {
				outFile << taskLst[i] << endl;
			}
		}

		outFile.close();
	}

	return;
}















