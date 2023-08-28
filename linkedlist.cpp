#include <iostream>

using namespace std;

template<class ItemType>
class Node
{
    private:
        ItemType item;
        Node<ItemType>* next;
    public:
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
        void setItem(const ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;
};

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNode


template<class ItemType>
class LinkedList
{
    private:
        Node<ItemType>* headPtr;

        int itemCount;

        Node<ItemType>* getNodeAt(int position) const;
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




int main()
{




    return 0;
}