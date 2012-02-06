#ifndef BST_HPP
#define BST_HPP

template <class Type>
BST<Type>::node::node():data()
{
    nodeKey    = NULL;
    leftChild  = NULL;
    rightChild = NULL;
}

template <class Type>
void BST<Type>::node::setKey(const char * const key)
{
    int len = static_cast<int>(strlen(key)+1);   // extra byte for NULL
    
    if (len <= STR_CAP)
    {
        if (nodeKey)
            delete [] nodeKey;
        nodeKey = new char [len];
        strcpy(nodeKey, key);
    }
    else // key is too big
        cout << "Key is too long" << endl;
}

template <class Type>
void BST<Type>::node::copy(const node *n)
{
    if (n != this)
    {
        this -> setKey(n -> nodeKey);
        this -> leftChild  = n -> leftChild;
        this -> rightChild = n -> rightChild;
        this -> data       = n -> data;
    }
    
    return;
}

template <class Type>
BST<Type>::node::~node()
{
    if (nodeKey)
        delete [] nodeKey;
    
    nodeKey    = NULL;
    leftChild  = NULL;
    rightChild = NULL;
}

template <class Type>
bool BST<Type>::node::greaterThan(const node *n) const
{
    if (strcmp(this->nodeKey, n->nodeKey) >= 0)
    {
        return true;
    }
    else
        return false;
}

template <class Type>
bool BST<Type>::node::lessThan(const node *n) const
{
    if (strcmp(this->nodeKey, n->nodeKey) < 0) {
        return true;
    }
    else
        return false;
}

//template <class Type>
//bool BST<Type>::node::operator==(const node &n) const
//{
//  return (strcmp(n.nodeKey, this -> nodeKey) == 0);
//}

template <class Type>
BST<Type>::BST(int capacity)
{
    treeCapacity = capacity;
    nodesIntree  = 0;
    treeRoot     = NULL;
    
    //if (treeCapacity == UNLIMITED || treeCapacity >= 1)
    //root = new node();
    //else
    // treeCapacity cannot be 0 or negative
}

template <class Type>
BST<Type>::~BST()
{
    if (treeRoot)
    {
        destroy(treeRoot);
    }
    treeRoot = NULL;
}

/*
 template <class Type>
 bool BST<Type>::equal(const BST<Type> &bst) const
 {
 bool equal = false;
 
 if (this.nodesIntree == bst.nodesIntree)
 {
 
 }
 return equal;
 }*/

template <class Type>
void BST<Type>::print() const
{
    printInorder(treeRoot);
}


template <class Type>
void BST<Type>::printInorder(const node *a) const
{
    if (a)
    {
        printInorder(a -> leftChild);
        cout << a -> nodeKey << endl;
        printInorder(a -> rightChild);
    }
    
    return;
}

template <class Type>
BST<Type>& BST<Type>::operator=(const BST<Type> &r)
{
    if (this != &r)
    {
        this -> destroy(treeRoot);
        this -> treeCapacity = r.treeCapacity;
        copyTree(r.treeRoot);
    }
    else
        return *this;
}

template <class Type>
void BST<Type>::copyTree(const node *n)
{
    if (n)
    {
        this -> insert(n->nodeKey, n->data);
        this -> copyTree(n -> leftChild);
        this -> copyTree(n -> rightChild);
    }
    return;
}

template <class Type>
bool BST<Type>::hasDuplicates() const
{
    List<Type> list;
    sortNodekeys(treeRoot, list);
    
    return (list.hasDuplicates());
}

template <class Type>
bool BST<Type>::operator==(const BST<Type> &r) const
{
    if (&r != this)
    {
        if ((r.nodesIntree + this -> nodesIntree) == 0) // empty trees are eqal
            return true;
        
        else if ( (r.nodesIntree == this -> nodesIntree) )
        {
            List<Type> lst1, lst2;
            
            sortNodekeys(this -> treeRoot, lst1);
            sortNodekeys(r.treeRoot, lst2);
            
            if (lst1 == lst2)
                return true;
            else
                return false;
        }
        else
            return false;
        
    }
    else
        return true;
}

template <class Type>
void BST<Type>::sortNodekeys(const node * n, List<Type> &list) const
{
    if (n)
    {
        sortNodekeys(n -> leftChild, list);
        list.insert(n -> data);
        sortNodekeys(n -> rightChild, list);
    }
    return;
}


