#include <iostream>
#include <string>

using namespace std;

enum options {QUIT, CNVRT_TO_SMS, CNVRT_TO_ENGlISH, LOWER, NONE};

	// Restore the cli input stream
void restoreStream();

	// The two main functions
void cnvrtToSMS();
void cnvrtToEnglish();

void preProccess(string &inputString, options textCase);
bool isPunct(char item);
	
	// Present simple cli menue
options getOption();

	// Replace regular expressions w/ substitute on the input string
void replace( string &inputString, string regExp, string substitute );




void restoreStream()
{
	cin.clear();
	cin.ignore(100, '\n');
}

bool isPunct(char item)
{
	bool isItemPunct;
	
	switch ( item )
	{
		case '(':
		case '.':
		case '-':
		case ',':
		case '!':
		case ';':
		case '_':
		case ':':
		case '}':
		case '{':
		case '?':
		case '[':
		case ']':
		case '/':
		case '"':
		case '\\':
		case '\'':
		case ')':
			isItemPunct = true;
			break;
			
		default:
			isItemPunct = false;
			
	}
	
	return isItemPunct;
	
}

void preProccess(string &text, options textCase)
{
	int len = static_cast<int>( text.length());
	
	for (int i = 0; i < len;)
	{
			// Convert to lowercase
		text[i] = static_cast<char> ( tolower(text[i]) );
		
			// Remove punctuations
		if ( ( isPunct(text[i]) ) && (textCase == LOWER) )
		{
			text.erase(i, 1);
				
				// Reset loop vars because string.erase() resets length of string
			len = static_cast<int>( text.length());
			
			if ( i not_eq 0)
			{
				i--;
			}
		}
		
		else
		{
			i++;
		}
		
	}
	
}
	// Present a simple menue and retrive user options
options getOption()
{
	int choice;
	bool invalidChoice = true;
	options retChoice;
	
	cout << "------------ Welcome to SMS <--> English translator"
		 << "------------" 
		 << endl;
	
	while ( invalidChoice )
	{
		cout << "[ 1 ] Translate English to SMS" << endl
			 << "[ 2 ] Translate SMS to English" << endl
			 << "[ 3 ] Quit" << endl;

		cout << "Please enter an option (1/2/3): ";	 
			cin >> choice;
		
		if ( cin.peek() == 10 )	// This check weather choice is an intiger
		{
			switch ( choice )
			{
				case 1:
					retChoice = CNVRT_TO_SMS;
					invalidChoice = false;
					break;
					
				case 2:
					retChoice = CNVRT_TO_ENGlISH;
					invalidChoice = false;
					break;
					
				case 3:
					retChoice = QUIT;
					invalidChoice = false;
					break;
					
				default:
					cout << endl;
					cout << "[!] ERROR: Invalid option <---" << endl;
					cout << endl;
					//restoreInput();	// #TODO: is this needed?
					
			}
			
		}
		
		else
		{
			cout << endl;
			cout << "[!] ERROR: You must enter an intiger value <---" << endl;
			cout << endl;
			
			restoreStream();
		}
		
	}
	
	return retChoice;
	
}
	// Looks a lot nicer if done w/ string.erase() or string.replace()
	// but i wanted to see what life was like just using string.substr()
	// and string.find()
void replace( string &inputString, string regExp, string substitute )
{
	string::size_type inpStrLen = inputString.length();
	string::size_type regExpLen = regExp.length();
	string::size_type regExp_loc;
	
	string tmpStr;
	bool regExp_found = true;
	
		// Search input and replace regExp w/ substitute untill no regExps
	while ( regExp_found )
	{
		regExp_loc = inputString.find( regExp );
		
		if ( regExp_loc != string::npos )
		{
				// Make a temporary string that is every char untill regExp location
				// Then add substitute word/phrase to tmp string	
			tmpStr = inputString.substr(0, regExp_loc);
			tmpStr += substitute;
			
				// Add every thing after regExp to tempString
			tmpStr += inputString.substr( (regExpLen + regExp_loc), 
										   inpStrLen );
										  
			inputString = tmpStr;
		}
		
		else
		{
			regExp_found = false;
		}
		
	}
	
}

void cnvrtToSMS()
{
	string text;
	
	restoreStream();	// See line 151
	
	getline(cin, text);
	
	preProccess(text, LOWER);
	
		// Dictionary
	replace(text, "see you", "c u");
	replace(text, "talk to you later", "ttyl");
	replace(text, "be right back", "brb");
	replace(text, "by the way", "btw");
	replace(text, "best friends forever", "bff");
	replace(text, "for what it's worth", "fwiw" );
	replace(text, "great", "gr8");
	replace(text, "in my humble opinion", "imho");
	replace(text, "later", "l8r");
	replace(text, "on my way", "omw");
	replace(text, "no problem", "np");
	replace(text, "too much information", "tmi");
	replace(text, "wish you were here", "wywh");
		
	cout << "\n-------------- Translation --------------" << endl;
	cout << text << endl;
	return;
}

void cnvrtToEnglish()
{
	string text;
		
	restoreStream();	// For some reaseon the newline is still in input buffer 
						// w/o restoreStream i would have to type getline twice
	getline(cin, text);
	preProccess(text, NONE);
	
		// All the things to convert
	replace(text, "c u", "see you");
	replace(text, "ttyl", "talk to you later");
	replace(text, "brb", "be right back");
	replace(text, "btw", "by the way");
	replace(text, "bff", "best friends forever");
	replace(text, "fwiw", "for what it's worth");
	replace(text, "gr8", "great");
	replace(text, "imho", "in my humble opinion");
	replace(text, "l8r", "later");
	replace(text, "omw", "on my way");
	replace(text, "np", "no problem");
	replace(text, "tmi", "too much information");
	replace(text, "wywh", "wish you were here");
	
	cout << "\n-------------- Translation --------------" << endl;
	cout << text << endl;
	return;
}


int main()
{
	options userChoice;
	
	userChoice = getOption();
	
		// Map user selected options to functions
	switch ( userChoice )
	{
		case QUIT:
			cout << endl;
			cout << "[-] EXiting..." << endl;
			break;
			
		case CNVRT_TO_SMS:
			cout << "Enter text to convert to SMS: " << endl;
			cnvrtToSMS();
			break;
			
		case CNVRT_TO_ENGlISH:
			cout << "Enter SMS to convert to english: " << endl;
			cnvrtToEnglish();
			break;
			
		default:
			cout << "[!] Unknown error..." << endl;
			
	}
	
	return 0;
}
