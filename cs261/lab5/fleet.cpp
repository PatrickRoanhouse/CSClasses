#include "fleet.h"


Fleet::Fleet():BST<Vehicle>()
{
}

void Fleet::insert(Vehicle &v)
{
     if (BST<Vehicle>::insert(v.getName(), v))
     {
         cout << "vehicle '" << v.getName() 
              << "' was added" << endl;
     }
    return;
}

void Fleet::remove(const char *key)
{
    if (BST<Vehicle>::remove(key, true))
    {
        std::cout << "'" << key << "' deleted" << std::endl;
    }
    else
        std::cout << "couldn't find '" << key << "'" << std::endl;
    return;
}

void Fleet::print() const
{
    std::cout << "---- Fleet ----" << std::endl;
    BST<Vehicle>::print();
}