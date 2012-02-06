// do not change this file except within the private section

#ifndef BST_H
#define BST_H

#ifndef ROOT
#define ROOT 0
#endif

#include "data.h"
typedef enum {LEAF, FULL, LEFT, RIGHT} Nodetype;
class BST
{
public:
	BST(int capacity = 5);
	BST(const BST& aTable);
	~BST();

	void insert(const data& aData, int index = 0);
	bool remove(const char *key);
	bool retrieve(const char *key, data& aData) const;
	void displayArrayOrder(ostream& out) const;
	void displayPreOrder(ostream& out, int index = 0) const;
	void displayInOrder(ostream& out, int index = 0) const;
	void displayPostOrder(ostream& out, int index = 0) const;
   void displayHeader(ostream& out, const char * type) const;
	int getSize(void) const;						// returns number of data items contained in the BST

private:
	struct item
	{
      item();
		bool	empty;
      data  node;
	};

	item *  items;
   int     itemsIntree;
   int     lstLen;

   void      growLst(int newSize);
   bool      getNodeindex(const char * key, int &index) const;
   Nodetype  getNodetype(int &index) const;
};


#endif
