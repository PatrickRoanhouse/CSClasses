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
   
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

	// Internal options
enum Options {ADD_TASK, SHOW_TASKS, FIND_TASK, QUIT};

	// Program const
#ifndef STR_CAP
#define STR_CAP 256
#endif

#ifndef CHAR_CAP
#define CHAR_CAP 3
#endif


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



#endif
