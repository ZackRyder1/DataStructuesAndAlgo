//
// Created by zack on 01/04/20.
//
#include<iostream>
using namespace std;

int cal_LCS(string a,string b)
{
    int LCS_table[a.length()+1][b.length()+1];

    for(int i=0;i<a.length()+1;i++)
        LCS_table[i][0] = 0;

    for(int i=0;i<b.length()+1;i++)
        LCS_table[0][i] = 0;

    for(int i =1;i<a.length()+1;i++)
    {
        for(int j=1;j<b.length()+1;j++)
        {
            if(a[i-1] == b[j-1])
                LCS_table[i][j] = 1 + LCS_table[i-1][j-1];
            else
                LCS_table[i][j] = max(LCS_table[i-1][j],LCS_table[i][j-1]);
        }
    }

    return LCS_table[a.length()][b.length()];
}

int main()
{
    string a ="ZAKI";
    string b ="RAFID";
    cout<<cal_LCS(a,b)<<'\n';
    return 0;
}
