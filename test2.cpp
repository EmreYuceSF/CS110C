#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "emre";
    cout<<name.size()<<endl;
    cout<<name[2]<<endl;
    string lastHalf = name.substr(name.size()/2, name.size()-1);
    cout<< lastHalf<<endl;

    string a = "";
    if (a)
    {
        cout<<"False"<<endl;
    }



    return 0;
}