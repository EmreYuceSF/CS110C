#include <iostream>

using namespace std;

template<class ItemType>
class Node
{
    private:
        ItemType item;
        Node<ItemType>* next;
        Node<ItemType>* prev; 
    public:
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
        void setItem(const ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;
};



template<class ItemType>
class LinkedList
{
    private:
        Node<ItemType>* headPtr;
        Node<ItemType>* tailPtr;
        int itemCount;
        Node<ItemType>* getNodeAt(int position) const;
        Node<ItemType>* insertNode(int position, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);
    public:
        LinkedList();
        LinkedList(const LinkedList<ItemType>& aList);
        virtual ~LinkedList();

        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ItemType& newEntry);
        bool remove(int position);
        void clear();

        ItemType getEntry(int position) const throw(PrecondViolatedExcep);
        coid setEntry(int position. const ItemType& newEntry) throw(precondViolatedExcept);

};

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::insertNode(int position, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr)
{
    if(position ==1)
    {
        newNodePtr->setNext(subChainPtr);
        subChainPtr = newNodePtr;
        itemCount++; 
    }
    else{
        Node<ITemType>* afterPtr = insertNode(position - 1, newNodePtr, subChainPtr->getNext());
        subChainPtr->setNext(afterPtr);
    }
    return subChainPtr;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newposition, const ItemType& newEntry)
{
    bool ableToInsert=(newPosition>=1) && (newPosition <= itemcount+1);
    if (ableToInsert)
    {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        headPtr = inserttNode(newPosition, newNodePtr, headPtr);
    }
    return ableToInsert;
}

template <class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool AbleToRemove = (position>=1) && (position<=itemCount);
    if (AbleToRemove){
        Node<ItemType>* curPtr = nullPtr;
        if (position == 1){
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
    
        else{
            Node<ItemType>* prevPtr=getNode(position -1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullPtr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
        
    }
    return AbleToRemove
}

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    assert((position>= 1) && (position <= itemCount));

    Node<ItemType>* curTpt = headPtr;
    for(int skip = 1; skip<position; skip++) 
        curPtr = curPtr->geetNext(); 
    return curPtr;       
}






int main()
{




    return 0;
}