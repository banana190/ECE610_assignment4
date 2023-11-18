#include <iostream>
#include "linklist.h"

#define push insertionLeft      // push is insertedLeft
#define pop removeLeft          // pop is removedLeft
#define enqueue insertionLeft   // enqueue is insertedLeft
#define dequeue removeRight     // dequeue is removedRight

int main()
{
    link_list stack;
    link_list queue;
    int k [5] = {2,4,6,8,10};

    // push
    std::cout << "this is the stack"<< std::endl;
    for (int i = 2; i < 5; i++)
    {
        std::cout << "push"<< std::endl;
        stack.push(k[i]);
        stack.printlist();
    }
    // pop
    stack.pop();
    std::cout << "pop"<< std::endl;
    stack.printlist();
    std::cout << "pop"<< std::endl;
    stack.pop();
    stack.printlist();

    // enqueue
    std::cout << "this is the queue"<< std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "enqueue"<< std::endl;
        queue.enqueue(k[i]);
        queue.printlist();
    }
    // dequeue
    std::cout << "dequeue"<< std::endl;
    queue.dequeue();
    queue.printlist();
    std::cout << "dequeue"<< std::endl;
    queue.dequeue(); 
    queue.printlist();
    system("pause");
    return 0;
}