#include <iostream>
#include "binarytree.h"

int main()
{
    BSTree I_love_tree;
    I_love_tree.Insert(9); 
    I_love_tree.Insert(7);
    I_love_tree.Insert(2);
    I_love_tree.Insert(4); 
    I_love_tree.Insert(1);
    I_love_tree.Insert(5);

    std::cout << "Searching 4 :" << std::endl;
    I_love_tree.Search(4);
    std::cout << "Deleting 4 :" << std::endl;
    I_love_tree.Delete(4);
    std::cout << "Searching 4 :" << std::endl;
    I_love_tree.Search(4);
    system("pause");  
    return 0;
}