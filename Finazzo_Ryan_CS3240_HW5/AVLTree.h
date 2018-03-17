/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTree.h
 * Author: Ryanfinazzo
 *
 * Created on November 14, 2017, 8:41 PM
 */
#include <iostream>

#ifndef AVLTREE_H
#define AVLTREE_H
using namespace std;

class AVLTree{
private: 
    struct Node{
        int value;
        Node* left;
        Node* right;
    };
    Node* root;
   
    void clear (Node*& root);
    int height (Node* root);
    void rotateRight (Node *& root);
    void rotateLeft (Node *& root);
    void rotateRightLeft (Node*& root);
    void rotateLeftRight (Node*& root);
    int difference (Node* root);
    void balance (Node*& root);
    void append (Node*& root, int value);
    void remove (Node*& root, int value);
    bool find (Node* root, int value);
    void print (Node* root);

public:
    AVLTree();
    ~AVLTree();
    void clear ();
    void append (int value);
    void remove (int value);
    bool find (int value); 
    void print ();
    bool isEmpty ();
    bool isFull ();  
};

AVLTree::AVLTree(){
    root = NULL;
}

AVLTree::~AVLTree(){
    clear();
}

int AVLTree::height(Node* r){
    if (r == NULL){
        return 0;
    }
    else{
        int lefti;
        int righti;
        lefti=height(r->left);
        righti=height(r->right);
        if (lefti > righti){
            return lefti+1;
        }
        else{
            return righti+1;
        }
    }
}

void AVLTree::rotateRight(Node*& ptr){
    Node* temp;
    temp=ptr->left;
    ptr->left=temp->right;
    temp->right = ptr;
    ptr = temp;
}

void AVLTree::rotateLeft(Node*& ptr){
    Node* temp;
    temp=ptr->right;
    ptr->right=temp->left;
    temp->left= ptr;
    ptr=temp;
}

void AVLTree::rotateRightLeft(Node*& ptr){
    rotateRight(ptr->right);
    rotateLeft(ptr);
}

void AVLTree::rotateLeftRight(Node*& ptr){
    rotateLeft(ptr->left);
    rotateRight(ptr);
}

int AVLTree::difference(Node* r){
    int bf;
    bf = height(r->right) - height(r->left);
    return bf;
}

void AVLTree::balance(Node*& r){
    if (difference(r) == -2){
        if (difference(r->left)==-1){
            rotateRight(r);
        }
        else {
            rotateLeftRight(r);
        }
    }
    else if (difference(r)==2){
        if (difference(r->right)==1){
            rotateLeft(r);
        }
        else {
            rotateRightLeft(r);
        }
    }
}

void AVLTree::append(int v){
    append(root, v);
}

void AVLTree::append(Node*& r, int v){
    if (r == NULL){
        r=new Node;
        r->value =v;
        r->left=NULL;
        r->right=NULL;
    }
    else if (v<r->value){
        append(r->left, v);
        balance(r);
    }
    else{
        append(r->right, v);
        balance(r);
    }
}

void AVLTree::remove(int v){
    remove(root, v);
}

void AVLTree::remove(Node*& r, int v){
    if (r==NULL){
        return;
    }
    else if (v<r->value){
        remove(r->left, v);
    }
    else if (v>r->value){
        remove(r->right, v);
    }
    else {
        if ((r->left) ==NULL && (r->right)==NULL){
            delete r;
            r=NULL;
        }
        else if ((r->left)!=NULL && (r->right)==NULL){
            Node* p;
            p=r;
            r=(r->left);
            delete r;
        }
        else if((r->left) == NULL && (r->right)!=NULL){
            Node* p;
            p=r;
            r=(r->right);
            delete r;
        }
        else{
            Node* p;
            while ((p->left) != NULL){
                p=p->left;
            }
            p->left =r->left;
            p=r;
            r=r->right;
            delete p;
        }   
    }
}

bool AVLTree::find(int v){
    return find(root, v);
    
}

bool AVLTree::find(Node* r, int v){
    if (r==NULL){
        return false;
    }
    else if ((r->value)==v){
        return true;
    }
    else if (v<(r->value)){
        
        return find((r->left), v);
    }
    else {
        return find((r->right), v);
    }
}

void AVLTree::print(){
    print(root);
}

void AVLTree::print(Node* r){
    if (r!=NULL){
        print(r->left);
        cout<<"Data"<<r->value<<endl;
        cout<<"Height"<<height(r)<<endl;
        print(r->right);
    }
}

bool AVLTree::isEmpty(){
    if (root==NULL){
        return true;
    }
    else {
        return false;
    }
}

bool AVLTree::isFull(){
    Node* temp = new Node;
    if (temp == NULL){
        return true;
    }
    else {
        return false ;
    }
}

void AVLTree::clear(){
    clear(root);
}

void AVLTree::clear(Node*& r){
    if (r!=NULL){
        clear(r->left);
        clear (r->right);
        delete r;
        r=NULL;
    }
}

#endif /* AVLTREE_H */

