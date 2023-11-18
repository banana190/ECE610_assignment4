#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include "sorting.h"
using std::cout;
using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

vector<int> random_generator(int size)
{
    vector<int> temp;
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> distribution(1, size);

    // std::srand(static_cast<unsigned int>(std::time(0)));
    int i;
    while (size != 0)
    {
        // temp.push_back( std::rand() % size + 1);
        i = distribution(gen);
        // cout << i << " ";
        temp.push_back(i);
        size--;
    }
    return temp;
}

int main()
{
    int list_size = 2048;
    // int list_size = 10000;
    cout << "list_size: " << list_size <<std::endl;
    vector<int> list(list_size, 0);
    list = random_generator(list_size);

    // BubbleSort
    vector<int> result_B(list_size, 0);
    const auto start_time_B = high_resolution_clock::now();
    result_B = BubbleSort(list);
    const auto end_time_B = high_resolution_clock::now();
    const auto duration_B = duration_cast<milliseconds>(end_time_B - start_time_B);
    cout << "OperationTime: " << duration_B.count() << " ms" << std::endl;
    // for (int i : result_B)
    // {
    //     cout << i << " ";
    // }
    //----------------------------------------------------------------
    // InsertionSort
    vector<int> result_I(list_size, 0);
    auto start_time_I = high_resolution_clock::now();
    result_I = InsertionSort(list);
    auto end_time_I = high_resolution_clock::now();
    auto duration_I = duration_cast<milliseconds>(end_time_I - start_time_I);
    cout << "OperationTime: " << duration_I.count() << " ms" << std::endl;
    //     for (int i : result_I)
    // {
    //     cout << i << " ";
    // }
    //----------------------------------------------------------------
    //selectionSort
    vector<int> result_S(list_size, 0);
    auto start_time_S = high_resolution_clock::now();
    result_S = SelectionSort(list);
    auto end_time_S = high_resolution_clock::now();
    auto duration_S = duration_cast<milliseconds>(end_time_S - start_time_S);
    cout << "OperationTime: " << duration_S.count() << " ms" << std::endl;
    // for (int i : result_S)
    // {
    //     cout << i << " ";
    // }
    std::string printing;
    cout << "Need result?(Y/N)\n";
    std::cin >> printing;
    for (char &c : printing) 
    {
        c = std::tolower(c);
    }
    if (printing == "y"||printing == "yes")
    {
        bool same = (result_B == result_I && result_I == result_S);
        for (int i : result_B)
        {
        cout << i << " ";
        }
        cout << "\n\nThe results are = "<< (same ? "SAME" : "DIFFERENT") << std::endl; 
    }

    system("pause");
    return 0;
}