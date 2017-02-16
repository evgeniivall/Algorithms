#include <iostream>
#include "algorithms.h"
#include "List_Class.h"

using std::cout;
using std::endl;

int main()
{
    List<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(10);
    l.push_back(20);

    l.push_front(1);
    l.push_front(2);
    l.push_front(1);
    l.push_front(2);

    List<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto i = l2.begin(); i != l2.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    l.pop_back();
    l.pop_back();

    selectionSort(l.begin(), l.end());
    reverse(l2.begin(), l2.end());
    for(auto i = l2.begin(); i != l2.end(); i++)
    {
        cout << *i << " ";
    }

    int array[10] = {1, 3, 5, 8, 9,3, 2, 5};

    insertSort(&array[0], &(array[10]));
    reverse(&array[0], &(array[10]));


    cout << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }


    return 0;
}
