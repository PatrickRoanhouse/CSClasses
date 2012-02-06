#include "bst.h"
#include <iostream>
#include <iomanip>

using namespace std;

BST::item::item()
{
   empty = true;
   node  = data();
}

BST::BST(int capacity) 
{
   items       = new item[capacity];
   lstLen      = capacity;
   itemsIntree = 0;
}

BST::~BST()
{
   if (items)
     delete [] items;
   items = NULL;
}

void BST::growLst(int newSize)
{
   item * tmpLst = new item[newSize];

   for (int i = 0; i < lstLen; i++)
      tmpLst[i] = items[i];

   if (items)
     delete [] items;

   items  = tmpLst;
   tmpLst = NULL;

   lstLen = newSize;

   return;
}

void BST::insert (const data& aData, int index)
{
  //TODO: Consider growing list more than required amount
  if (itemsIntree == 0)                // Insert the very first item to root
  {
      items[ROOT].node  = aData;
      items[ROOT].empty = false;

      ++itemsIntree;
  }

  else if (items[index].empty)         // Add a leaf (also the base case)
  {
      items[index].empty = false;
      items[index].node  = aData;

      ++itemsIntree;
  }

  else if (aData < items[index].node)  // Insert leftChild
  {
      int leftChildindex = (2*index)+1;

      if (leftChildindex >= (lstLen))
      {
         growLst(leftChildindex+1);
         insert(aData, leftChildindex);
      }

      else
         insert(aData, leftChildindex);
  }

  else if (aData > items[index].node)  // Insert rightChild
  {
      int rightChildindex = (2*index)+2;

      if (rightChildindex >= (lstLen))
      {
         growLst(rightChildindex+1);
         insert(aData, rightChildindex);
      }

      else
        insert(aData, rightChildindex);
  }

  return;
}

bool BST::retrieve(const char *key, data& aData) const
{
    if (itemsIntree > 0)
    {
        int index = ROOT;
        if (getNodeindex(key, index))
        {
            aData = items[index].node;
            return true;
        }

        else
            return false;
    }

    else
        return false;
}

bool BST::remove(const char* key)
{
    int  keyIndex = ROOT;
    bool retval   = false;

    if ( (itemsIntree > 0) && getNodeindex(key, keyIndex) )
    {
        Nodetype type = getNodetype(keyIndex);

        if (type == LEAF)
            items[keyIndex].empty = true;

        else if (type == RIGHT)
        {
                // Copy the right child to the curent node
            int rightChild  = (2 * keyIndex) + 2;
            items[keyIndex] = items[rightChild];
                // Delete the right child
            items[rightChild].empty = true;
        }

        else if (type == LEFT)
        {
                // Copy leftChild to current node, and delete left child
           int leftChild   = (2 * keyIndex) + 1;
           items[keyIndex] = items[leftChild];

           items[leftChild].empty = true;
        }

        else    // type == FULL
        {
            int rightChild   = (2 * keyIndex) + 2;
            int minNodeindex = rightChild; 
            bool flag        = true;
                
                // Find the min value of the right subtree (which will not have left child)
            while (flag)
            {
                int leftChild = (2 * minNodeindex) + 1;

                if ( (leftChild < lstLen) && (!items[leftChild].empty))
                    minNodeindex = leftChild;
                else
                    flag = false;
            }

            items[keyIndex]           = items[minNodeindex];
            items[minNodeindex].empty = true;


        }

        retval = true;
    }

    if (retval)
        --itemsIntree;
    
    return retval;
}


bool BST::getNodeindex(const char * key, int &index) const
{
    bool result;
    Nodetype type  = getNodetype(index);

    if (key == items[index].node)
        result = true;

    else if (type == LEAF)
        result = false;

    else if (type == FULL)
    {
        if (key > items[index].node)
        {
            index  = (2 * index) + 2;
            result = getNodeindex(key, index);
        }
        else
        {
            index  = (2 * index) + 1;
            result = getNodeindex(key, index);
        }
    }

    else if (type == RIGHT)
    {
        if (key > items[index].node)
        {
            index  = (2 * index) + 2;
            result = getNodeindex(key, index);
        }
        else
            result = false;
    }

    else
    {
        if (key < items[index].node)
        {
            index  = (2 * index) + 1;
            result = getNodeindex(key, index);
        }
        else
            result = false;
    }


    return result;
}

