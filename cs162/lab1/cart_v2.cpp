//      cart_v2.cpp
//
//		Name: Ladinu Chandrasinghe
//		Assignment: Lab 1 - Shopping Cart
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
#include <cstring>
using namespace std;

const int STR_CAP = 256;
const int CART_CAP = 100;
const int CHAR_CAP = 3;

enum Options {ADD_ITEM, SHOW_CART, CHECKOUT, YES, NO};

struct Cart {
	
	char name[STR_CAP];
	double price;
	// int tax;
	// double barcode;
	// other
};


/** 
 * name: readDouble
 * @param Cstring prompt.
 * @return Returns a double.
 *
*/ 
double readDouble(const char prompt[]);

/**
 * name: readStr
 * @param Empty array of chars, cstring prompt, and an optional intiger that 
 * determine when to stop reading chars into the input array. By default the
 * capacity is the constant STR_CAP 
 *
 * This will display the prompt and read chars into the input array.
 * 
 * @return none
*/ 
void readStr(char str[], const char prompt[], int cap);

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
 * name: showMenu
 * @param A double that is the cart total
 *
 * Display the main menu, and display the cart total as the header.
 * 
 * 
 * @return none
*/
void showMenu(const double &cartTotal);

/**
 * name: addItem
 * @param Array of struct Cart, a double that is the total value, and an int
 * that is the number of occupied slots in the array of structs.
 *
 * Adds an item to the cart, compute the total value, and increment the
 * number of slots left in the cart. Item properties such as Item price and name
 * is retrived from within the function.
 * 
 * 
 * @return none
*/
void addItem(Cart [], double &total, int &size);

/**
 * name: showCart
 * @param Struct item array, and an int that is the number of items in the
 * array and a double that is the cart total
 *
 * This function simply iterate trhough the array and prints item information 
 * to the screeen. It also prints out the grand total.
 * 
 * @return none
*/
void showCart(Cart [], const int &itemsInCart);

/**
 * name: getOption
 * @param none
 *
 * This function retrives a valid option from the user.
 * 
 * @return An enum of Option type.
*/
Options getOption();

/**
 * name: confirmItem
 * @param none
 *
 * This function ask user to confirm.
 * 
 * @return An enum of Option YES or NO.
*/
Options confirmItem();


Options confirmItem(void) {
	
	bool validInput = false;
	char choice;
	Options retVal;
	
	while (!validInput)
	{
		choice = readChar("Add item to cart? (y/n): ");
		
		if (choice == 'y')
		{
			retVal = YES;
			validInput = true;
		}
		
		else if ( choice == 'n' )
		{
			retVal = NO;
			validInput = true;
		}
		
		else
		{
			cout << "[!] ERROR: Please enter 'y' or 'n'" << endl;
		}
	}
	
	return retVal;
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

double readDouble(const char prompt[]) {
	
	double tmpDbl;
	bool inputRed = false;
	
	while (!inputRed)
	{
		cout << prompt;
			cin  >> tmpDbl;
		cin.ignore(STR_CAP, '\n');
			
		if ( !cin.good() )
		{
			cout << "[!] ERROR: You must enter a number" << endl;
			cin.clear();
			cin.ignore(STR_CAP, '\n');
		}
		
		else
		{
			inputRed = true;
		}
	}
	
	return tmpDbl;
}

void readStr(char str[], const char prompt[], int cap = STR_CAP) {
	
	bool inputRed = false;
	
	while (!inputRed)
	{
		cout << prompt;
			cin.get(str, cap, '\n');
		cin.ignore(STR_CAP, '\n');
		
			// Check for invalid input
		if ( !cin.good() )
		{
			cout << "[!] Could not read input" << endl;
			cin.clear();
			cin.ignore(STR_CAP, '\n');
		}
		
		else
		{
			inputRed = true;
		}
		
	}
		
	return;
}

void showMenu(const double &cartTotal) {
	
	cout << endl
		 << "----- Cart Total: $" << cartTotal 
		 << " ------" << endl
		 << "(a) Add item" << endl
		 << "(s) Show cart" << endl
		 << "(q) Check out" << endl;
	return;
}

void addItem(Cart cart[], double &cartTotal, int &itemsInCart) {
	
		// Check if room is in cart
	if ( itemsInCart < CART_CAP )
	{
		int index = itemsInCart;
		char name[STR_CAP];
		Options confirmed;
		double price;
		
			// Header
		cout << endl;
		cout << "------- Add Item -------" << endl;
		
			// Read name and price
		readStr(name, "Enter item name: ");
		price = readDouble("Enter item price: ");
		
			// Echo item back to user
		cout << endl
			 << "------- Confirm Item -------" 
			 << endl
			 << "Item name: " << name 
			 << endl
			 << "Item price: $" << price 
			 << endl
			 << "Cart total: $" << cartTotal + price 
			 << endl
			 << endl;
		
			// Confirm item
		confirmed = confirmItem();
		
		if ( confirmed == YES )
		{
				// Add item to cart
			strcpy( cart[index].name, name);
			cart[index].price = price;
			
				// Increment items in cart and update cartTotal
			cartTotal += price;
			++itemsInCart;
		}
	}
	
	else
	{
		cout << "[!] No more room in cart. Please check out" << endl;
	}
	
	return;
}

Options getOption(void) {
	
	Options option;
	bool validOption = false;
	
	while (!validOption)
	{
		switch ( readChar("\nEnter a choice: ") )
		{
			case 'a':
				option = ADD_ITEM;
				validOption = true;
				break;
				
			case 's':
				option = SHOW_CART;
				validOption = true;
				break;
				
			case 'q':
				option = CHECKOUT;
				validOption = true;
				break;
				
			default:
				cout << "[!] Please enter a valid option" << endl;
		}	
	}
	
	return option;
}

void showCart(Cart cart[], const int &itemsInCart) {
	
	int stopIndex = itemsInCart;
	
	cout << endl << "----- Items in Cart ------" << endl;
	
	if (stopIndex == 0)
	{
		cout << endl
				<< "[!] The cart is empty. Please add items." << endl;
	}
	
	else
	{
		for (int i = 0; i < stopIndex; i++)
		{
			cout << i + 1 << ") "
				 << cart[i].name 
				 << "\t $" << cart[i].price 
				 << endl;
		}
		
		cout << endl;
		
	}
	
	return;
}



int main(int argc, char **argv) {
	
	double cartTotal = 0.0;
	int itemsInCart = 0;
	
	Options userOption;
	Cart cart[CART_CAP];
	
	bool checkOut = false;
	
		// Set proper output properties for currency
		// This is copied from Lab 1 specifications
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << endl << "*** Welcome to the shopping cart ***" << endl;
	
	while (!checkOut)
	{
		showMenu(cartTotal);
		userOption = getOption();
		
			// Map user option to function
		switch (userOption)
		{
			case ADD_ITEM:
				addItem(cart, cartTotal, itemsInCart);
				break;
				
			case SHOW_CART:
				showCart(cart, itemsInCart);
				break;
				
			case CHECKOUT:
				checkOut = true;
				// show grand total
				showCart(cart, itemsInCart);
				cout << "*** Grand Total: $" << cartTotal 
					 << " ***" << endl;
				break;
				
			default:
				cout << "ERROR: main() -> unknown userOption" << endl;
				checkOut = true;
		}
	}
	
	return 0;
}


























