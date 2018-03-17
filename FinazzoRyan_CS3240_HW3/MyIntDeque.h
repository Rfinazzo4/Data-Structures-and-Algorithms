/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyIntDeque.h
 * Author: Ryanfinazzo
 *
 * Created on October 24, 2017, 7:58 PM
 */

#ifndef MYINTDEQUE_H
#define MYINTDEQUE_H

class MyIntDeque{
private:
    int* List;
    int cap;
    int length;
    int first;
    int last;
public: 
    MyIntDeque(int);
    ~MyIntDeque();
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    int size();
    int front();
    int back();
    bool isFull();
    bool isEmpty();
    void clear();
};


MyIntDeque::MyIntDeque(int i){
    cap = i;
    length = 0;
    List= new int[cap];
    for(int j=0; j<cap;j++){
        List[i]=0;
    }
    
}

MyIntDeque::~MyIntDeque(){
    delete [] List;
}

void MyIntDeque::push_back(int i){
    if (isFull()){
        return;
    }
    else if (isEmpty()){
        first=0;
        last=0;
        List[first] = i;
        length++;
    }
    else {
        List[last+1]=i;
        last++;
        length++;
    }
}

void MyIntDeque::push_front(int i){
    if (isFull()){
        return;
    }
    else if (isEmpty()){
        first = 0;
        last = 0;
        List[first] = i;
        length++;
    }
    else { 
        int temp=last;
        for(int j=0; j<=last;j++){
            List[temp+1]=List[temp];
            temp--;
        }
        List[first]=i;
        last++;
        length++;
    }
}

void MyIntDeque::pop_back(){
    if (isEmpty()){
         return;
    }
    List[last]=0;
    last--;
    length--;
}

void MyIntDeque::pop_front(){
    if (isEmpty()){
        return;
    }
    int temp = first;
    for(int i=0; i<last;i++){
      List[temp]=List[temp+1];
      temp++;
    }
    List[temp]=0;
    last--;
    length--;
}

int MyIntDeque::size(){
    return length;
}

int MyIntDeque::front(){
    if (isEmpty()){
        return 0;
    }
    return List[first];
}
int MyIntDeque::back(){
     if (isEmpty()){
        return 0;
    }
    return List[last];
}
bool MyIntDeque::isEmpty(){
    if (length==0){
        return true;
    }
    else{
        return false;
    }
}

bool MyIntDeque::isFull(){
    if (length==cap){
        return true;
    }
    else{
        return false;
    }
}

void MyIntDeque::clear(){
    for(int i=0; i<cap;i++){
        List[i]=0;
    }
    first = 0;
    last=0;
    length=0;
}
#endif /* MYINTDEQUE_H */

