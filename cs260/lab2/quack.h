// you can only change this file by adding items to the "private" section

#pragma once

#include <ostream>

using namespace std;

class quack
{
public:
	quack(int capacity);
	~quack(void);
	bool pushFront(const int n);	// push an item onto the front
	bool pushBack(const int n);		// push an item onto the back
	bool popFront(int& n);			// pop an item off the front
	bool popBack(int& n);			// pop an item off the back
	void rotate(int r);				// "rotate" the stored items (see note below)
	void reverse(void);				// reverse the order of the stored items
	int	itemCount(void);			// return the current number of stored items

private:
	int front;
	int back;
	int count;
	int lstLen;
	int direction;

   int mod(int a, int b);         // custom modulo function

	struct item						// definition of each item stored by the quack
	{
		int		n;
	};
	item		*items;				// pointer to storage for the circular array

public:
	friend ostream& operator<<(ostream& out, quack& q);
	friend ostream& operator<<(ostream& out, quack::item& i);
};

// the following example should make it clear what "rotate" means:
//   quack: 2, 1, 0, 7, 8		-- current contents, front is on the left
//   >>> rotate(2)
//   quack: 0, 7, 8, 2, 1		-- contents after rotation by +2
//   >>> rotate(-3)
//   quack: 8, 2, 1, 0, 7		-- contents after rotation by -3
