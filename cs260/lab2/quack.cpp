// add code to these functions to make quack do something useful

#include "quack.h"

quack::quack(int capacity)
{
	front		  = -1;
	back		  = 0;
	count		  = 0;
	lstLen	  = capacity;
	direction  = 1;		// Clockwise
		
	items = new item [capacity];
}

quack::~quack(void)
{
	if (items)
	{
		delete [] items;
		items	= NULL;
	}	
}

bool quack::pushFront(const int n)
{
	item		anItem;
	
	anItem.n	= n;
	count		= count + 1;
	front		= mod((front + direction), lstLen );
	
		// When front "over lap" back, shift back over one
		// Also, decrease count by 1 because new items are not being added
		// to the list. (only existing items get overwritten when count > lstLen)
	if (count > lstLen)
	{
		back	= mod((back + direction), lstLen);
		count = count - 1;
	}
	
	items[front]	= anItem;
	return true;
}

bool quack::pushBack(const int n)
{
	item anItem;
	anItem.n	= n;
	
		// When back "over laps" front, shift front by 1
	if (count >= lstLen)
	{
		back			= front;
		front			= mod((front - direction), lstLen);
		items[back] = anItem;
 	}
 	
	else if (count == 0)
	{
			// When no items in list pushBack and pushFront is the same
			// so just call pushFront
		pushFront(n);	
	}
	
	else
	{
		count		 = count + 1;
		back		 = mod((back - direction), lstLen);
		items	[back] = anItem;
	}
	
	return true;
}

bool quack::popFront(int& n)
{
	bool retVal = true;
	
	if (count != 0)
	{
		n	      = items[front].n;
		front		= mod((front - direction), lstLen);
		count		= count - 1;
	}
	else
	{
			// No items to pop. List is empty
		retVal = false;
	}
	
	return retVal;
}

bool quack::popBack(int& n)
{
	bool retVal = true;
	
	if (count != 0)
	{
		n			= items[back].n;
		back		= mod((back + direction), lstLen);
		count		= count - 1;
	}
	else
	{
			// No items to pop
		retVal = false;
	}
	
	return retVal;
}

void quack::rotate(int r)
{
		// When the list is full, to rotate just move front and back
   if (count == lstLen)
   {
      front    = mod((front + r), lstLen);
      back     = mod((back + r), lstLen);
   }
   
      // Same as popback. If list is big, rotating one by one is very ineficent
   else if (r == (count -1))
   {
      
      //popBack();
   }

   
   else
   {
      int i = 0;
      
         // When input is negative move front and back clockwise
      if ( r < 0)
      {
         while (i > r)
         {
            front        = mod((front + direction), lstLen);
            items[front] = items[back];
            back         = mod((back + direction), lstLen);
            --i;     // because r is negative
         }
         
      }
      
         // When input is non negative, move counter clockwise
      else
      {
         while (i < r)
         {
            back        = mod((back - direction), lstLen);
            items[back] = items[front];
            front       = mod((front - direction), lstLen);
            ++i;
         }
      }
      
   }
	
	return;
}

void quack::reverse(void)
{
		// Change direction (from clockwise to counter clockwise and vice versa)
   direction == 1? direction = -1: direction = 1;
		// reverse front and back
   swap(front, back);
   
	return;
}

int	quack::itemCount(void)
{
	return count;
}

   // This custom modulo deals with negative numbers.
   // Is C++ % the remainder (not modulo) ?
int quack::mod(int a, int b)
{
  int ret = a % b;
  
  if (ret < 0)
    ret = ret + b;

  return ret;
}

ostream& operator<<(ostream& out, quack& q)
{
	// Print the list
	if (q.count == 0)
	{
		out << endl << "quack: empty" << endl << endl;
	}
	
	else
	{
		int i    = q.front;
		out << endl << "quack: ";
		
		while (i != q.back)
		{
			out << q.items[i] << ", ";
			i = q.mod((i - q.direction), q.lstLen);
		}
			
		out << q.items[q.back] << endl << endl;
		
	}
	
	return out;
}

ostream& operator<<(ostream& out, quack::item& i)
{
		// Print struct item
	out << i.n;
	return out;
}
