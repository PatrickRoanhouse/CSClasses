// make NO CHANGES to this file

#ifndef _WINERY_
#define _WINERY_

#include <ostream>
#include <cstring>

class winery
{
public:
	winery(const char * const name, const char * const location, const int acres, const int rating);
   winery();
   void  copy(const winery &Awinery);
	virtual ~winery(void);
	const char * const getName() const;
	const char * const getLocation() const;
	const int getAcres() const;
	const int getRating() const;

	// display headings for lists of wineries
	static void displayHeadings(std::ostream& out);

	friend std::ostream& operator<<(std::ostream& out, winery *w);

private:
	char	*name;
	char	*location;
	int		acres;
	int		rating;

   // A safer strcpy method
   void copyStr(char *&dataMem, const char * const inputStr);
};

#endif // _WINERY_
