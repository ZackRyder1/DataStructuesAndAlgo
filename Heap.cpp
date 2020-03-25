//
// Created by zack on 25/03/20.
//
#include<iostream>
#include <cmath>
using namespace std;

class Heap{
    int * heap;
    int size;
    const int max_size;

public:
    Heap(int size):max_size(size)
    {
        this->size = 0;
        this->heap = new int[size];
    }

    Heap(int * arr,int size,int max):max_size(max)
    {
        this->size = size;
        this->heap = arr;
    }

    int getParent(int index)
    {
        return ceil((float)index/2)-1;
    }

    int getLeftChild(int index)
    {
        return index*2+1;
    }

    int getRightChild(int index)
    {
        return index*2+2;
    }

    int getNonLeaves()
    {
        return floor(this->size/2)-1;
    }

    void Max_Heapify(int index)
    {
        int leftC_index = getLeftChild(index);
        int rightC_index = getRightChild(index);
        int largest_index = index,largest = this->heap[index];

        if(leftC_index<this->size && largest<this->heap[leftC_index])
        {
            largest = this->heap[leftC_index];
            largest_index = leftC_index;
        }

        if(rightC_index<this->size && largest<this->heap[rightC_index])
        {
            largest = this->heap[rightC_index];
            largest_index = rightC_index;
        }

        if(largest_index != index)
        {
            this->heap[largest_index] = this->heap[index];
            this->heap[index] = largest;
            Max_Heapify(largest_index);
        }
    }


    void build_Heap()
    {
        for(int i=getNonLeaves();i>=0;i--)
        {
            Max_Heapify(i);
        }
    }

    void increase_Key(int index,int newValue)
    {
        this->heap[index] = newValue;
        int temp_index = index;
        while(temp_index>0 && this->heap[getParent(temp_index)]< this->heap[temp_index])
        {
            int temp = this->heap[getParent(temp_index)];
            this->heap[getParent(temp_index)] = this->heap[temp_index];
            this->heap[temp_index] = temp;
            temp_index = getParent(temp_index);
        }
    }

    void insert_Key(int Value)
    {
        if(this->size == this->max_size)
        {
            cout<<"Heap OverFlow"<<'\n';
            return;
        }

        this->heap[this->size++] = INT32_MIN;
        increase_Key(this->size-1,Value);
    }

    int extract_Max()
    {
        int Max = this->heap[0];
        this->heap[0] = this->heap[--this->size];
        this->heap[this->size] = Max;
        Max_Heapify(0);
    }

    void List()
    {
        cout<<"Heap Contents"<<'\n'<<"----------------------------"<<'\n';
        for(int i=0;i<this->size;i++)
        {
            cout<<"Value at Node["<<i<<"] is "<<this->heap[i]<<'\n';
        }
    }

    ~Heap()
    {
        cout<<"Heap gets deleted"<<'\n';
    }

};

int main()
{
    int size = 5;
    int arr[5] = {1,25,23,3,4};
    Heap * heap = new Heap(arr,5,6);
    heap->List();
    cout<<"-----------------------------"<<'\n';
    heap->build_Heap();
    heap->List();
    heap->insert_Key(100);
    cout<<"-----------------------------"<<'\n';
    heap->List();
    heap->extract_Max();
    cout<<"-----------------------------"<<'\n';
    heap->extract_Max();
    heap->List();
    cout<<"-----------------------------"<<'\n';
    heap->List();
    delete heap;
    return 0;
}
