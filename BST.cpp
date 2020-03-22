//
// Created by zack on 18/03/20.
//
#include <iostream>
using namespace std;

class BSTNode{
    int data;
    BSTNode * left;
    BSTNode * right;

public:
    BSTNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    BSTNode * getLeftChild()
    {
        return this->left;
    }

    BSTNode* getRightChild()
    {
        return this->right;
    }

    void setLeftChild(BSTNode * left)
    {
        this->left = left;
    }

    void setRightChild(BSTNode * right)
    {
        this->right = right;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

};

class BST{
    BSTNode * root;
    string serialized;
    int iterator;

    BSTNode* insert(BSTNode * root , int data)
    {
        if(root == nullptr)
        {
            BSTNode * newNode = new BSTNode(data);
            root = newNode;
        }
        else if(root->getData() >= data)
        {
            root->setLeftChild(insert(root->getLeftChild(),data));
        }
        else if(root->getData() < data)
        {
            root->setRightChild(insert(root->getRightChild(),data));
        }
        return root;
    }

    void inorder(BSTNode * root)
    {
        if(root != nullptr) {
            inorder(root->getLeftChild());
            cout<< root->getData()<<" ";
            inorder(root->getRightChild());
        }

    }

    void preorder(BSTNode * root)
    {
        if(root != nullptr) {
            cout<< root->getData()<<" ";
            preorder(root->getLeftChild());
            preorder(root->getRightChild());
        }
    }

    void postorder(BSTNode * root)
    {
        if(root != nullptr) {
            postorder(root->getLeftChild());
            postorder(root->getRightChild());
            cout<< root->getData()<<" ";
        }
    }

    BSTNode* deleteNode(BSTNode * subTreeRoot,int data)
    {
        if(subTreeRoot == nullptr)
        {
            return subTreeRoot;
        }

        else if(subTreeRoot->getData() > data)
        {
            subTreeRoot->setLeftChild(deleteNode(subTreeRoot->getLeftChild(),data));
        }

        else if(subTreeRoot->getData() < data)
        {
            subTreeRoot->setRightChild(deleteNode(subTreeRoot->getRightChild(),data));
        }

        else{

            if(subTreeRoot->getLeftChild() == nullptr && subTreeRoot->getRightChild() == nullptr)//One Child
            {
                delete subTreeRoot;
                subTreeRoot = nullptr;
            }

            else if(subTreeRoot->getLeftChild() == nullptr) //One Child
            {
                BSTNode * temp = subTreeRoot;
                subTreeRoot = subTreeRoot->getRightChild();
                delete temp;
            }

            else if(subTreeRoot->getRightChild() == nullptr) //One Child
            {
                BSTNode * temp = subTreeRoot;
                subTreeRoot = subTreeRoot->getLeftChild();
                delete temp;
            }

            else{ //Two Children
                BSTNode * temp = getMin(subTreeRoot->getRightChild());
                subTreeRoot->setData(temp->getData());
                subTreeRoot->setRightChild(deleteNode(subTreeRoot->getRightChild(),temp->getData()));
            }

            return subTreeRoot;

        }
    }

    BSTNode * getMin(BSTNode * root)
    {
        if(root->getLeftChild() == nullptr)
            return root;

        getMin(root->getLeftChild());
    }

    void Serialize(BSTNode * root)
    {
        if(root == nullptr)
        {
            this->serialized += "N ";
            return;
        }
        this->serialized += to_string(root->getData())+" ";
        Serialize(root->getLeftChild());
        Serialize(root->getRightChild());
    }

    int getNumber()
    {
        string number;
        for(;this->iterator<this->serialized.length();this->iterator++)
        {
            if(this->serialized[iterator] == ' ')
            {
                this->iterator++;
                if(number.compare("N") == 0)
                    return -1;
                else
                    return stoi(number);
            }
                number += this->serialized[iterator];
        }
        return -2;
    }

    BSTNode* Deserialize(BSTNode* root,int number)
    {
        if(number == -1)
        {
            delete root;
            return nullptr;
        }
            root->setData(number);
            root->setLeftChild(new BSTNode(0));
            root->setRightChild(new BSTNode(0));
        root->setLeftChild(Deserialize(root->getLeftChild(),getNumber()));
        root->setRightChild(Deserialize(root->getRightChild(),getNumber()));
    }

public:
    BST()
    {
        this->root = nullptr;
        this->serialized = new char[50];
        this->iterator = 0;
    }

    void insert(int data)
    {
        this->root = insert(this->root,data);
    }

    void inorder()
    {
        inorder(this->root);
        cout<<"\n";
    }

    void preorder()
    {
        preorder(this->root);
        cout<<'\n';
    }

    void postorder()
    {
        postorder(this->root);
        cout<<'\n';
    }

    void getMin()
    {
        cout<<"The Minimum Value is "<< getMin(this->root)->getData()<<'\n';
    }

    void deleteNode(int data)
    {
        cout<<"Trying to delete the value = "<< data<<'\n';
        this->root = deleteNode(this->root,data);
    }

    void Serialize()
    {
        Serialize(this->root);
    }

    void PrintSerialized()
    {
        cout<<"The serialized string is "<<'\n';
        cout<<this->serialized<<'\n';
    }

    BST * Deserialize()
    {
        BST * b2 = new BST();
        b2->root = new BSTNode(0);
        Deserialize(b2->root,getNumber());
        this->iterator = 0;
        return b2;
    }

    ~BST()
    {
        while(this->root != nullptr)
            deleteNode(this->root->getData());
    }


};

int main()
{
    BST b1;
    b1.insert(25);
    b1.insert(23);
    b1.insert(27);
    b1.insert(22);
    b1.insert(24);
    b1.insert(26);
    b1.insert(28);
    b1.Serialize();
    b1.PrintSerialized();
    BST * b2 = b1.Deserialize();
    b1.inorder();
    b2->inorder();



    return 0;
}

