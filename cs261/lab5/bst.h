#ifndef BST_H
#define BST_H

#ifndef UNLIMITED
#define UNLIMITED -1
#endif

#ifndef STR_CAP
#define STR_CAP 256
#endif

#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;

template <class Type>
class BST
{
public:
    BST(int capacity=UNLIMITED);
    ~BST();
    
    bool insert(const char * const key, const Type &object);
    bool remove(const char * const key, const bool removeDuplicates=false);
    
    bool find(const char * const key, Type &object);
    bool hasDuplicates() const;
    void print() const;
    bool isEmpty() const;
    bool isFull() const;
    
    bool operator==(const BST<Type> &t) const;
    BST<Type>& operator=(const BST<Type> &r);
    //bool equal(const BST<Type> &bst) const;
    
private:
    struct node
    {
        node();
        ~node();
        void setKey(const char * const key);
        void copy(const node *n);
        
        bool lessThan(const node *n) const;
        bool greaterThan(const node *n) const;
        bool operator==(const node &n) const;
        
        char *nodeKey;
        node *leftChild;
        node *rightChild;
        Type data;
    };
    
    node *treeRoot;
    int  treeCapacity;
    int  nodesIntree;
    
    bool removeNode(const char * const key, const bool removeDuplicates=false, node * startNode = NULL);
    
    void destroy(node *aNode);
    
    void printInorder(const node * n) const;
    
    void sortNodekeys(const node * n, List<Type> &list) const;
    
    void copyTree(const node * n);
};
#include "bst.hpp"
#endif

