//      
//		Name: Ladinu Chandrasinghe
//		Assignment: Lab 5 - Sorted/Linked List TaskList
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
   head = NULL;
   tail = NULL;
}

TaskLst::TaskLst(const char fileName[])
{
	head = NULL;
   tail = NULL;
	load(fileName);
}

void TaskLst::addItem (const char name[], const char info[], const char date[])
{
   Node *tmpNode = new Node;

      // Set data
   tmpNode-> task.setCourseName(name);
   tmpNode-> task.setTaskinfo(info);
   tmpNode-> task.setDuedate(date);
   tmpNode-> next = NULL;

   if (!head)
     head = tmpNode;

   // connect node to chain
   if (tail) {
     
     //Node *nextNode = NULL;
     Node *walk = NULL;
     char name2[STR_CAP];
     char name3[STR_CAP];
     bool flag = true;
     Node *nextNode = NULL;

     while (flag) {
       getNode(walk);
       nextNode = walk-> next;
       walk-> task.getCourseName(name2);

       if (nextNode == NULL) {
         // Append tmpNode to list
         tmpNode-> next = NULL;
         walk-> next = tmpNode;
         // Move tail
         tail = tmpNode;
         
         flag = false;
       }

       else {
         nextNode-> task.getCourseName(name3);
         if ( (strcmp(name, name2) >=0) and (strcmp(name, name3) <= 0) ) {
           // Insert into linked list
           tmpNode-> next = walk-> next;
           walk-> next = tmpNode;

           flag = false;
         }
       }
     }

     walk = NULL;
     tmpNode = NULL;
     nextNode = NULL;
   }

   else {
     tail = tmpNode;
     tmpNode = NULL;
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

void TaskLst::getNode (Node *&aNode)
{ 
   // point aNode to start of list
  if (aNode == NULL) {
    aNode = head;
  }

  else {
    aNode = aNode-> next;
  }
  
  return;
}

void TaskLst::display()
{ 
   Node *current = NULL;
   getNode(current);

   while (current) {
     // Print task
     cout << "\t" << current-> task << endl;

     getNode(current);
   }

	return;
}

void TaskLst::search()
{
  Node *walk = NULL;
  bool noResult = true;
  char query[STR_CAP];
  char tmp_courseName[STR_CAP];

  readStr(query, "\nEnter course name: ", STR_CAP);
  getNode(walk);

  while (walk != NULL) {
    walk-> task.getCourseName(tmp_courseName);

    if ( strstr(tmp_courseName, query) != NULL) {
      cout << "\t" << walk-> task << endl;
      noResult = false;
    }

    getNode(walk);
  }

  if (noResult) {
    cout << "[-] Coursne name '"
         << query << "'"
         << " was not found"
         << endl << endl;
  }

  walk = NULL;
   
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
   
   else {
     Node *current = NULL;
     getNode(current);

     while (current) {
       // Write last item without newline
       if (current == tail) {
         outFile << current-> task;
       }

       else {
         outFile << current-> task << endl;
       }

       getNode(current);
     }
   }

	return;
}

TaskLst::~TaskLst() {
   // Destroy link
   Node *current = NULL;
   Node *tmpNode = NULL;
   current = head;

   while (current) {
      tmpNode = current;
      current = tmpNode-> next;

      delete tmpNode;
      tmpNode = NULL;

   }

   head = NULL;
   tail = NULL;

}















