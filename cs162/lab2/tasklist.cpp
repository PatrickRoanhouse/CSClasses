//      tasklist.cpp
//      
//		Name: Ladinu Chandrasinghe
//		Assignment: Lab 2 - Task List
//		Class: CS162
//      
//      Copyright (C) <2011> by <ladinu@gmail.com>
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

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

const int CAP = 256;
const int CHAR_CAP = 3;
const int STR_CAP = 1024;
const char FILENAME[] = "tasks.txt";

enum Options {ADD_TASK, SHOW_TASKS, FIND_TASK, QUIT};
struct Task {
	
	char courseName[CAP];
	char description[CAP];
	char dueDate[CAP];
};

/** 
 * name: showMenue
 * @param none
 * 
 * This simply displays the main menu
 * @return nonw
 *
*/ 
void showMenu(void);

/** 
 * name: addTask
 * @param list of struct Task and the size of the list
 * 
 * This function prompts for 3 inputs, course name, description and due date
 * the values are then added to a struct in taskList. The size is also incremen-
 * ted.
 * 
 * @return none
 *
*/ 
void addTask(Task taskList[], int &size);

/** 
 * name: showTasks
 * @param taskList and task list size
 * 
 * showTasks simply print each item in task list to the screen,
 * 
 * @return none
 *
*/ 
void showTasks(const Task taskList[], const int &size);

/** 
 * name: findTask
 * @param taskList and task size
 * 
 * This performs a linear search on taskList by the course title
 * 
 * 
 * @return none
 *
*/ 
void findTask(const Task taskList[], const int &size);

/** 
 * name: loadTasks
 * @param task list and size of task lise
 * 
 * This function reads saved tasks from file. The function is called when the
 * user run the program. All the data from file is loaded into taskList.
 * 
 * @return none
 *
*/ 
void loadTasks(Task taskList[], int &size);

/** 
 * name: commit
 * @param taskList and task size
 * 
 * When the user quits the program, this is function is called to save the 
 * taskList on to a file.
 * 
 * @return none
 *
*/ 
void commit(Task taskList[], const int &size);

/** 
 * name: getOption
 * @param none
 * 
 * this function retrives a valid option from the user
 * 
 * @return an option from the enum option
 *
*/ 
Options getOption(void);

/**
 * name: readChar
 * @param Cstring prompt.
 *
 * This will mainly be used get user options when menu is displayed.
 * The input will be red as an array and only the first item in array
 * will be returned. This is because if a user enter "aaaa" cin will only read
 * the first char. If the option was 'q' and ther user enter 'qjdm' it would
 * still be a valid option. To prevent this, input is red into an array and 
 * if more than 1 chars are present in the array, error message is shown. 
 * 
 * The char is converted to lower case before it is returned. So, for example a 
 * valid option can be 'A' or 'a'.
 * 
 * @return a single char
*/
char readChar(const char prompt[]);

/**
 * name: readStr
 * @param Empty array of chars, cstring prompt, and an optional intiger that 
 * determine when to stop reading chars into the input array. By default the
 * capacity is the constant STR_CAP.
 *
 * This will display the prompt and read chars into the input array.
 * 
 * @return none
*/ 
void readStr(char str[], const char prompt[], int cap);

int main() {
	
	Task taskList[CAP];
	Options userOption;
	int size = 0;
	bool quit = false;
	
	// Read tasks from the file
	loadTasks(taskList, size);
	
	cout << "*** Welcome to Task List ***" << endl;
	while (!quit)
	{
		showMenu();
		userOption = getOption();
		
		// Map user options to proper functions
		switch (userOption)
		{
			case ADD_TASK:
				addTask(taskList, size);
				break;
				
			case SHOW_TASKS:
				showTasks(taskList, size);
				break;
				
			case FIND_TASK:
				findTask(taskList, size);
				break;
				
			case QUIT:
				commit(taskList, size);
				quit = true;
				break;
				
			default:
				cout << "[!] ERROR: unknown option" << endl;
				quit = true;
		}
		
	}
	
	return 0;
}

Options getOption(void) {
	
	Options option;
	bool validOption = false;
	
	while (!validOption)
	{
		switch ( readChar("Enter a choice: ") )
		{
			case 'a':
				option = ADD_TASK;
				validOption = true;
				break;
				
			case 's':
				option = SHOW_TASKS;
				validOption = true;
				break;
				
			case 'f':
				option = FIND_TASK;
				validOption = true;
				break;
				
			case 'q':
				option = QUIT;
				validOption = true;
				break;
				
			default:
				cout << "[!] Please enter a valid option" << endl;
		}	
	}
	
	return option;
}

