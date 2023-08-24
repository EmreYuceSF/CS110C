#include <iostream>
using namespace std;

template <class swapType>
void searchForWord(swapType target, swapType array[], int left, int right)
{
    int mid = (left+right)/2;
    
    if (left<=right)
    {
       
    

        if (array[mid]==target)
        {
            cout<<mid<<endl;
            return;
        }
        else if (array[mid] < target)
        {
            left = mid+1;
            searchForWord(target, array, left, right);
            return;
        }
        else if (array[mid] > target)
        { 
            right = mid-1;
            searchForWord(target, array, left, right);
            return;
        }
    }
    else
        cout<<"Not here!"<<endl;

}

template<class swapType>
void swapAnything(swapType& x, swapType& y)
{
    swapType temp;
    temp = x;
    x = y;
    y= temp;
}


template<class swapType>
void sort(swapType list[], int length)
{
    swapType lowestValue;
    int lowestPos;
    for(int i=0; i<length-1; i++)
    {
        lowestValue=list[i];
        lowestPos = i;
        for(int j=i+1; j<length; j++)
        {
            if(list[j]<lowestValue)
            {
                lowestPos = j;
                lowestValue = list[j];
            }  
        }
        swapAnything(list[i], list[lowestPos]); 
    }

}


int main()
{
    int target = 1;
    
    int phones[9] = {5,7,45,898,67,345,334,4,123};

    sort(phones, 9);

    for(int i = 0; i<8; i++)
    {
        cout<<phones[i]<<endl;
    }

    searchForWord(target, phones, 0, 8);




    return 0;
}