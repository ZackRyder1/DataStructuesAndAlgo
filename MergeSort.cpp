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


void Merge(Array * left,Array * right,Array * A)
{
    int left_itr,right_itr,A_itr;
    left_itr = right_itr = A_itr = 0;
    
    while(left_itr<left->size && right_itr<right->size)
    {
        if(left->arr[left_itr] <= right->arr[right_itr])
            A->arr[A_itr++] = left->arr[left_itr++];
        else
            A->arr[A_itr++] = right->arr[right_itr++];
    }
    
    while(left_itr<left->size)
        A->arr[A_itr++] = left->arr[left_itr++];
    
    while(right_itr<right->size)
        A->arr[A_itr++] = right->arr[right_itr++];
    
    delete left;
    delete right;
}

void MergeSort(Array * A)
{
    if(A->size < 2)
        return;
    int mid = A->size/2;
    Array * left = new Array(mid);
    Array * right = new Array(A->size - mid);
    for(int i=0;i<mid;i++)
        left->arr[i] = A->arr[i];
    
    for(int i=mid;i<A->size;i++)
        right->arr[i-mid] = A->arr[i];
    
    MergeSort(left);
    MergeSort(right);
    Merge(left,right,A);
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
    MergeSort(A);
    cout<<"Sorted Array"<<'\n';
    Print(A->arr,A->size);
    cout<<"-------------------------------"<<'\n';
    return 0;
}

