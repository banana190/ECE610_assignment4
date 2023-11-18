#include <iostream>
#include <vector>

using std::vector;
template <typename T>
void easy_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

vector<int> BubbleSort(vector<int> list)
{
    int Compairing_Time = 0;
    int Swap_Time = 0;
    int size = list.size();
    bool swapping = false;
    do
    {
        swapping = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (list[i] > list[i + 1])
            {
                easy_swap(list[i], list[i + 1]);
                Swap_Time++;
                swapping = true;
            }
            Compairing_Time++;
        }
    } while (swapping);
    std::cout << "\n\nThe Bubble sort operation took " << Compairing_Time << " times at compairing";
    std::cout << "\nThe Bubble sort operation took " << Swap_Time << " times at swaping\n\n";
    return list;
}

vector<int> SelectionSort(vector<int> list)
{
    int Compairing_Time = 0;
    int Swap_Time = 0;
    int size = list.size();
    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (list[j] < list[index])
                index = j;
            Compairing_Time++;
        }
        easy_swap(list[i], list[index]);
        Swap_Time++;
    }
    std::cout << "\n\nThe Selection sort operation took " << Compairing_Time << " times at compairing\n";
    std::cout << "The Selection sort operation took " << Swap_Time << " times at swaping\n\n";

    return list;
}

vector<int> InsertionSort(vector<int> list)
{
    int Compairing_Time = 0;
    int Swap_Time = 0;
    int size = list.size();
    for (int i = 1; i < size; i++)
    {
        int pivot = list[i];
        int j;
        for (j = i; j > 0; --j)
        {
            Compairing_Time ++;
            if (list[j - 1] > pivot)
            {
                list[j]=list[j - 1];
                Swap_Time++;
            }
            else
                break;
        }
        list[j] = pivot;
    }
    std::cout << "\n\nThe Insertion sort operation took " << Compairing_Time << " times at compairing\n";
    std::cout << "The Insertion sort operation took " << Swap_Time << " times at swaping\n\n";
    return list;
}