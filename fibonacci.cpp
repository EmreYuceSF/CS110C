// Emre Yuce - CS 110C 
// Question 2 - comparing time of recursive function with small and large repeatation and iterative method  

#include <iostream>
#include <chrono> // I found this library useful to see time difference between begining  and the end of the functions as seconds. 
#include <iomanip>


using namespace std;

int fibonacci_recursion(int n)
{
    if((n==1) || (n==2))
        return 1; 
    else
        return fibonacci_recursion(n-1)+fibonacci_recursion(n-2);
}

int fibonacci_iterative(int n)
{
   int current = 1, next = 1, previous = 1;
   for (int i = 3; i<=n; i++)
   {
        next = previous + current;
        previous = current; 
        current = next;

   } 
   return next;
}

int main()
{   
    // Testing the small recursion(n=5)
    int n;
    int rabbit;
    // n for small recursion
    n = 5;
    cout<<"*******************"<<endl;
    auto start = chrono::high_resolution_clock::now();
    rabbit = fibonacci_recursion(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout <<fixed<<setprecision(2) <<"Function took for small(5) recursion " << duration.count() << " seconds." << endl;
    cout<<"after 5 months of amunts of rabbit: "<<rabbit<<endl;

    // Testing the large recursion (n=45)
    n = 45;
    cout<<"*******************"<<endl;
    start = chrono::high_resolution_clock::now();
    rabbit = fibonacci_recursion(n);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout <<fixed<<setprecision(2) <<"Function took for large(45) recursion " << duration.count() << " seconds." << endl;
    cout<<"after "<<n<<" months of amunts of rabbit: "<<rabbit<<endl;

    // Testing the iterative approach( n=45)
    n = 45;
    cout<<"*******************"<<endl;
    start = chrono::high_resolution_clock::now();
    rabbit = fibonacci_iterative(n);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout <<fixed<<setprecision(2) <<"Function took for large(45) iterative " << duration.count() << " seconds." << endl;
    cout<<"after "<<n<<" months of amunts of rabbit: "<<rabbit<<endl;

    return 0;
}


/* OUTPUT
*******************
Function took for small(5) recursion 0.00 seconds.
after 5 months of amunts of rabbit: 5
*******************
Function took for large(45) recursion 3.56 seconds.
after 45 months of amunts of rabbit: 1134903170
*******************
Function took for large(45) iterative 0.00 seconds.
after 45 months of amunts of rabbit: 1134903170
*/

/* MY DEDUCTION
With number is getting bigger for the recursion method, program is significantly getting slower.
the reason is that we are calculating the same input again and again when we use recursive method. 
In this practice iterative method looks much faster than this recursive method. 
*/