/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AddressBook.h
 * Author: Ryanfinazzo
 *
 * Created on October 1, 2017, 10:10 PM
 */

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include<string>
using namespace std;

class AddressBook
{
	private:
	struct Contact
	{
		string name, phone;
		Contact* next;
	};
	Contact* List = new Contact;
	public:
	AddressBook();
	~AddressBook();
	bool isEmpty() const;
	bool isFull() const;
	void add(string, string);
	void remove(string);
	void clear();
	bool find(string) const;
};

AddressBook::AddressBook() {
            
    List->next = NULL;
            
}

AddressBook::~AddressBook() {
    clear();
}

bool AddressBook::isEmpty() const{
    if (List->next == NULL){
        return true;
    }
    else {
        return false; 
    } 
}

bool AddressBook::isFull() const{
    Contact* dummy = new Contact;
    if (dummy==NULL){
        delete dummy;
        return true;
    }
    else{
        delete dummy;
        return false;
    }
    
}
    

void AddressBook::add(string name , string phone){
    Contact* node = new Contact;
    if (isEmpty()){
        List = node;
        node->name = name;
        node->phone = phone; 
        node->next=NULL;
    }    
    else{
     Contact* temp = new Contact;
     while(temp->next!=NULL){
         temp=temp->next;
    }
        temp->next=node;
        node->next=NULL;
        node->name = name;
        node->phone = phone; 
    }
}

void AddressBook::remove(string name){
    if(isEmpty()){
        return;
    }
    Contact* prev = new Contact;
    Contact* curr = new Contact;
    curr=List->next;
    prev = List;
    if(prev->name == name){
        List=List->next;
        delete prev;
        delete curr;
        return;
    }
    while(curr !=NULL){
        if(curr->name!=name){
        prev=curr;
        curr=curr->next;
        }
        else{
            prev->next = curr->next;
            delete curr;
            return;
        }
    }
}
void AddressBook::clear(){
    while(List!=NULL){
        Contact* temp= new Contact;
        temp=List;
        List=List->next;
        delete temp;
    }
}

bool AddressBook::find(string name) const{
    if(isEmpty()){
        return false;
    }
    Contact* temp=new Contact;
    temp=List;
    while (temp!=NULL){
        if(temp->name == name){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
}
#endif