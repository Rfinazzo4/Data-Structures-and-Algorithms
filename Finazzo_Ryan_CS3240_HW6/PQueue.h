/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PQueue.h
 * Author: Ryan finazzo
 *
 * Created on November 27, 2017, 7:42 PM
 */

#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>

using namespace std;


class PQueue{
private:
    int* heap;
    int size;
    int bottom;
    void ReHeapUp();
    void ReHeapDown();
    
public: 
    PQueue(int);
    ~PQueue();
    void enqueue(int);
    void dequeue();
    int top();
};

PQueue::PQueue(int s){
    size =s;
    heap = new int [s];
    bottom =-1;
}

PQueue::~PQueue(){
    delete [] heap;
    
}

void PQueue::enqueue(int i){
    if ( bottom !=size){
        bottom++;
        heap[bottom]=i;
        ReHeapUp();
    }  
}
void PQueue::dequeue(){
    if (bottom!=-1){
        heap[0]=heap[bottom];
        bottom--;
        ReHeapDown();
        
    }
}
int PQueue::top(){
    if(bottom!=-1){
        return heap[0];
    }
    return -1;
}
void PQueue::ReHeapDown(){
    int p=top();
    int lc;  //left child
    int rc;  //right child
    int bc; //base child
    while (p<bottom){
        lc=(2*p)+1;
        rc=(2*p)+2;
        if (lc==bottom){
            if (lc==bottom){
                bc=lc;
            }
            else{
                if (heap[lc] > heap[rc]) {
                    bc=lc;
                }
                else {
                    bc=rc;
                }
            }
        }
        else{
            return;
        }
        if (heap[p]<heap[bc]){
            int temp = heap[p];
            heap[p]=heap[bc];
            heap[bc]=temp;
            p=bc;
        }
        else {
            return;
        }
    }
}

void PQueue::ReHeapUp(){
    
    int i = bottom;
    int p;
    while (i!=0){
        p = (i-1)/2;
        if (heap[i]>heap[p]){
            int temp=heap[i];
            heap[i]=heap[p];
            heap[p]=temp;  
        }
        else{
            return;
        }
        i=p;
    }
}
#endif /* PQUEUE_H */

