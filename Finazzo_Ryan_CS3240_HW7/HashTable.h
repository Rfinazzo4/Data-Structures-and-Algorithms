/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashTable.h
 * Author: Ryanfinazzo
 *
 * Created on November 30, 2017, 9:35 PM
 */


#include <iostream>
#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

class HashTable{
private:
    struct Element{
        string key;
        int mark;
    };
    
    Element* table;
    int size;
    int hash(string);
public:
    HashTable(int);
    ~HashTable();
    void insert(string);
    void remove(string);
    bool isFull();
    bool isEmpty();
    void clear();
    void print();
    bool find(string);
};

    HashTable::HashTable(int s){
        size=s;
        table = new Element[size];
        for (int i=0; i<size; i++){
            table[i].mark=0;
        }
    }
    
    HashTable::~HashTable(){
        delete [] table;
    }
    
    void HashTable::insert(string k){
        int i = hash(k);
        int j;
        if (i==0){
            j=size;
        }
        else {
            j=i-1;
        }
        while (table[i].mark==2){
            if(i==j){
                return;
            }
            if(i==size){
                i=0;
            }
            else{
                i++;
            }
        }
        
        table[i].key=k;
        table[i].mark = 2;
    }
    
    void HashTable::remove(string x){
        if (find(x)){
            for (int i=0; i<size;i++){
                if (table[i].key==x && table[i].mark == 2){
                    table[i].mark =1;
                    return;
                }
            }
        }
        
    }
    bool HashTable::isFull(){
        for (int i=0; i<size; i++){
            if (table[i].mark!=2){
                return false;
               }
        }
        return true;
    }
    bool HashTable::isEmpty(){
         for (int i=0; i<size; i++){
            if (table[i].mark==2){
                return false;
               }
        }
        return true;
    }
    void HashTable::clear(){
        for (int i=0; i<size;i++){
            table[i].mark=0;
        }
    }
    
    void HashTable::print(){
        for (int i=0;i<size; i++){
            if (table[i].mark == 2){
                cout<<table[i].key<<endl;
            }
        }
    }
    bool HashTable::find(string x){
        for (int i=0; i<size;i++){
            if(table[i].key == x && table[i].mark==2){
                return true;
            }
        } 
        return false; 
    }
     int HashTable::hash(string x){
         int ascii=0;
         for (int i =0; i<x.length();i++){
             ascii=ascii + x[i];
         }
         return (ascii%size);
     }

#endif /* HASHTABLE_H */

