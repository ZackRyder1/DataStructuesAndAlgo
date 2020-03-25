//
// Created by zack on 25/03/20.
//
#include<iostream>
using namespace std;

struct Array{
    int * arr;
    int size;

public:
    Array(int size)
    {
        this->arr = new int [size];
        this->size = size;
    }
};

int Partition(Array * A,int start,int end)
{
    int pivot = A->arr[end];  //Last element as Pivot
    int j=start-1;
    for(int i=start;i<end;i++)
    {
        if(A->arr[i] <= pivot)
        {
            int temp = A->arr[++j];
            A->arr[j] = A->arr[i];
            A->arr[i] = temp;
        }
    }
    A->arr[end] = A->arr[++j];
    A->arr[j] = pivot;
    return j; // index of pivot element
}


void QuickSort(Array * A,int start,int end)
{
    if(start<end)
    {
        int pivot_index = Partition(A,start,end);
        QuickSort(A,start,pivot_index-1);
        QuickSort(A,pivot_index+1,end);
    }
}

void Print(int arr[],int size)
{
    for (int i = 0; i < size;i++) {
        cout<<"Array["<<i<<"] = "<<arr[i]<<'\n';
    }
}

int main()
{
    int size = 6;
    Array * A = new Array(size);
    A->arr[0] = 45;
    A->arr[1] = 4;
    A->arr[2] = 2;
    A->arr[3] = 1;
    A->arr[4] = 3;
    A->arr[5] = 0;
    cout<<"Unsorted Array"<<'\n';
    Print(A->arr,A->size);
    cout<<"-------------------------------"<<'\n';
    QuickSort(A,0,A->size-1);
    cout<<"Sorted Array"<<'\n';
    Print(A->arr,A->size);
    cout<<"-------------------------------"<<'\n';
    return 0;
}

