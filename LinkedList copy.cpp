// Emre Yuce CS110C 
// Assignment 3 - Reverse /  I turned linked List to Doubly Linked List and add reverse function to the LinkedList class. 


//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>
#include "Swapper.h" // Very needed 

template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
   headPtr = nullptr;
   tailPtr = nullptr;
   itemCount = 0;

}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount) //I wish that I've read all the instructions fully before starting the assignment, I've changed here too and hope it works 🤷‍♂️
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr){
      headPtr = nullptr;  // Original list is empty
      tailPtr = nullptr; 
   }
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      tailPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      

      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last!!!(maybe first) node in new chain
       
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         ItemType prevItem = newChainPtr->getItem();
         
         
         // Create a new node containing the next item 
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
         
         
         // Link new node to end of new chain
         newNodePtr->setPrev(newChainPtr); // that was the key touch!
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
      tailPtr->setPrev(newChainPtr);  // since we now newChainPtr points to the last node we can let tail to point that 
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  
      
      // This implementation ignores newPosition, and always put the new
      // item at the beginning of the list.
      // Your assignment is to correctly insert the item into newPosition
      if (!itemCount){
         headPtr = newNodePtr;
         tailPtr = newNodePtr;
      }
      
      else if (newPosition==1)
      {

         newNodePtr->setNext(headPtr);
         headPtr->setPrev(newNodePtr); 
         headPtr = newNodePtr;

      }
      else if (newPosition == itemCount+1) // if is going to the append to the end of the list
      {
         Node<ItemType>* lastNodePtr = getNodeAt(newPosition-1);
         newNodePtr->setPrev(lastNodePtr);
         lastNodePtr->setNext(newNodePtr);
         tailPtr = lastNodePtr->getNext();
         
  
      }
      else
      {
         Node<ItemType>* prevPtr = getNodeAt(newPosition- 1);
         Node<ItemType>* nextPtr = getNodeAt(newPosition); //current Node before inserting 
         newNodePtr->setPrev(prevPtr);
         newNodePtr->setNext(nextPtr);
         nextPtr->setPrev(newNodePtr);
         prevPtr->setNext(newNodePtr);
      }
      

      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
         headPtr->setPrev(nullptr);

      }
      else if (position == itemCount)
      {
         curPtr = tailPtr;
         tailPtr = tailPtr->getPrev();
         tailPtr->setNext(nullptr);
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         Node<ItemType>* nextPtr = curPtr->getNext();
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         nextPtr->setPrev(prevPtr);
         prevPtr->setNext(nextPtr);
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      curPtr->setPrev(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position."; 
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt

template<class ItemType>
void  LinkedList<ItemType>::reverse()
{
   
   Node<ItemType>* curr = headPtr;
   Node<ItemType>* next = nullptr;
   Node<ItemType>* prev = nullptr;
   
   while(curr!= nullptr)
   {
      next = curr->getNext();
      prev = curr->getPrev();
      curr->setNext(prev);
      curr->setPrev(next);
      curr = curr->getPrev();
      
   }
     
   swap(headPtr, tailPtr);   
   
}





// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;

