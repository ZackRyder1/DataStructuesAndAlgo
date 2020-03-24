//
// Created by zack on 24/03/20.
//
#include<iostream>
using namespace std;

int * insertion_Sort(int arr[],int size)
{
    for(int i = 1;i<size;i++)
    {
        int hole = i;
        int temp = arr[hole];
        while(hole>0 && arr[hole-1]>=temp)
        {
            arr[hole] = arr[hole-1];
            arr[--hole] = temp;
        }
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

    int arr[6] = {45,4,2,1,3,0};
    int size = 6;
    cout<<"Unsorted Array"<<'\n';
    Print(arr,size);
    cout<<"-------------------------------"<<'\n';
    insertion_Sort(arr,size);
    cout<<"Unsorted Array"<<'\n';
    Print(arr,size);
    cout<<"-------------------------------"<<'\n';
    return 0;
}

