//
// Created by zack on 29/03/20.
//
#include<iostream>
using namespace std;
struct Job{
    int deadline;
    int profit;

public:
    Job()
    {
        this->deadline=0;
    }

    Job(int deadline,int profit)
    {
        this->deadline = deadline;
        this->profit = profit;
    }


};

void Swap(Job * a,Job * b)
{
    Job temp = *a;
    *a = *b;
    *b = temp;
}

Job & findMaxProfit(Job * job,int size)
{
    int max_index = 0;
    Job max = job[0];
    for(int i=1;i<size;i++)
    {
        if(max.profit<job[i].profit)
        {
            max = job[i];
            max_index = i;
        }
    }
    Swap(&job[max_index],&job[size-1]);
    return job[size-1];
}

int findMaxDeadline(Job * jobs,int size)
{
    int max = jobs[0].deadline;
    for(int i=1;i<size;i++)
        if(max<jobs[i].deadline)
            max = jobs[i].deadline;

        return max;
}

void Print(Job * jobs,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"The Job with deadline "<<jobs[i].deadline<<" and a profit of "<<jobs[i].profit<<" will execute "<<i+1<<'\n';
    }
}

int findProfit(Job * jobs,int size)
{
    int total_profit = 0;
    int remaining_size =  findMaxDeadline(jobs,size);
    int actual_size = remaining_size;
    Job * schedule = new Job[remaining_size];

    while(size>0 && remaining_size>0)
    {
        Job MaxProfitJob = findMaxProfit(jobs,size);
        size--;
        for(int i=MaxProfitJob.deadline-1;i>=0;i--)
        {
            if(schedule[i].deadline == 0)
            {
                schedule[i] = MaxProfitJob;
                total_profit+=MaxProfitJob.profit;
                remaining_size--;
                break;
            }
        }
    }
    Print(schedule,actual_size);
    delete [] schedule;
    return total_profit;
}




int main()
{
    Job j1(5,200);
    Job j2(3,180);
    Job j3(3,190);
    Job j4(2,300);
    Job j5(4,120);
    Job j6(2,100);
    Job jobs[6] = {j1,j2,j3,j4,j5,j6};
    int profit = findProfit(jobs,6);
    cout<<"Total Profit is "<< profit<<'\n';
    return 0;
}

