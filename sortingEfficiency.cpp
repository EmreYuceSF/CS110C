// Emre Yuce CS110C
// Assignment 4 - Sorting Efficiency
// demonstrating the merge Sort, bubble Sort, counting Sort and counting the interaction with the arrays for each sorting algorithm


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>



using namespace std;
// it is not recommended to have  global variables  but for this case I did not mind using for counting reason
int counter = 0; // counter starts from 0 and I have to remember every time to set it to 0 before new counting opreatrion
const int numNum = 101;  // this number of numbers will be use for creating count array and for generating random number from 0 to numNum (numNum exclusive)


int generateRandNum() // a simple function to create a single random number
{ 
    int random = rand() %numNum;
    return random;
}


void printArray(int* array,  const int SIZE) // this funciton prints out an array 
{
    for(int i =0; i<SIZE; i++)
    {
        if (i<SIZE-1)
            cout<<array[i]<<",";
        else
            cout<<array[i];
    }
    cout<<""<<endl;
}

void swapper(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void bubbleSort(int* array, int size)
{  
     
    bool swap = true;   // to start while loop 
    while (swap == true)
    {    
        swap = false; 
        for (int i=1; i<size; i++)
            {
                counter+=2; // +2 instead of +1 beacuse every time we compare two elements from the array
                if (array[i] < array[i-1]) // comparing 2 elements from array
                {
                
                swap = true;
                swapper(array[i], array[i-1]);  // program reaches same elements again to swap
                counter+=2;   
                }
            }
    }
    cout<<"In bubble-sort function we accessed the elements "<<counter<<" times."<<endl;
    counter = 0; //reset counter
}




template <class ItemType>
void merge(ItemType array[], int first, int middle, int last)
{
    
    int size = last-first+1;   // creating just enough size for every time we need will be more memory friendly
    ItemType* tempArray = new ItemType[size];
    int firstStart = first; // first half starting index
    int firstEnd = middle; // first half ending index
    int lastStart = middle+1; //second(last) half starting index
    int lastEnd = last; // second(last) half ending index
    int index = 0;
    while((firstStart<=firstEnd)&&(lastStart<=lastEnd))
    {
        counter+=2;
        if (array[firstStart]<array[lastStart])
        {
            tempArray[index++] = array[firstStart++];
            counter++;
        }
        else
        {
            tempArray[index++] = array[lastStart++];
            counter++;
        }
         
    }
    
    while (firstStart<=firstEnd)
    {
        counter++;
        tempArray[index++] = array[firstStart++];
    }
    while (lastStart<=lastEnd)
    {
        counter++;
        tempArray[index++] = array[lastStart++];
    }
    for (int i=0; i<size; i++)
    {
        counter+=1;
        array[first++]  = tempArray[i];        
    }
    delete [] tempArray;
    tempArray = nullptr;
    
}

template <class ItemType>
void mergeSort(ItemType array, int first, int last)
{
    if (first<last)
    {
        int mid = (first+last)/2; 
        mergeSort(array, first, mid); // recursion for the first half of the every current array 
        mergeSort(array, mid+1, last); // recursion for remaining half (last half)     
        merge(array, first, mid, last);     
    }
}


template <class ItemType>
void countingSort(ItemType* theArray, int size)
{
    ItemType* countArray=nullptr;
    countArray = new ItemType[numNum]; // this will initilize every element in this new array to 0
   
    for(int i = 0; i<size; i++)
    {
        counter++;
        countArray[theArray[i]]++;
    }
    int index = 0;
    for(int i = 0; i<numNum; i++)
    {
        while(countArray[i]>0)
        { 
            countArray[i]--;
            
            theArray[index] = i;
            index++;
            counter ++;
        }
    } 
    delete [] countArray;
} 


int main()
{    
    srand((unsigned) time(NULL));
    string space= string(20,'*');

    const int EIGHT = 8;       //sizes for tests
    const int THIRTYTWO = 32;
    const int HUNDREDAND = 128;
    
    int eightArray[EIGHT];
    int thirtyTwoArray[THIRTYTWO];
    int hundredAndArray[HUNDREDAND];
    
    //these eight lines of code will use for all 3 parts


    // counting for Bubble-Sort starts here
    for(int i = 0; i<EIGHT; i++) // for 8 elements
    {
        eightArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before BubbleSort: ";
    printArray(eightArray, EIGHT);
    bubbleSort(eightArray, EIGHT);
    cout<<"After Buble Sort:  ";
    printArray(eightArray, EIGHT);
    cout<<space<<endl;



    for(int i = 0; i<THIRTYTWO; i++) // for 32 elements  
    {
        thirtyTwoArray[i] = generateRandNum();
    }

    cout<<endl<<space<<endl;
    cout<<"Before BubbleSort: ";
    printArray(thirtyTwoArray, THIRTYTWO);
    bubbleSort(thirtyTwoArray, THIRTYTWO);
    cout<<"After BubbleSort:  ";
    printArray(thirtyTwoArray, THIRTYTWO);
    cout<<space<<endl;


    for(int i = 0; i<HUNDREDAND; i++)  // for 128 elemets
    {
        hundredAndArray[i] = generateRandNum();
    }
    
    
    cout<<endl<<space<<endl;
    cout<<"Before BubbleSort: ";
    printArray(hundredAndArray, HUNDREDAND);
    bubbleSort(hundredAndArray, HUNDREDAND);
    cout<<"After BubbleSort:  ";
    printArray(hundredAndArray, HUNDREDAND);
    cout<<space<<endl;
    
    counter = 0;
    // couinting bubble sort ends here!

   
   
    //counting for merge-sort starts here!
    for(int i = 0; i<EIGHT; i++) // for 8 elements
    {
        eightArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before MergeSort: ";
    printArray(eightArray, EIGHT);
    mergeSort(eightArray, 0, EIGHT-1);
    cout<<"In Merge-Sort function we accessed the elements "<<counter<<" time"<<endl;
    counter = 0;
    cout<<"After MergeSort:  ";
    printArray(eightArray, EIGHT);
    cout<<space<<endl;

    for(int i = 0; i<THIRTYTWO; i++) // for 32 elements  
    {
        thirtyTwoArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before MergeSort: ";
    printArray(thirtyTwoArray, THIRTYTWO);
    mergeSort(thirtyTwoArray, 0, THIRTYTWO-1);
    cout<<"In Merge-Sort function we accessed the elements "<<counter<<" time"<<endl;
    counter = 0;
    cout<<"After MergeSort:  ";
    printArray(thirtyTwoArray, THIRTYTWO);
    cout<<space<<endl;


    for(int i = 0; i<HUNDREDAND; i++)  // for 128 elemets
    {
        hundredAndArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before MergeSort: ";
    printArray(hundredAndArray, HUNDREDAND);
    mergeSort(hundredAndArray,0,HUNDREDAND-1);
    cout<<"In Merge-Sort function we accessed the elements "<<counter<<" time"<<endl;
    counter = 0;
    cout<<"After MergeSort:  ";
    printArray(hundredAndArray, HUNDREDAND);
    cout<<space<<endl;



  
    for(int i = 0; i<EIGHT; i++) // for 8 elements
    {
        eightArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before CountingSort: ";
    printArray(eightArray, EIGHT);
    countingSort<int>(eightArray, EIGHT);
    cout<<"In counting-sort function we accessed the elements "<<counter<<" time"<<endl;
    cout<<"After CountingSort:  ";
    printArray(eightArray, EIGHT);
    counter = 0;
    cout<<space<<endl;
    
    for(int i = 0; i<THIRTYTWO; i++) // for 32 elements  
    {
        thirtyTwoArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before CountingSort: ";
    printArray(thirtyTwoArray, THIRTYTWO);
    countingSort<int>(thirtyTwoArray, THIRTYTWO);
    cout<<"In counting-sort function we accessed the elements "<<counter<<" time"<<endl;
    cout<<"After CountingSort:  ";
    printArray(thirtyTwoArray, THIRTYTWO);
    counter = 0;
    cout<<space<<endl;
    
    

    for(int i = 0; i<HUNDREDAND; i++)  // for 128 elemets
    {
        hundredAndArray[i] = generateRandNum();
    }
    cout<<endl<<space<<endl;
    cout<<"Before CountingSort: ";
    printArray(hundredAndArray, HUNDREDAND);
    countingSort<int>(hundredAndArray, HUNDREDAND);
    cout<<"In counting-sort function we accessed elements "<<counter<<" time"<<endl;
    cout<<"After CountingSort:  ";
    printArray(hundredAndArray, HUNDREDAND);
    counter = 0;
    cout<<space<<endl;
    //counting for merge-sort ends here!
    
    return 0;
}


/* OUTPUT
********************
Before BubbleSort: 86,71,23,43,98,64,79,39
In bubble-sort function we accessed the elements 130 times.
After Buble Sort:  23,39,43,64,71,79,86,98
********************

********************
Before BubbleSort: 93,33,18,78,36,75,85,11,55,97,86,42,76,18,61,90,25,1,35,34,85,25,5,80,1,80,69,75,99,67,34,31
In bubble-sort function we accessed the elements 2014 times.
After BubbleSort:  1,1,5,11,18,18,25,25,31,33,34,34,35,36,42,55,61,67,69,75,75,76,78,80,80,85,85,86,90,93,97,99
********************

********************
Before BubbleSort: 3,64,25,41,51,53,12,0,54,32,92,22,22,45,60,50,17,12,0,85,100,54,90,60,30,7,66,15,77,0,68,43,34,41,13,74,21,96,1,26,70,84,75,23,74,38,69,26,98,45,32,46,12,27,54,99,13,87,55,52,56,2,93,14,10,19,59,25,13,52,95,52,12,53,5,67,76,65,49,19,55,1,10,42,87,23,44,42,90,80,32,50,92,94,0,45,68,3,26,86,69,94,59,61,89,92,42,12,64,61,42,55,5,57,18,93,90,30,61,41,22,47,99,8,22,0,86,84
In bubble-sort function we accessed the elements 38406 times.
After BubbleSort:  0,0,0,0,0,1,1,2,3,3,5,5,7,8,10,10,12,12,12,12,12,13,13,13,14,15,17,18,19,19,21,22,22,22,22,23,23,25,25,26,26,26,27,30,30,32,32,32,34,38,41,41,41,42,42,42,42,43,44,45,45,45,46,47,49,50,50,51,52,52,52,53,53,54,54,54,55,55,55,56,57,59,59,60,60,61,61,61,64,64,65,66,67,68,68,69,69,70,74,74,75,76,77,80,84,84,85,86,86,87,87,89,90,90,90,92,92,92,93,93,94,94,95,96,98,99,99,100
********************

********************
Before MergeSort: 82,32,26,12,39,62,34,27
In Merge-Sort function we accessed the elements 78 time
After MergeSort:  12,26,27,32,34,39,62,82
********************

********************
Before MergeSort: 68,31,71,50,96,90,15,69,42,30,79,79,50,24,88,30,0,18,20,92,68,60,77,85,32,31,25,27,86,1,56,25
In Merge-Sort function we accessed the elements 562 time
After MergeSort:  0,1,15,18,20,24,25,25,27,30,30,31,31,32,42,50,50,56,60,68,68,69,71,77,79,79,85,86,88,90,92,96
********************

********************
Before MergeSort: 10,4,30,99,53,56,19,37,34,86,74,91,64,32,84,25,69,25,83,98,28,95,28,96,4,76,30,18,47,64,71,15,71,42,42,55,65,30,80,29,73,58,90,95,34,6,53,36,94,100,59,24,31,50,54,90,40,47,24,7,70,90,83,41,13,41,58,11,75,92,26,23,80,42,53,24,54,14,81,44,27,87,50,37,54,42,45,21,46,90,60,72,90,60,48,61,27,30,51,43,19,36,68,37,2,22,34,47,1,66,74,36,28,89,60,52,93,98,61,28,85,23,72,22,45,59,66,55
In Merge-Sort function we accessed the elements 3252 time
After MergeSort:  1,2,4,4,6,7,10,11,13,14,15,18,19,19,21,22,22,23,23,24,24,24,25,25,26,27,27,28,28,28,28,29,30,30,30,30,31,32,34,34,34,36,36,36,37,37,37,40,41,41,42,42,42,42,43,44,45,45,46,47,47,47,48,50,50,51,52,53,53,53,54,54,54,55,55,56,58,58,59,59,60,60,60,61,61,64,64,65,66,66,68,69,70,71,71,72,72,73,74,74,75,76,80,80,81,83,83,84,85,86,87,89,90,90,90,90,90,91,92,93,94,95,95,96,98,98,99,100
********************

********************
Before CountingSort: 93,18,39,83,99,51,26,83
In counting-sort function we accessed the elements 16 time
After CountingSort:  18,26,39,51,83,83,93,99
********************

********************
Before CountingSort: 94,20,73,0,25,63,26,87,64,65,97,80,69,32,82,54,60,54,31,45,40,49,27,75,16,57,6,49,85,36,29,76
In counting-sort function we accessed the elements 64 time
After CountingSort:  0,6,16,20,25,26,27,29,31,32,36,40,45,49,49,54,54,57,60,63,64,65,69,73,75,76,80,82,85,87,94,97
********************

********************
Before CountingSort: 88,11,14,3,99,14,7,37,8,100,56,63,10,20,79,23,19,98,85,43,71,22,20,13,47,37,5,26,41,13,10,55,5,98,85,62,72,53,18,49,73,43,31,14,60,69,77,22,26,15,93,40,96,75,85,13,19,43,18,57,2,83,5,78,92,1,16,71,10,26,11,55,63,62,67,50,91,95,43,12,59,74,21,84,23,47,54,92,34,68,88,40,56,94,45,14,42,43,72,30,39,96,43,34,73,85,30,75,8,23,61,40,45,13,88,16,91,87,63,14,15,10,67,99,54,26,8,91
In counting-sort function we accessed elements 256 time
After CountingSort:  1,2,3,5,5,5,7,8,8,8,10,10,10,10,11,11,12,13,13,13,13,14,14,14,14,14,15,15,16,16,18,18,19,19,20,20,21,22,22,23,23,23,26,26,26,26,30,30,31,34,34,37,37,39,40,40,40,41,42,43,43,43,43,43,43,45,45,47,47,49,50,53,54,54,55,55,56,56,57,59,60,61,62,62,63,63,63,67,67,68,69,71,71,72,72,73,73,74,75,75,77,78,79,83,84,85,85,85,85,87,88,88,88,91,91,91,92,92,93,94,95,96,96,98,98,99,99,100
********************
*/