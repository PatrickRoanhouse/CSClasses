//    table.cpp
//
//		Name: Ladinu Chandrasinghe
//		Assignment: 1
//		Class: CS261
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
using namespace std;

// Displaya welcome message and show instructions
void displayIntro();

// Get a number from user input. This will also check for valid input.
int getNum();


int main()
{
  int num;

  displayIntro();
  num = getNum();

  // Print the header (top) row
  cout << " ";
  for (int j=0; j <= num; j++)
  {
    cout << setfill(' ') << setw(5) << right << j;
  }

  cout << endl;

  // Print the multiplication table
  for (int i=0;i <= num;i++)
  {
    cout << left << setw(5)<< i;  // This is the left most colum of the table
    for (int n=0; n <=num; n++)
    {
      cout << setw(5) << left << n*i;
    }
    cout << endl;
  }

return 0;
}

int getNum()
{
  int  num;
  bool validInput = false;

  while (!validInput)
  {
    cout << "Enter a number: ";
    cin  >> num;

    if (num <=12 && num >=4)
      validInput = true;
    else
    {
      cout << "[!] Must be a number and between 4 and 12 inclusive" << endl;
      cin.clear();
      cin.ignore(1024, '\n');
    }
  }

  return num;
}

void displayIntro()
{
  cout << "***Welcome to Multiplication Table Generator***" << endl;
  cout << "You can enter a number between 4 and 12 (inclusive)" << endl;
  return;
}
