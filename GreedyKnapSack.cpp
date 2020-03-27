#include <iostream>
using namespace std;
struct Item{
    int id;
    int weight;
    int profit;
    float ratio;
public:
    Item()
    {

    }

    Item(int id, int weight, int profit) : id(id), weight(weight), profit(profit), ratio((float)profit/weight) {}

    float getRatio() const {
        return ratio;
    }

    int getWeight() const {
        return weight;
    }

    int getProfit() const {
        return profit;
    }

};

class SmartItem{
    Item * ptr;

public:
    SmartItem(Item * item)
    {
        this->ptr = item;
    }

    Item *getPtr() {
        return ptr;
    }

    ~SmartItem()
    {
        cout<<"Deleting the item having id "<<this->ptr->id<<'\n';
        delete this->ptr;
    }
};

struct Array{
    Item * arr;
    int size;

public:
    Array(int size)
    {
        this->arr = new Item[size];
        this->size = size;
    }
};

int Partition(Array * A,int start,int end)
{
    float pivot = A->arr[end].getRatio();//Last element as Pivot
    Item pivot_Item = A->arr[end];
    int j=start-1;
    for(int i=start;i<end;i++)
    {
        if(A->arr[i].getRatio() <= pivot)
        {
            Item temp = A->arr[++j];
            A->arr[j] = A->arr[i];
            A->arr[i] = temp;
        }
    }
    A->arr[end] = A->arr[++j];
    A->arr[j] = pivot_Item;
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


float maxProfit(Array * arr,int size,int knapsack)
{
    float profit = 0;
    QuickSort(arr,0,arr->size-1);  //Sort the elements according to the ratio
    int i=arr->size-1;
    while(knapsack>0 && arr->arr[i].getWeight() <= knapsack)
    {
        cout<<"Adding the Item having id "<<arr->arr[i].id<<" to the Knapsack."<<'\n';
        knapsack-=arr->arr[i].getWeight();
        profit+=arr->arr[i--].getProfit();
    }

    if(knapsack>0 && i>0)
    {
        cout<<"Adding the Fractional part of Item having id "<<arr->arr[i].id<<" to the Knapsack."<<'\n';
        profit+= (float)knapsack*(arr->arr[i].getRatio());
        knapsack = 0;
    }

    return profit;

}

void Print(Item arr[],int size)
{
    for (int i = 0; i < size;i++) {
        cout<<"Array["<<i<<"] = "<<arr[i].getRatio()<<'\n';
    }
}

int main() {


    SmartItem item1 = SmartItem(new Item(1,2,10));
    SmartItem item2 = SmartItem(new Item(2,3,5));
    SmartItem item3 = SmartItem(new Item(3,5,15));
    SmartItem item4 = SmartItem(new Item(4,7,7));
    SmartItem item5 = SmartItem(new Item(5,1,6));
    SmartItem item6 = SmartItem(new Item(6,4,18));
    SmartItem item7 = SmartItem(new Item(7,1,3));
    Array * arr = new Array(7);
    arr->arr[0] = *item1.getPtr();
    arr->arr[1] = *item2.getPtr();
    arr->arr[2] = *item3.getPtr();
    arr->arr[3] = *item4.getPtr();
    arr->arr[4] = *item5.getPtr();
    arr->arr[5] = *item6.getPtr();
    arr->arr[6] = *item7.getPtr();

    int profit = maxProfit(arr,arr->size,15);

    cout<<"Max Profit is "<<profit<<'\n';
    return 0;
}
