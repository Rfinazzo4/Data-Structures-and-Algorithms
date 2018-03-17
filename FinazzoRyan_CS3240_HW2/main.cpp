/* 
 * File:   main.cpp
 * Author: Ryan Finazzo
 * Created on January 5th 2017
 * 
 */
//System Libraries 
#include "AddressBook.h"
#include<iostream>
#include <string>
using namespace std;

string getName();
string getPhone();
void isFull(const AddressBook&);
void isEmpty(const AddressBook&);

int main()
{
	AddressBook a;
	char choice;
	
	do
	{
		string name, phone;
		
		cout << "A-Add Contact\n";
		cout << "R-Remove Contact\n";
		cout << "F-Find Contact\n";
		cout << "C-Clear Contacts\n";
		cout << "E-isEmpty\n";
		cout << "U-isFull\n";
		cout << "Q-Quit\n";
		cout << "> ";
		
		cin >> choice;
		cin.ignore();
		
		switch(choice)
		{
			case 'A':
			case 'a':
				name = getName();
				phone = getPhone();
				a.add(name, phone);
			break;
			case 'R':
			case 'r':
				name = getName();
				a.remove(name);			
			break;
			case 'F':
			case 'f':
				name = getName();
				cout << a.find(name) << endl;
			break;
			case 'C':
			case 'c':
				a.clear();
			break;
			case 'E':
			case 'e':
				isEmpty(a);
			break;
			case 'U':
			case 'u':
				isFull(a);
			break;
		}	
	} while(choice != 'Q' && choice != 'q');
}

string getName()
{
	string n;
	
	cout << "Enter contact's name: ";
	getline(cin, n);
	
	return n;
}

string getPhone()
{
	string p;
	
	cout << "Enter contact's number: ";
	getline(cin, p);
	
	return p;
}

void isFull(const AddressBook& r)
{
	if(r.isFull())
		cout << "AddressBook is full.\n";
	else
		cout << "AddressBook isn't full.\n";
}


void isEmpty(const AddressBook& r)
{
	if(r.isEmpty())
		cout << "AddressBook is empty.\n";
	else
		cout << "AddressBook isn't empty.\n";
}