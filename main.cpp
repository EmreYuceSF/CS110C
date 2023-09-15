// Emre Yuce CS110C 
// Assignment 3 - Reverse /  I turned linked List to Doubly Linked List and add reverse function to the LinkedList class. 


//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	cout << "The list contains " << endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl << endl;
}  // end displayList

void listTester()
{
	ListInterface<string>* listPtr = new LinkedList<string>();
   
	cout << "Testing the Doubly-Link-Based List:" << endl;
	string data[] = {"one", "two", "three", "four", "five", "six"};
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
	for (int i = 0; i < 6; i++)
   {
		if (listPtr->insert(i + 1, data[i]))
         cout << "Inserted " << listPtr->getEntry(i + 1)
         << " at position " << (i + 1) << endl;
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1)
         << endl;
	}  // end for
   
   displayList(listPtr);
   
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;
   
   cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
   
   cout << "After replacing the entry at position 3 with XXX: ";
   listPtr->setEntry(3, "XXX");
   displayList(listPtr);
 
   
   
} // end listTester 

void myTest()
{
   LinkedList<string>* list = new LinkedList<string>();
   Node<string>* headPtr = nullptr;
   Node<string>* tailPtr = nullptr;
   Node<string>* curr = nullptr;
   string data[] = {"one", "two", "three", "four", "five", "six"};
   for (int i = 0; i < 6; i++)
   {
		if (list->insert(i + 1, data[i]))
         cout << "Inserted " << list->getEntry(i + 1)
         << " at position " << (i + 1) << endl;
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1)
         << endl;
	}  // end for

   headPtr = list->getHead();
   tailPtr = list->getTail();
   curr = headPtr;
   cout<<"Using getNext() -> moves from head to tail"<<endl;
   while (curr)
   {
      cout<<curr->getItem()<<endl;
      curr = curr->getNext();
   }


   curr = tailPtr;
   cout<<"Using getPrev() -> moves from tail to head"<<endl;
   while (curr)
   {
      cout<<curr->getItem()<<endl;
      curr = curr->getPrev();
   }

   list->reverse();
   cout<<"Doubly Linked List is reversed now!"<<endl;

   headPtr = list->getHead();
   tailPtr = list->getTail();
   curr = headPtr;
   cout<<"Using getNext() -> moves from head to tail"<<endl;
   while (curr)
   {
      cout<<curr->getItem()<<endl;
      curr = curr->getNext();
   }


   curr = tailPtr;
   cout<<"Using getPrev() -> moves from tail to head"<<endl;
   while (curr)
   {
      cout<<curr->getItem()<<endl;
      curr = curr->getPrev();
   }
   list->remove(3);
   cout<<"removing node three and four will be removed because of list is reversed!"<<endl;
   headPtr = list->getHead();
   tailPtr = list->getTail();
   curr = headPtr;
   cout<<"Using getNext() -> moves from head to tail"<<endl;
   while (curr)
   {
      cout<<curr->getItem()<<endl;
      curr = curr->getNext();
   }
   
}


int main()
{
   listTester();
   cout<<"The output above this line shows my implantation did not break the code!"<<endl;
   myTest();
  
   return 0;
}  // end main


/* 
emreyuce <LinkedList> -> ./a.out 
Testing the Doubly-Link-Based List:
isEmpty: returns 1; should be 1 (true)
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
The list contains 
one two three four five six 

isEmpty: returns 0; should be 0 (false)
getLength returns : 6; should be 6
The entry at position 4 is four; should be four
After replacing the entry at position 3 with XXX: The list contains 
one two XXX four five six 

The output above this line shows my implantation did not break the code!
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
Using getNext() -> moves from head to tail
one
two
three
four
five
six
Using getPrev() -> moves from tail to head
six
five
four
three
two
one
Doubly Linked List is reversed now!
Using getNext() -> moves from head to tail
six
five
four
three
two
one
Using getPrev() -> moves from tail to head
one
two
three
four
five
six
removing node three and four will be removed because of list is reversed!
Using getNext() -> moves from head to tail
six
five
three
two
one
 */