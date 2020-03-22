//
// Created by zack on 19/03/20.
//
#include <iostream>
#include<string>
#include <list>
#include <map>
#include <iterator>
#include <queue>
using namespace std;
class Vertex;

class Edge{
    list <Vertex*> * adjList;

public:
    Edge()
    {
         this->adjList = new list<Vertex*>();
    }

    void addEdge(Vertex * v);

    list<Vertex*> * getList()
    {
        return this->adjList;
    }

    ~Edge()
    {
        delete this->adjList;
    }
};



class Vertex{
    string name;
    Edge * edges;

public:
    Vertex()
    {

    }

    Vertex(string name)
    {
        this->name = name;
        this->edges = new Edge();
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    Edge * getEdges()
    {
        return this->edges;
    }

    ~Vertex()
    {
        delete edges;
    }

};

class Graph{

    map <string,Vertex*> * vertices;
    map<Vertex*,bool> * traversal;

    void AddEdge(Vertex * incoming,Vertex * outgoing)
    {
        incoming->getEdges()->addEdge(outgoing);
        outgoing->getEdges()->addEdge(incoming);
    }


    void Traversal_Init()
    {
        this->traversal = new map<Vertex*,bool>();
        map<string,Vertex*>::iterator it;
        for(it=this->vertices->begin();it!=vertices->end();it++)
        {
            this->traversal->insert(pair<Vertex*,bool>(it->second,false));
        }
    }

    void BFS_traversal(Vertex * v)
    {

        Vertex * u = v;
        cout<<"Visited the node having name : " << u->getName()<<'\n';
        this->traversal->at(v) = true; //Setting current node as visited
        queue<Vertex*> * q = new queue<Vertex*>();

        while(true){
            list <Vertex*> :: iterator it;
            list<Vertex *> * list1 = u->getEdges()->getList();
            for(it=list1->begin(); it!=list1->end(); it++) //Accessing the Adjacent nodes
            {
                if(!(this->traversal->at(*it))) //is it visited Before???
                {
                    q->push(*it);
                    cout<<"Visited the node having name : " << (*it)->getName()<<'\n';
                    this->traversal->at(*it) = true;
                }
            }
            if(q->empty())
                return;
            else
            {
                u = q->front();
                q->pop();
            }
        }
    }

    void DFS_traversal(Vertex * v)
    {
        Vertex * u = v;
        this->traversal->at(u) = true;
        cout<<"Visited the node having name : " << u->getName()<<'\n';
        list <Vertex*> :: iterator it;
        list<Vertex *> * list1 = u->getEdges()->getList();
        for(it=list1->begin(); it!=list1->end(); it++)
        {
            if(!(this->traversal->at(*it)))
                DFS_traversal(*it);
        }

    }

public:

    Graph()
    {
        this->vertices = new map<string,Vertex*>;
    }

    void AddVertex(string name)
    {
        this->vertices->insert(pair<string,Vertex*>(name,new Vertex(name)));
    }

    void AddEdge(string incoming,string outgoing)
    {
        AddEdge(this->vertices->at(incoming),this->vertices->at(outgoing));
    }

    void List()
    {
        map<string,Vertex*> :: iterator i;
        for(i= this->vertices->begin(); i!=this->vertices->end(); i++)
        {
            cout<< "Visited Vertex :"<< i->first<<'\n';
            list<Vertex*> * list1 = i->second->getEdges()->getList();
            list<Vertex*>:: iterator t1;
            for(t1=list1->begin(); t1!= list1->end() ; t1++)
            {
                cout<<"The Vertex " << i->first << " is connected to " << (*t1)->getName()<<'\n';
            }
            cout<<"--------------------------------------"<<'\n';
        }
    }

    void BFS()
    {
        Traversal_Init();
        map<string,Vertex*> :: iterator i;
        cout<<"BFS"<<'\n'<<"-----------------------------"<<'\n';
        for(i= this->vertices->begin(); i!=this->vertices->end(); i++)
        {
            if(!(this->traversal->at(i->second)))
                BFS_traversal(i->second);
        }
        cout<<"------------------------------"<<'\n';
    }

    void DFS()
    {
        Traversal_Init();
        map<string,Vertex*> :: iterator i;
        cout<<"DFS"<<'\n'<<"-----------------------------"<<'\n';
        for(i= this->vertices->begin(); i!=this->vertices->end(); i++)
        {
            if(!(this->traversal->at(i->second)))
                DFS_traversal(i->second);
        }
        cout<<"------------------------------"<<'\n';
    }

    ~Graph()
    {
        delete vertices;
        delete traversal;
    }

};

void Edge:: addEdge(Vertex * v) {
    this->adjList->push_front(v);
}



int main()
{
    Graph * g1 = new Graph();
    g1->AddVertex("A");
    g1->AddVertex("B");
    g1->AddVertex("C");
    g1->AddVertex("D");
    g1->AddVertex("E");
    g1->AddVertex("F");
    g1->AddVertex("G");
    g1->AddVertex("H");
    g1->AddEdge("A","B");
    g1->AddEdge("A","C");
    g1->AddEdge("B","D");
    g1->AddEdge("B","E");
    g1->AddEdge("C","F");
    g1->AddEdge("C","G");
    g1->AddEdge("D","H");
    g1->AddEdge("E","H");
    g1->AddEdge("F","H");
    g1->AddEdge("G","H");
    g1->BFS();
    g1->DFS();
    delete g1;
    return 0;
}