#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

	// This convert a given letter to uppercase.
	// Then, updates the occurence of letter in letterCount[] 
void updateLetterCount(char letter, char alphabet[], int letterCount[]);

	// This reads a file given by the use and calls
	// updateLetterCount() for each charachter
void readFile();

	// Display statistics
void dispStats(int count[], char alphabet[]);


const int ALPHA_SIZE = 26;		// English alphabet length

void dispStats(int count[], char alphabet[])
{
	for (int i = 0; i < ALPHA_SIZE; i++)
	{
		cout << alphabet[i] << " " << count[i]
			 << endl;
	}
	
	return;
}


void updateLetterCount(char letter, char alphabet[], int letterCount[])
{
	
		// Check if char letter is a alphabetic char
	if ( isalpha(letter) )
	{
		letter = toupper( letter );		// Convert to uppercase
		
		int i = 0;
		bool notFound = true;
		
		while ( notFound and (i < ALPHA_SIZE) )
		{
			if ( letter == alphabet[i] )
			{
				letterCount[i] += 1;
				
				notFound = false;
			}
			
			i++;
		}
		
	}
	
	return;
}

void processFile()
{
	string fileName;
	ifstream inptFile;
	
	bool flag = true;
	
	while ( flag )
	{
		cout << "[?] Enter path to file: ";
		getline(cin, fileName);
		
		inptFile.open( fileName.c_str() );
		
		if ( inptFile.is_open() )
		{
				// An array of 26 elements, each set to 0
			int letterCount[ALPHA_SIZE] = {0};
			char alphabet[ALPHA_SIZE] = 
					 {'A', 'B', 'C', 'D', 
					  'E', 'F', 'G', 'H', 
					  'I', 'J', 'K', 'L', 
					  'M', 'N', 'O', 'P', 
					  'Q', 'R', 'S', 'T', 
					  'U', 'V', 'W', 'X', 
					  'Y', 'Z'};
			char c;
			
			while ( inptFile.good() )
			{
				c = inptFile.get();
				
				updateLetterCount(c, alphabet, letterCount);
			}
			
			dispStats(letterCount, alphabet);
			
			flag = false;
			
		}
		
		else
		{
			cout << "[!] ERROR: Could not open '"
				 << fileName << "'" << endl;
				 
			cout << endl;
		}
	}
	
	return;
}

int main()
{
	processFile();
	
	return 0;

}
