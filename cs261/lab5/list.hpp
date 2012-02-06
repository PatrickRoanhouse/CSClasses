#ifndef LIST_HPP
#define LIST_HPP
template <class Type>
List<Type>::node::node():object()
{
    next = NULL;
}

template <class Type>
List<Type>::node::~node()
{
    next = NULL;
}

template <class Type>
bool List<Type>::node::equal(const node *r) const
{
    if (r != this)
        return (r -> object == this -> object);
    else
        return true;
}

template <class Type>
bool List<Type>::node::equal(const node &r) const
{
    if (&r != this)
        return (r.object == this -> object);
    else
        return true;
}

template <class Type>
List<Type>::List()
{
    head        = NULL;
    tail        = NULL;
    itemsInlist = 0;
}

template <class Type>
List<Type>::~List()
{
    node * cursor = NULL;
    cursor        = head;
    bool done     = false;
    
    while (!done)
    {
        if (head -> next)
        {
            head   = head -> next;
            delete cursor;
            cursor = head; 
        }
        else
            done = true;
    }
    
    tail   = NULL;
    cursor = NULL;
    delete head;
    head   = NULL;
}

template <class Type>
bool List<Type>::operator==(const List<Type> &r) const
{
    if (&r != this)
    {
        bool equal = true;
        bool flag;
        
        node * cursor1 = this -> head;
        node * cursor2 = r.head;
        
        if (this -> itemsInlist == r.itemsInlist)
            flag = true;
        else
        {
            flag  = false;
            equal = false;
        }
        while (flag)
        {
            if (cursor1 && cursor2)
            {
                if (cursor1->equal(cursor2))
                {
                    cursor1 = cursor1 -> next;
                    cursor2 = cursor2 -> next;
                }
                else
                {
                    equal = false;
                    flag  = false;
                }
            }
            else
                flag = false;
        }
        cursor1 = NULL;
        cursor2 = NULL;
        
        return equal;
    }
    else
        return true;
}

template <class Type>
bool List<Type>::hasDuplicates() const
{
    bool duplicate = false;
    bool flag      = false;
    node * cursor  = head;
    
    while (!flag)
    {
        if (cursor && cursor -> next)
        {
            if (cursor -> equal(cursor -> next))
            {
                duplicate = true;
                flag      = true;
            }
            else
                cursor = cursor -> next;
        }
        else
            flag = true;
    }
    return duplicate;
}

template <class Type>
void List<Type>::insert(const Type &data)
{
    if (!head)
    {
        head = new node();
        tail = head;
        head -> object = data;
    }
    
    else
    {
        node * nodeTobeAdded    = new node();
        nodeTobeAdded -> object = data;
        
        tail -> next = nodeTobeAdded;
        tail         = nodeTobeAdded;
    }
    itemsInlist++;
    return;
}
#endif
