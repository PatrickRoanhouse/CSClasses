#include "list.h"


list::node::node(const winery &awinery)
{
   nextByName     = NULL;
   nextByRating   = NULL;

   item = winery();
   item.copy(awinery);
}

list::list()
{
  headByName      = NULL;
  headByRating    = NULL;
}

list::~list()
{
   node * current = NULL;
   node * next    = NULL;

   current  = headByName;
   next     = current -> nextByName;

   while (next)
   {
      delete current;
      current  = next;
      next     = next -> nextByName;
   }

   if (current)
   {
      delete current;
   }

   current      = NULL;
   next         = NULL;
   headByName   = NULL;
   headByRating = NULL;

}

void list::displayByName(ostream& out) const
{
  node * current  = NULL;
  current = headByName;

  if (current)
  {
    current -> item.displayHeadings(out);

    while (current)
    {
      out << &(current-> item) << endl;
      current = current-> nextByName;
    }
  }

  else
  {
    //out << "No items in lis";
  }

  return;
}

void list::displayByRating(ostream& out) const
{
  node * current  = NULL;
  current = headByRating;
  
  if (current)
  {
    current-> item.displayHeadings(out);

    while (current)
    {
      out << &(current-> item) << endl;
      current = current-> nextByRating;
    }
  }

  else
  {
    //out << "No items in list";
  }

  return;
}

void list::insert(const winery& awinery)
{
   node * tmpNode = new node(awinery);

   if ( headByName && headByRating)
   {
      insertByRating    (tmpNode);
      insertByName      (tmpNode);
   }

   else
   {
      headByName   = tmpNode;
      headByRating = tmpNode;
   }

   tmpNode = NULL;

   return;
}


void list::insertByRating(node *&aNode)
{
   node * current    = NULL;
   node * next       = NULL;
   int aNodeRating, currentRating, nextRating;
   
   aNodeRating = aNode -> item.getRating();
   current     = headByRating;
   next        = current -> nextByRating;
   
      // When only head is in list we only need one comparison
   if ( (current == headByRating) && (!next) )
   {
      currentRating    = headByRating -> item.getRating();
      
      if (currentRating > aNodeRating)
      {
         headByRating -> nextByRating  = aNode;
      }
      
      else if (currentRating < aNodeRating)
      {
         aNode -> nextByRating = headByRating;
         headByRating          = aNode;
      }
      
         // When they both have the same rating
      else
      {
         int aNodeAcres = aNode      -> item.getAcres();
         int headAcres  = headByName -> item.getAcres();
         
         if (aNodeAcres < headAcres)
         {
            headByRating -> nextByRating = aNode;
         }
         
         else
         {
            aNode -> nextByRating = headByRating;
            headByRating          = aNode;
         }
      }
      current = NULL;
   }
   
   while (current)
   {
      if (!next)
      { 
         currentRating   = headByRating -> item.getRating();
         
         if (currentRating < aNodeRating)
         {
            aNode -> nextByRating = headByRating;
            headByRating          = aNode;
         }
         
         else
         {
            current -> nextByRating  = aNode;
         }
         
         current = NULL;
      }
      
      else
      {
         currentRating  = current -> item.getRating();
         nextRating     = next    -> item.getRating();
         
         //#TODO: What about when they are ==
         if ( (aNodeRating < currentRating) && (aNodeRating > nextRating) )
         {
            current -> nextByRating = aNode;
            aNode   -> nextByRating = next;
            
            current = NULL;
         }
         
         else
         {
            current  = next;
            next     = current -> nextByRating;
         }
      }
   }
   
   
   
   return;
}

void list::insertByName(node *&aNode)
{
   node * current    = NULL;
   node * next       = NULL;

   bool nameCmp;
   const char * name    = aNode-> item.getName();
   const char * currName;
   const char * nextName;

   current  = headByName;
   next     = current -> nextByName;

   while (current)
   {
         // When there is only one node in list, you only
         // need one comparison to figure out the order
      if ( (current == headByName) && (!next) )
      {
         const char * headName = current -> item.getName();

         if ( strcmp(name, headName) <= 0 )
         {
            aNode -> nextByName  = current;
            headByName           = aNode;

         }
         else
         {
            current -> nextByName   = aNode;
            aNode   -> nextByName   = NULL;
         }

            // Because only one node was in list
         current  = NULL;
      }

         // When two or more nodes in list
      else
      {
         if (next)
         {
           currName = current -> item.getName();
           nextName = next    -> item.getName();

           nameCmp  = ((strcmp(name, currName) >= 0) &&
                       (strcmp(name, nextName) <= 0));

           if (nameCmp)
           {
               // Insert into list
             aNode      -> nextByName    = next;
             current    -> nextByName    = aNode;

               // Wjen aNode is inseted break from loop
             current = NULL;
           }
           
           else
           {
              current  = next;
              next     = current -> nextByName;
           }
         }

        else
         {
            const char * headName   = headByName -> item.getName();
            if (strcmp(name, headName) <= 0)
            {
               aNode -> nextByName = headByName;
               headByName = aNode;

            }

            else
            {
               current -> nextByName = aNode;
            }

           current = NULL;
         }
      }
   }

   next        = NULL;
   return;
}


winery * const list::find(const char * const name) const
{
   node   * current     = NULL;
   winery * retVal      = NULL;

   current  = headByName;

   while (current)
   {
      if ( strcmp(current-> item.getName(), name) == 0 )
      {
         retVal   = &(current-> item);
         current  = NULL;
      }

      else
      {
         current  = current-> nextByName;
      }
   }

	return retVal;
}

void list::getPrevNode(node *&prev, node *&query, node *&startPoint,int n)
{
   node * current = startPoint;
   prev    = NULL;
   
   while (current)
   {
      if (current == query)
      {
         current = NULL;
      }
      
      else
      {
         prev = current;
         
         if (n == 1)
         {
            current = current -> nextByName;
         }
         else
         {
            current = current -> nextByRating;
         }
      }
   }
   
   
   return;   
}

bool list::remove (const char * const name)
{
	bool   retVal = false; 
   
   node * nodeToDel = NULL;
   node * current   = headByName;
   
      // Find the node to delete
   while (current)
   {
      if (strcmp(current -> item.getName(), name) == 0)
      {
         nodeToDel = current;
         current   = NULL;
      }
      
      else
      {
         current = current -> nextByName;
      }
   }
   
      // If the node is found delete it
   if (nodeToDel)
   {
      node * prevByName    = NULL;
      node * prevByRate    = NULL;
      
      getPrevNode(prevByName, nodeToDel, headByName, 1);
      getPrevNode(prevByRate, nodeToDel, headByRating, 0);
      
      if (prevByName)
         prevByName -> nextByName   = nodeToDel -> nextByName;
      else
         headByName = headByName -> nextByName;
         
      if (prevByRate)
         prevByRate -> nextByRating = nodeToDel -> nextByRating;
      else
         headByRating = headByRating -> nextByRating;

      delete nodeToDel;
      nodeToDel = NULL; 
   }
   

	return retVal;
}
