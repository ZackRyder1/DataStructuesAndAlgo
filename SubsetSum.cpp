//
// Created by zack on 05/04/20.
//
#include<iostream>
using namespace std;

bool subsetSum(int arr[],int size,int sum)
{
    bool table[size+1][sum+1];
    table[0][0] = true;

    for(int i=1;i<sum+1;i++)
        table[0][i] = false;

    for(int i=1;i<size+1;i++)
        table[i][0] = true;

    for(int i=1;i<size+1;i++)
        for(int j=1;j<sum+1;j++)
        {
            if(j>=arr[i-1])
                table[i][j] = table[i-1][j-arr[i-1]] || table[i-1][j];
            else
                table[i][j] = table[i-1][j];
        }
    return table[size][sum];
}


int main()
{
    int arr[4] = {1,2,3,6};
    int sum = 8;
    int size = 4;
    cout<<"Subset sum is ";
    subsetSum(arr,size,sum)?cout<<" present":cout<<" absent";
    cout<<'\n';
    return 0;
}

