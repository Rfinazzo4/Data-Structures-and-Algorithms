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
		bool used;
	};
	Contact* List;
	int cap;
	public:
	AddressBook(int);
	~AddressBook();
	bool isEmpty() const;
	bool isFull() const;
	void add(string, string);
	void remove(string);
	void clear();
	string find(string) const;
};

AddressBook::AddressBook(int size) {
            cap = size;
            List = new Contact [cap];
            clear();
            
}

AddressBook::~AddressBook() {
    delete [] List;
}

bool AddressBook::isEmpty() const{
    for (int i=0; i<cap; i++){
        if (List[i].used == false){
            
        }
        else{
            return false;
        }
    }
    return true;
}

bool AddressBook::isFull() const{
    for (int i=0; i<cap; i++){
        if (List[i].used == false){
            return false;
        }
    }
    return true;
}

void AddressBook::add(string name , string phone){
    for (int i=0; i<cap; i++){
        if (List[i].used == false){
            List[i].name = name;
            List[i].phone = phone;
            List[i].used = true;
            break;
        }
    }
}

void AddressBook::remove(string name){
    for (int i=0; i < cap; i++){
                if (List[i].name == name){
                    List[i].used =false;
                    break;
                }
            }
}
void AddressBook::clear(){
    for (int i=0; i<cap; i++){
        List[i].used = 0;
    }
}

string AddressBook::find(string name) const{
    for (int i=0; i<cap; i++){
        if (List[i].name == name){
            return List->phone;
        }
    }
    return "NO MATCH";
}
#endif