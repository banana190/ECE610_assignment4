#include <iostream>
// Chun Wei Wang Lai
//----------------------------------------------------------------
using std::cout;
using std::cin;
using std::endl;

class link_list;

class link_node
{
    private:
        int data;
        link_node *next;
    public:
        link_node():data(0),next(0){};
        link_node(int a):data(a),next(0){};
    
    friend class link_list;
};

class link_list
{
    private:
        link_node *first;
    public:
        link_list():first(0){};
        void printlist();
        void insertionLeft(int a);
        void insertionRight(int a);
        void deletion(int a);
        void search(int a);
        void removeLeft();
        void removeRight();
};

void link_list::printlist() // O(n)
{
    if (first == 0)
    {
        cout<< "empty list"<< endl;
        return;
    }
    link_node *current = first;
    while (current !=0) //current = after last node
    {
        cout << current->data;
        if (current-> next != 0)
            cout << ", ";
        current = current->next;
    }
    cout<< endl;
}

void link_list::insertionLeft(int a) // O(1)
{
    link_node *newnode = new link_node(a); //new memory for new int a
    newnode->next = first;// the new int a's next node is the first node
    first = newnode;//the new int a become the first node
}

void link_list::insertionRight(int a) // O(n) if there is a *last then O(1)
{
    link_node *newnode = new link_node(a);

    if (first == 0)
    {
        first = newnode;
        return;
    }

    link_node *current = first;
    while(current->next != 0 ) //current = last node
    {
        current = current->next;
    }
    current->next = newnode;
}

void link_list::deletion(int a) // O(n)
{
    link_node *previous = 0;
    link_node *current = first;
    while (current != 0) //make sure can delete every a
    {
        if (current->data == a)
        {
            if (current == first)
            {
                first = current->next;
                delete current; 
                current = first;
            }
            else
            {
                previous->next = current->next;
                delete current; 
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

void link_list::search(int a) // O(n)
{
    link_node *current = first;
    int temp = 0;

    while(current!=0)
    {
        if (current->data == a)
            temp++;
        current = current -> next;
    }

    if (temp !=0) 
        cout<<"there is " << temp <<" "<< a <<" in the list.\n";
    else
        cout<<"There is no " << a << " in the list.\n";
    return;
}
//----------------------------------------------------------------
//These functions are for Stack and Queue
void link_list::removeLeft() //O(1)
{
    link_node *current = first;
    first = current -> next;
    delete current;
    current = 0;
    return;
}

void link_list::removeRight() // O(n)
{
    link_node *current = first;
    link_node *previous = 0;
    while (current -> next != 0)
    {
        previous = current;
        current = current -> next;
    }
    delete current;
    previous-> next = 0;
    return;
}


