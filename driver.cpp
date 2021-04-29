#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ARRAY_LENGTH 6
 
int main(int argc, char** argv)
{
    /*srand (time(NULL));
    int ar[ARRAY_LENGTH];
    //4 2 1 6 0 3
    ar[0] = 4;
    ar[1] = 2;
    ar[2] = 1;
    ar[3] = 6;
    ar[4] = 0;
    ar[5] = 3;
    mergeSort(ar, 0, ARRAY_LENGTH-1);*/

    // create linked list
    LinkedList* ll = new LinkedList();
    // place values into linked list
    ll->addEnd(4);
    ll->addEnd(2);
    ll->addEnd(1);
    ll->addEnd(6);
    ll->addEnd(0);
    ll->addEnd(3);
    // list before sorting
    ll->display();
    // call merge sort
    ll->mergeSort(0, ll->count - 1);
    // list after sorting
    ll->display();
    return 0;
}

void displayIntArray(int ar[])
{
    for(int i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << ar[i] << endl;
    }
}
