//
// Created by zack on 26/03/20.
//
#include <iostream>
using namespace std;

void Swap(int * a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMinIndex(const int arr[],int start,int size)
{
    int min = arr[start],min_index = start;
    for(int i=start;i<size;i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int * selectionSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int min_index = getMinIndex(arr,i,size);
        Swap(&arr[min_index],&arr[i]);
    }
    return arr;
}


void Print(int arr[],int size)
{
    for (int i = 0; i < size;i++) {
        cout<<"Array["<<i<<"] = "<<arr[i]<<'\n';
    }
}

int main()
{
    int arr[5] = {100,2,90,46,86};
    cout<<"Unsorted Array"<<'\n'<<"------------------------"<<'\n';
    Print(arr,5);
    selectionSort(arr,5);
    cout<<"------------------------"<<'\n';
    cout<<"Sorted Array"<<'\n'<<"------------------------"<<'\n';
    Print(arr,5);
    return 0;
}
