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

int * bubbleSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        bool swapped = false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j] >=arr[j+1])
            {
                Swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
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
    bubbleSort(arr,5);
    cout<<"------------------------"<<'\n';
    cout<<"Sorted Array"<<'\n'<<"------------------------"<<'\n';
    Print(arr,5);
    return 0;
}

