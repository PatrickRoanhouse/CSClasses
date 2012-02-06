// make no changes to this file except to have it
// print your own name instead of "Your Name"

// this code enables Visual Studio's memory leak checking.
// Your code should not have memory leaks, and I will be
// testing your code for this in Visual Studio.  The #ifdef
// keeps this code from compiling in non-Windows environments.
// But if you use a non-Windows environment, you are still
// responsible for writing code with no memory leaks.
#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <iostream>
#include "quack.h"

using namespace std;

const static int QUACK_SIZE = 7;

static void push(quack& q, bool front, int n)
{
	bool	ok;

	if (front)
		ok = q.pushFront(n);
	else
		ok = q.pushBack(n);
	cout << ">>> push" << (front ? "Front " : "Back ") << n << (ok ? " succeeded\n" : " failed\n");
}

static void pop(quack& q, bool front)
{
	bool	ok;
	int		n;

	if (front)
		ok = q.popFront(n);
	else
		ok = q.popBack(n);
	cout << ">>> pop" << (front ? "Front " : "Back ");
	if (ok)
		cout << "succeeded: " << n << endl;
	else
		cout << "failed\n";
}

int main (void)
{
	quack	q(QUACK_SIZE);

#ifdef _WIN32
	// request memory leak report in Output Window after main returns
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	cout << "CS260 - Lab2 - Ladinu Chandrasinghe\n";
	cout << q;
	push(q, true, 1);
	push(q, true, 2);
	push(q, true, 3);
	push(q, true, 4);
	push(q, false, 0);
	push(q, true, 9);
	cout << q;
	cout << "--- # of items: " << q.itemCount() << endl << endl;
	pop(q, true);
	cout << q;
	pop(q, true);
	cout << q;
	push(q, false, 7);
	cout << q;
	push(q, false, 8);
	cout << q;
	cout << ">>> rotate(2)\n";
	q.rotate(2);
	cout << q;
	cout << ">>> rotate(-3)\n";
	q.rotate(-3);
	cout << q;
	cout << ">>> reverse\n";
	q.reverse();
	cout << q;
	push(q, true, 6);
	cout << q;
	cout << ">>> rotate(3)\n";
	q.rotate(3);
	cout << q;
	cout << ">>> rotate(-4)\n";
	q.rotate(-4);
	cout << q;
	cout << "--- # of items: " << q.itemCount() << endl << endl;
	while (q.itemCount() > 0) {
		pop(q, false);
		cout << q;
		}
	cout << "--- # of items: " << q.itemCount() << endl << endl;

	return 0;
}
