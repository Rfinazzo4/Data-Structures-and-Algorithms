/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ryanfinazzo
 *
 * Created on November 30, 2017, 9:32 PM
 */

#include "HashTable.h"

#include<iostream>
using std::cout;
using std::endl;


int main()
{
	HashTable h(5);
	
	cout << h.isFull() << ", " << h.isEmpty() << endl;
	
	h.insert("Hello!");
	h.insert("Hello!");
	h.insert("How");
	h.insert("Are");
	h.insert("You?");
	h.print();
	h.remove("Hello!");
	h.remove("Hello!");
	h.print();
	
	cout << h.isFull() << ", " << h.isEmpty() << endl;
	
	cout << h.find("How") << ", " << h.find("Hello") << endl;
	cout << h.find("Dog") << endl;
	
	h.remove("Dog");
	h.print();
	h.clear();
	h.print();
}