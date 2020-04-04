//
// Created by zack on 04/04/20.
//
#include <iostream>
using namespace std;

class Item{
    int profit;
    int weight;
public:
    Item(){}

    Item(int profit, int weight) : profit(profit), weight(weight) {}

    int getProfit() const {
        return profit;
    }

    int getWeight() const {
        return weight;
    }
};

int findProfit(Item arr[],int numItems,int knapsack)
{
    int table[numItems+1][knapsack+1];

    for(int i=0;i<numItems+1;i++)
        table[i][0] = 0;

    for(int i=0;i<knapsack+1;i++)
        table[0][i] = 0;

    for(int i=1;i<numItems+1;i++)
    {
        int weight = arr[i-1].getWeight();
        int profit = arr[i-1].getProfit();
        for(int j=1;j<knapsack+1;j++)
        {
            if(weight<=j && table[i-1][j-weight] + profit > table[i-1][j])
                table[i][j] = table[i-1][j-weight] + profit;
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[numItems][knapsack];
}

int main()
{
    Item item1(10,1);
    Item item2(12,2);
    Item item3(28,4);
    Item arr[3] = {item1,item2,item3};
    cout<<"The Maximum Profit is "<<findProfit(arr,3,6)<<'\n';
    return 0;
}