char readChar(const char prompt[]) {
	
	char tmpStr[CHAR_CAP];
	bool inputRed = false;
	
	while (!inputRed)
	{
		cout << prompt;
		cin.get(tmpStr, CHAR_CAP, '\n');
		cin.ignore(CAP, '\n');
		
		if ( !cin.good() )
		{
			cout << "[!] ERROR: could not read character" << endl;
			cin.clear();
			cin.ignore(CAP, '\n');
		}
		
		else
		{
				// Check for multiple chars
			if ( tmpStr[1] )
			{
				cout << "[!] ERROR: You can only enter one character" << endl;
			}
			
			else
			{
				inputRed = true;
			}
		}
	}
	
	return tolower(tmpStr[0]);
}

void readStr(char str[], const char prompt[], int cap = STR_CAP) {
	
	bool inputRed = false;
	
	while (!inputRed)
	{
		cout << prompt;
		cin.get(str, cap, '\n');
		cin.ignore(cap, '\n');
		
			// Check for invalid input
		if ( !cin.good() )
		{
			cout << "[!] Could not read input" << endl;
			cin.clear();
			cin.ignore(cap, '\n');
		}
		
		else
		{
			inputRed = true;
		}
		
	}
		
	return;
}

void showMenu(void) {
	
	cout << "(a) Add task" << endl;
	cout << "(s) Show tasks" << endl;
	cout << "(f) Find task" << endl;
	cout << "(q) Quit" << endl << endl;
	
	return;
}

void addTask(Task taskList[], int &size) {
	
	char courseName[STR_CAP], description[STR_CAP], dueDate[STR_CAP];
	
		// Read task properties
	cout << endl;
	readStr(courseName, "Enter course name: ");
	readStr(description, "Enter task description: ");
	readStr(dueDate, "Enter due date: ");
	cout << endl;
	
		// Add task to list
	strcpy(taskList[size].courseName, courseName);
	strcpy(taskList[size].description, description);
	strcpy(taskList[size].dueDate, dueDate);
	
	size++;
	
	return;
}

void showTasks(const Task taskList[], const int &stopIndex) {
	
	if (stopIndex == 0)
	{
		cout << "[!] No tasks in list" << endl;
		cout << endl;
	}
	
	else
	{
		int i;
		for (i = 0; i < stopIndex; i++)
		{
			cout << i + 1 << ".\t"	//#TODO: format correctly
				 << taskList[i].courseName << ";"
				 << taskList[i].description << ";"
				 << taskList[i].dueDate << endl;
			cout << endl;
		}
		
	}
	
	
	return;
}

void findTask(const Task taskList[], const int &size) {
	
	bool noResult = true;
	char query[STR_CAP];
	readStr(query, "\nEnter course name: ");
	
	for (int i = 0; i < size; i++)
	{
		if ( strcmp(taskList[i].courseName, query) == 0)
		{
			
			cout << taskList[i].courseName << ";"
				 << taskList[i].description << ";"
				 << taskList[i].dueDate;
			cout << endl << endl;
			
			noResult = false;
		}
		
	}
	
	if (noResult)
	{
		cout << "[-] Course name `"
			 << query << "`" 
			 << "was not found" 
			 << endl << endl; 
	}
	
	
	return;
}

void loadTasks(Task taskList[], int &size) {
	
	ifstream file;
	file.open(FILENAME);
	
	if (file.is_open())
	{
		while ( file.good() )
		{
				// Read from file and add to taskList
			file.get(taskList[size].courseName, STR_CAP, ';');
			file.ignore(STR_CAP, ';');
			
			file.get(taskList[size].description, STR_CAP, ';');
			file.ignore(STR_CAP, ';');
			
			file.get(taskList[size].dueDate, STR_CAP, '\n');
			file.ignore(STR_CAP, '\n');
			
			size++;
		}
		
		file.close();
	}
	
	return;
}

void commit(Task taskList[], const int &size)
{
	ofstream outFile;
	outFile.open(FILENAME);
	
	if (!outFile)
	{
		cout << "[!] ERROR: could not open file to save data" << endl;
		cout << "[!] Data was not saved..." << endl;
	}
	
	else
	{
		for (int i = 0; i < size; i++)
		{
			if ( i == (size - 1) )
			{
					// This is used to not add new line on last element
				outFile << taskList[i].courseName << ';'
					<< taskList[i].description << ';'
					<< taskList[i].dueDate;
			}
			
			else
			{
				outFile << taskList[i].courseName << ';'
					<< taskList[i].description << ';'
					<< taskList[i].dueDate << endl;
			}
		}
		
		outFile.close();
	}
	
	return;
}