template <class Type>
void BST<Type>::destroy(node *aNode)
{
    if (aNode)
    {
        destroy(aNode -> leftChild);
        destroy(aNode -> rightChild);
        delete aNode;
        aNode = NULL;
    }
    return;
}
template <class Type>
bool BST<Type>::insert(const char * const key, const Type &object)
{
    if (!isFull())
    {
        node * nodeTobeAdded = new node();
        nodeTobeAdded->setKey(key);
        nodeTobeAdded->data = object;
        
        if(!treeRoot)
            treeRoot = nodeTobeAdded;
        else
        {
            node * currentNode    = treeRoot;
            bool nodeHasbeenAdded = false;
            
            while (!nodeHasbeenAdded)
            {
                if (nodeTobeAdded -> lessThan(currentNode))
                {
                    if (!(currentNode -> leftChild))
                    {
                        currentNode -> leftChild = nodeTobeAdded;
                        nodeHasbeenAdded         = true;
                    }
                    else // currentNode -> leftChild
                        currentNode = currentNode -> leftChild;
                }
                else // nodeTobeAdded -> greaterThan(currentNode)
                {
                    if (!(currentNode -> rightChild))
                    {
                        currentNode -> rightChild =nodeTobeAdded;
                        nodeHasbeenAdded          = true;
                    }
                    else // currentNode -> rightChild
                        currentNode = currentNode -> rightChild;
                }
            }
            currentNode = NULL;
        }
        
        nodesIntree++;
        nodeTobeAdded = NULL;
        return true;
    }
    else
        return false;
}

template <class Type>
bool BST<Type>::remove(const char * const key, const bool removeDuplicates)
{
    return (removeNode(key, removeDuplicates));
}

template <class Type>
bool BST<Type>::removeNode(const char * const key, const bool removeDuplicates, node *startNode)
{
    if (!startNode)
        startNode = treeRoot;
    
    node * parent      = NULL;
    node * child       = NULL;
    bool found         = false;
    bool flag          = true;
    
    parent = startNode;
    child  = startNode;
    
    while (flag)
    {
        if ( (!parent) || (!child)) // if parent or child is null, then no item in tree
            flag = false;
        
        else if ( strcmp(child -> nodeKey, key) > 0)
        {
            parent = child;
            child  = child -> leftChild;
        }
        
        else if ( strcmp(child -> nodeKey, key) < 0)
        {
            parent = child;
            child  = child -> rightChild;
        }
        
        else // child -> nodeKey >= key
        {
            flag = false;
            found = true;
        }
    }
    
    if (found)
    {
        bool moveRoot    = false;
        node * dummyRoot = NULL;
        
        if (child == treeRoot)
        {
            dummyRoot              = new node();
            dummyRoot -> leftChild = treeRoot;
            treeRoot               = dummyRoot;
            parent                 = dummyRoot;
            moveRoot               = true; 
        }
        // remove a leaf
        if ( !(child -> leftChild) && !(child -> rightChild) )
        {
            if ( (parent -> leftChild) == child)
                parent -> leftChild = NULL;
            
            else    // parent -> rightChild == child
                parent -> rightChild = NULL;
            
            delete child;
        }
        
        // remove node with one child
        else if ( (child -> leftChild) && !(child -> rightChild) )
        {
            if ( (parent -> leftChild) == child )
                parent -> leftChild = child -> leftChild;
            else
                parent -> rightChild = child -> leftChild;
            
            delete child;
        }
        
        else if ( (child -> rightChild) && !(child -> leftChild) )
        {
            if ( (parent -> leftChild) == child )
                parent -> leftChild = child -> rightChild;
            else
                parent -> rightChild = child -> rightChild;
            
            delete child;
        }
        
        
        // remove node with two children
        else
        {
            // Find the minimum value from child's right subtree
            node * minNode   = NULL;
            node * minParent = NULL;
            minNode          = child -> rightChild;
            minParent        = child;
            flag             = true;
            
            while (flag)
            {
                if (!(minNode -> leftChild))
                    flag = false;
                else
                {
                    minParent = minNode; 
                    minNode   = minNode -> leftChild;
                }
            }
            
            child -> setKey(minNode -> nodeKey);
            child -> data = minNode -> data;
            

           if (minParent -> leftChild == minNode)
                minParent -> leftChild = NULL;
            else
            {
                minParent -> rightChild = minNode -> rightChild;
            }
            delete minNode;
            
            minNode   = NULL;
            minParent = NULL;
        }
        
        if (moveRoot)
        {
            treeRoot = dummyRoot -> leftChild;
            delete dummyRoot;
            dummyRoot = NULL;
        }
        nodesIntree--;
        
            // Check if duplicates need to be removed (if so call self again)
        if (removeDuplicates)
            removeNode(key, true);
    }
    
    parent = NULL;
    child  = NULL;
    return found;
}

template <class Type>
bool BST<Type>::find(const char * const key, Type &retObject)
{
    if (!isEmpty())
    {
        bool flag  = true;
        bool found = false;
        node * parent = treeRoot;
        node * child  = treeRoot;
        
        while (flag)
        {
            if ( (!parent) || (!child)) // if parent or child is null, then no item in tree
                flag = false;
            
            else if ( strcmp(child -> nodeKey, key) > 0)
            {
                parent = child;
                child  = child -> leftChild;
            }
            
            else if ( strcmp(child -> nodeKey, key) < 0)
            {
                parent = child;
                child  = child -> rightChild;
            }
            
            else // child -> nodeKey == key
            {
                retObject = child -> data;
                flag      = false;
                found     = true;
            }
        }
        
        return found;
    }
    else
        return false;
}

template <class Type>
bool BST<Type>::isEmpty() const
{
    return (nodesIntree == 0);
}

template <class Type>
bool BST<Type>::isFull() const
{
    return (nodesIntree == treeCapacity);
}
#endif
