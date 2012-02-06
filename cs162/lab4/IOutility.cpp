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

#include <IOutility.h>

void showMenu (void)
{
	cout << "(a) Add task" << endl;
	cout << "(s) Show tasks" << endl;
	cout << "(f) Find tasks" << endl;
	cout << "(q) Quit" << endl; 
}


Options getOption(void) {
	
	Options option;
	bool validOption = false;
	
	while (!validOption)
	{
		
		switch ( readChar("Enter a choice: ")  )
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
		cin.ignore(STR_CAP, '\n');
		
		if ( !cin.good() )
		{
			cout << "[!] ERROR: could not read character" << endl;
			cin.clear();
			cin.ignore(STR_CAP, '\n');
		}
		
		else
		{
				// Check for multiple chars
			if ( strlen(tmpStr) != 1 )
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
			// Check for string length
			// Alert user if string is eqal to STR_CAP so-
			// we always have one less (to make 257 -> 256, 101 -> 100 etc.)
			if ( strlen(str) == cap ) {
				cout << "[!] ERROR: Input is too long" << endl;
			}
			
			else {
				// Check for semicolons
				bool flag = false;
				int i = 0;
			
				while (i < strlen(str)) {
				
					if (str[i] == ';') {
						flag = true;
					}
					i++;
				}

				if (!flag) {
					inputRed = true;
				}
				else {
					cout << "[!] Semicolons are not allowed" << endl;
				}
			}
		}
	}
	return;
}
