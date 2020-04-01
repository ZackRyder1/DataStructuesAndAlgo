//
// Created by zack on 31/03/20.
//
#include<iostream>
#include<list>
#include <map>
#include<queue>

using namespace std;
list<char> solution;
map<int,char> mappings;

class SplitNode
{
    int split1;
    int split2;

public:
    SplitNode(int split1=-1,int split2=-1)
    {
        this->split1 = split1;
        this->split2 = split2;
    }

    int getSplit1() const {
        return split1;
    }

    void setSplit1(int split1) {
        SplitNode::split1 = split1;
    }

    int getSplit2() const {
        return split2;
    }

    void setSplit2(int split2) {
        SplitNode::split2 = split2;
    }
};

class Matrix
{
    char name;
    int dimension1;
    int dimension2;

public:
    Matrix()
    {

    }
    Matrix(const char &name, int dimension1, int dimension2) : name(name), dimension1(dimension1),
                                                                 dimension2(dimension2) {}

    const char &getName() const {
        return name;
    }

    void setName(const char &name) {
        Matrix::name = name;
    }

    int getDimension1() const {
        return dimension1;
    }

    void setDimension1(int dimension1) {
        Matrix::dimension1 = dimension1;
    }

    int getDimension2() const {
        return dimension2;
    }

    void setDimension2(int dimension2) {
        Matrix::dimension2 = dimension2;
    }
};

void initialize(Matrix matrices[],int size)
{
    for(int i= 0;i<size;i++)
    {
        mappings.insert(pair<int,char>(i,matrices[i].getName()));
        solution.push_back(matrices[i].getName());
    }
}

list<char>::iterator find(char data,list<char>::iterator it)
{
    for(it=solution.begin();it!=solution.end();it++)
        if(*it == data)
            break;
    return it;
}

void parenthesis(int split1,int split2)
{
    if(split1 == split2)
        return;

    list<char>::iterator it = find(mappings.at(split1),it);
    solution.insert(it,'(');
    it = find(mappings.at(split2),it);
    solution.insert(++it,')');
}

SplitNode * processSplit(SplitNode split_dim[],int split,int start,int end)
{
    split_dim[0].setSplit1(start);
    split_dim[0].setSplit2(split);
    split_dim[1].setSplit1(split+1);
    split_dim[1].setSplit2(end);
    return split_dim;
}

void buildSolution(int * arr,int m,int n)
{
    int split[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            split[i][j] = arr[i*n+j];

        SplitNode * split_content = new SplitNode[2];
        int first_split = split[0][n-1];
        processSplit(split_content,first_split,0,n-1);
        queue<SplitNode *> processSplitQ;
        processSplitQ.push(split_content);
        while(!processSplitQ.empty())
        {
           split_content = processSplitQ.front();
           processSplitQ.pop();
           for(int i=0;i<2;i++)
           {
               int start = split_content[i].getSplit1();
               int end = split_content[i].getSplit2();
               parenthesis(start,end);
               if(start+1 == end)
                    continue;
               else if(start != end)
               {
                   SplitNode * split_content = new SplitNode[2];
                   first_split = split[start][end];
                   processSplitQ.push(processSplit(split_content,first_split,start,end));
               }
           }
        }


}

int Matrix_Chain(int * p,int size)  //just returns min. scalar multiplication
{
       int table_size = size-1;
       int table [table_size][table_size];
       int split[table_size-1][table_size];
       for(int i =0;i<table_size;i++)
           table[i][i] = 0;
    for (int l = 1; l < table_size; l++) {
        for(int i=0;i<table_size-l;i++)
        {
            int j = i+l;
            table[i][j] = INT16_MAX;
            for(int k=i;k<j;k++)
            {
                int q = table[i][k] + table[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(q<table[i][j]) {
                    table[i][j] = q;
                    split[i][j] = k;
                }
            }
        }
    }
     buildSolution((int*)split,table_size-1,table_size);
    return table[0][size-2];
}

void print()
{
    list<char>::iterator it;
    for(it=solution.begin();it!=solution.end();it++)
    {
        cout<<*it;
    }
    cout<<'\n';
}


int main()
{
    Matrix a('A',1,2);
    Matrix b('B',2,1);
    Matrix c('C',1,4);
    Matrix d('D',4,1);
    Matrix matrices[4];
    matrices[0] = a;
    matrices[1] = b;
    matrices[2] = c;
    matrices[3] = d;
    initialize(matrices,4);
    int p[5];
    p[0] = a.getDimension1();
    p[1] = a.getDimension2();
    p[2] = b.getDimension2();
    p[3] = c.getDimension2();
    p[4] = d.getDimension2();
    cout<<"The Mininum Scalar Multiplication required is "<<Matrix_Chain(p,5)<<'\n';
    cout<<"The solution for Matrix Chain is ";
    print();

    return 0;
}

