#include <iostream>

using namespace std;

template <class ItemType>
void printArray(ItemType array[], int first, int last)
{
    for(int i = first; i<=last; i++)
    {
        cout<<array[i]<<" ";
    }  
    cout<<""<<endl;
}

template <class ItemType>
void merge(ItemType array[], int first, int middle, int last)
{
    
    int size = last-first+1; 
    ItemType tempArray[size];
    int firstStart = first;
    int firstEnd = middle;
    int lastStart = middle+1;
    int lastEnd = last;
    int index = 0;
    while((firstStart<=firstEnd)&&(lastStart<=lastEnd))
    {
        if (array[firstStart]<array[lastStart])
            tempArray[index++] = array[firstStart++];
        else
            tempArray[index++] = array[lastStart++];
        
         
    }
    
    while (firstStart<=firstEnd)
    {
        tempArray[index++] = array[firstStart++];
    }
    while (lastStart<=lastEnd)
    {
        tempArray[index++] = array[lastStart++];
    }
    for (int i=0; i<size; i++)
    {
        array[first++]  = tempArray[i];
        
       
    }
    
    
    
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




int main()
{

    int testArray[] = {20,80,60,34,23,33};
        cout<<"\n\nUnsorted: ";
    for(int i = 0; i<6; i++)
    {
        cout<<testArray[i]<<" ";
    }
    
    cout<<"\nMerge-Sort algorithm starts..."<<endl;
    mergeSort(testArray, 0, 5);
    cout<<"\nsorted atrray: ";

    printArray(testArray, 0, 5);
    
    cout<<"*Done!"<<endl;




    return 0;
}