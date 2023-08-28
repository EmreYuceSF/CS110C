//Emre Yuce CS 110C Assignment_1 - Recursion


#include <iostream>

using namespace std;


void intReverse(int num)
{
    /*
      This function recursively prints the individual digits of a number.
    The base case is when the number becomes 0, at which point the recursion stops.
    In each recursive step, the function:
    - Calculates the last digit of the number using the modulus operator (%).
    - Prints the last digit.
    - Removes the last digit by integer division (/) with 10.
    - Calls itself with the new(updated) number.
    This continues until the number becomes 0.
     */

    if (num>0)
    {
        cout<<num%10;
        num /= 10; 
        intReverse(num);
    }
    else
        cout<<""<<endl;
}



int sumStartToEnd(int start, int end)
{
    /*
    The function sums up numbers from number start to the number end including start and the end.
    Our base case is start<end. while start<end our function returns start+end+(function itself with start+1 and end-1 parameters)
    in the end, we have 2 possibility it can end start>end or start==end. If (start>end) that means all numbers are used between start and end there are no 
    calculating needs to be done but if ends with start == end then that number needs to be added to the total.

     */
    
    if (start<end)
    {
        return(start+end+sumStartToEnd(start+1, end-1));
    }
    else if (start == end)
    {
        return start;
    }
    else
        return 0;
    
}


void writeBackward(string s="cat")
{
    /* 
    The function prints out the reverse of the string, which is passed as a parameter to the function.
    The function does that recursively. 
    First prints out the last letter of the string, then calls itself with a substring of 
    the last string without the last letter and does that till the string becomes an empty string.
    --> This method prints out the last letters of each substrings before calling the next loop. 
     */
    
    
    cout << "Enter writeBackward with string: " << s << endl;
    int length = s.size();
    if(s.empty()){}
    else
    {
        cout << "About to write last character of string: "<< s << endl;
        cout<<"-> "<<s[length-1]<<endl; // I used the 'endl;' manipulator to have a clear output!
        writeBackward(s.substr(0, length-1));
    }
    cout << "Leave writeBackward with string: " << s << endl;


}
void writeBackward2(string s)
{
    /*
    This function prints out the reversal of a string provided as a parameter. It adheres to the "last in, first out" approach characteristic of recursive functions.
     In each recursive call, the function trims the initial character of the string and calls itself with the updated string. Upon reaching the end of the string,
    it begins to output the characters in reverse order.
     Subsequently, during the backtracking phase, the function retraces its steps, printing the initial character of the string at each step.
      */

    cout << "Enter writeBackward2 with string: "<<s<<endl;
    int length = s.size();
    if(length == 0){}
    else
    {
        
        writeBackward2(s.substr(1, length));
        cout << "About to write first character of string: "<< s << endl;
        cout<<"-> "<<s[0]<<endl; // I used the 'endl;' manipulator to have a clear output!
    }
    cout << "Leave writeBackward2 with string: " << s << endl;

}


int main()
{
    int num;
    cout<<"Please enter a number to be printed out reversed: ";
    cin>>num;
    intReverse(num);
    cin.clear();


    int start, end;
    cout<<"\nPlease enter the start and the end numbers\n(start must be smaller than the end number!) E.g. 3 6: ";
    cin>>start>>end;
    // check if true
    int result = ((end)*(end+1)/2)-((start)*(start-1)/2);
    int total = sumStartToEnd(start, end);
    cout<<total<<endl;
    if (total==result)
        cout<<"Correct! Validation has been completed.\n"<<endl;
    else
        cout<<"failed\n"<<endl;


    string animal = "dog";

    writeBackward(animal);
    cout<<""<<endl;
    writeBackward2(animal);


    

    return 0;
}


/*  OUTPUT
[eyuce@hills CS_110C]$ ./a.out 
Please enter a number to be printed out reversed: 12345
54321

Please enter the start and the end numbers
(start must be smaller than the end number!) E.g. 3 6: 3 87
3825
Correct! Validation has been completed.

Enter writeBackward with string: dog
About to write last character of string: dog
-> g
Enter writeBackward with string: do
About to write last character of string: do
-> o
Enter writeBackward with string: d
About to write last character of string: d
-> d
Enter writeBackward with string: 
Leave writeBackward with string: 
Leave writeBackward with string: d
Leave writeBackward with string: do
Leave writeBackward with string: dog

Enter writeBackward2 with string: dog
Enter writeBackward2 with string: og
Enter writeBackward2 with string: g
Enter writeBackward2 with string: 
Leave writeBackward2 with string: 
About to write first character of string: g
-> g
Leave writeBackward2 with string: g
About to write first character of string: og
-> o
Leave writeBackward2 with string: og
About to write first character of string: dog
-> d
Leave writeBackward2 with string: dog
[eyuce@hills CS_110C]$ 

 */


