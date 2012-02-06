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

#include "IOutility.h"
#include "TaskLst.h"

int main ()
{
	
	TaskLst list;
	// Read fata from db
	list.load("tasks.txt");

	Options userOption;
	bool quit = false;
	
	
	cout << "*** Welcome to Task List ***" << endl;
	while (!quit)
	{
		showMenu();
		userOption = getOption();
		
		// Map user options to proper functions
		switch (userOption)
		{
			case ADD_TASK:
				list.addItem();	
				break;
				
			case SHOW_TASKS:
				list.display();
				break;
				
			case FIND_TASK:
				list.search();
				break;
				
			case QUIT:
				list.commit("tasks.txt");
				quit = true;
				break;
				
			default:
				cout << "[!] ERROR: unknown option" << endl;
				quit = true;
		}
		
	}

	return 0;
}














