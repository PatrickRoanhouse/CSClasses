#ifndef LIST_H
#define LIST_H

#include <cstring>

template <class Type>
class List
{
public:
    List();
    ~List();
    void insert(const Type &t);
    bool operator==(const List &r) const;
    bool hasDuplicates() const;
    
   
private:
    struct node
    {
        node();
        ~node();
        
        bool equal(const node * r) const;
        bool equal(const node &r) const;
        
        node * next;
        Type object;
    };
    
    node * head;
    node * tail;
    int itemsInlist;
};
#include "list.hpp"
#endif