void BST::displayArrayOrder (ostream& out) const
{
   displayHeader(out, "array order");
   for (int i = 0; i < lstLen; i++)
   {
      if ( !items[i].empty )
      {
         out << left << setw(25) << items[i].node; // Display name
         out << setw(10);

         if (getNodetype(i) == LEAF)               // Display leaf or not
           out << "leaf";
         else
           out << "    ";
         
         out << i << endl;                         // Display index
      }
   }

  return;
}

void BST::displayPreOrder (ostream& out, int index) const
{
  if ( (index < lstLen) && (itemsIntree > 0))
  {
      if (index == ROOT)
         displayHeader(out, "preorder");

      out << left << setw(25) << items[index].node;
      out << setw(10);

      if ( getNodetype(index) == LEAF )
         out << "leaf" << index << endl;
      else
      {
         out << "    " << index << endl;

         int      rightChild = (2 * index) + 2;
         int      leftChild  = (2 * index) + 1;
         Nodetype nodeType   = getNodetype(index);

         if (nodeType == FULL)
         {
            displayPreOrder(out, leftChild);
            displayPreOrder(out, rightChild);
         }

         else if (nodeType == LEFT)
            displayPreOrder(out, leftChild);

         else if (nodeType == RIGHT)
            displayPreOrder(out, rightChild);
      }
  }
  return;
}

void BST::displayInOrder (ostream& out, int index) const
{
  if ( (index < lstLen) && (itemsIntree > 0))
  {
      int      rightChild = (2 * index) + 2;
      int      leftChild  = (2 * index) + 1;
      Nodetype nodeType   = getNodetype(index);
      
      if (index == ROOT)                  // Display the header
         displayHeader(out, "inorder");
      
      if ( (nodeType == LEFT) || (nodeType == FULL) )    // Travel to the left branch
         displayInOrder(out, leftChild);
         
      out << left << setw(25) << items[index].node;      // Print the current node
      out << setw(10);

      if ( nodeType == LEAF )
         out << "leaf" << index << endl;
      else
         out << "    " << index << endl;

      if ( (nodeType == FULL) || (nodeType == RIGHT) )   // Travel to the right branch
         displayInOrder(out, rightChild);
  }

  return;
}

void BST::displayPostOrder (ostream& out, int index) const
{
   if ( (index < lstLen) && (itemsIntree > 0))
   {
      int      rightChild = (2 * index) + 2;
      int      leftChild  = (2 * index) + 1;
      Nodetype nodeType   = getNodetype(index);

      if (index == ROOT)                                 // Display the header
         displayHeader(out, "postorder");

      if ( (nodeType == LEFT) || (nodeType == FULL) )    // Travel to the left branch
         displayPostOrder(out, leftChild);

      if ( (nodeType == RIGHT) || (nodeType == FULL) )   // Travel to the left branch
         displayPostOrder(out, rightChild);

      out << left << setw(25) << items[index].node;      // Print the current node
      out << setw(10);

      if ( nodeType == LEAF )
         out << "leaf" << index << endl;
      else
         out << "    " << index << endl;
   }

   return;
}

void BST::displayHeader (ostream& out, const char * type) const
{
      // The heading
  out << ">>> " << type << ": " << endl << endl;
  out << setfill(' ') << left
      << setw(25)     << "name"
      << setw(10)     << "leaf?"
      << "index"      << endl;
  out << setfill(' ') << left
      << setw(25)     << "----"
      << setw(10)     << "-----"
      << "-----"      << endl;
  return;
}

Nodetype BST::getNodetype (int &nodeIndex) const
{
  Nodetype type;
  int      rightChild = (2 * nodeIndex) + 2;
  int      leftChild  = (2 * nodeIndex) + 1;

   // Check if both children are out of bound
  if ( (leftChild >= lstLen) && (rightChild >= lstLen) )
      type = LEAF;
   // Check if both children are inbound
  else if ( (leftChild < lstLen) && (rightChild < lstLen) )
  {
      if (items[leftChild].empty && items[rightChild].empty) // When both are empy its a leaf 
         type = LEAF;

      else if ((!items[rightChild].empty && !items[leftChild].empty))  // When both are full
         type = FULL;
      
      else if (items[rightChild].empty)                              // When node has left child
         type = LEFT;

      else if (items[leftChild].empty)                               // Whne node has right child
         type = RIGHT;
  }

  else if ( (leftChild < lstLen) && (rightChild >= lstLen) )
  {
      if ( items[leftChild].empty )
         type = LEAF;
      
      else
         type = LEFT;
  }
  // No nead to check if rightChild is inbound and leftChild is out bound
  // becasue when leftChild is outbound rightChild is automatcally out bound
  return type;
}

int BST::getSize (void) const
{
	return itemsIntree;
}
