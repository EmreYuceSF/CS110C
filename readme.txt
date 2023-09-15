Emre Yuce CS110C Assignment 3 - Reverse
I implemented reverse function and turned the Linked List to Doubly Linked List

I created extra Swapper class which was not necessary at all but I wanted to experience it.

Output 

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