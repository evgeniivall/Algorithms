#include <iostream>
#include "algorithms.h"
#include "List_Class.h"

using std::cout;
using std::endl;


void minus(int& value)
{
    value = -(value);
}

int main()
{
    List<int> l = {2, 2, 6, 8, 1, 2,  5, 7, 8, 2, 1,1};
    cout << "List: ";
    for(auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl << "List: ";
    selectionSort(l.begin(), l.end());
    for(auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    transform(l.begin(), l.end(), minus);
    cout << endl << "List: ";
    for(auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl << "Min: " << *(findMin(l.begin(), l.end()));
    cout << endl << "Max: " << *(findMax(l.begin(), l.end()));

    int array[10] = {1, 3, 5, 8, 9,3, 2, 5};
    cout << endl << "Array  : ";
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }

    transform(&array[0], &array[10], minus);
    cout << endl << "Array  : ";
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << "Min: " << *(findMin(&array[0],&array[10]));
    cout << endl << "Max: " << *(findMax(&array[0],&array[10]));


    return 0;
}
