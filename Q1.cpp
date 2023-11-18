#include <iostream>
#include "linklist.h"


int main(){
    link_list testing;
    int k [5] = {2,4,6,8,10};
    std::cout << "sample array = [2,4,6,8,10]" << std::endl;
    std::cout << "Inserting the elements from first"<< std::endl;
    for(int i = 0; i < 5; i++)
    {
        testing.insertionLeft(k[i]);
    }
    testing.printlist();
    std::cout << "Inserting the elements from last"<< std::endl;
    for(int i = 0; i < 5; i++)
    {
        testing.insertionRight(k[i]); 
    }
    testing.printlist();
    std::cout<<"This will delete all 6 in the list."<<std::endl;
    testing.deletion(6);
    testing.printlist();

    return 0;
}