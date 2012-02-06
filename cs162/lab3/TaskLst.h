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

#ifndef TASKLST_H
#define TASKLST_H 

#ifndef LST_CAP
#define LST_CAP 50
#endif

#include "Task.h"
#include "IOutility.h"
#include <fstream>
#include <iomanip>
using namespace std;

class TaskLst 
{
	public:
		TaskLst ();
		TaskLst(const char fileName[]);

		// Mutators
		void addItem(const char name[], const char info[], const char date[]);
		void addItem();
		void load(const char fileName[]);
		void commit(const char fileName[]);
		
		// Read only
		void display();
		void search();

		
	private:
		int size;
		Task taskLst[LST_CAP];
};
#endif
