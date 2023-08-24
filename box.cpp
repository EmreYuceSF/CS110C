#include <iostream>
#include <typeinfo>
#include <string>
#include <stdexcept>

using namespace std;

template<class ItemType>
class Box
{
    private:
        ItemType item;
    public:
        void setItem(const ItemType& i)
            {item = i;}
        ItemType getItem() const
            {return item;}
};

template<class BoxType, class ItemType>
BoxType findBox(BoxType boxes[], int size, ItemType target)
{
    int i = 0;
    bool found = false;
    while (!found && (i<size))
    {
        if (target==boxes[i].getItem())
            found = true;
        else
            i++;
    }
    if (!found){
        throw logic_error("Target not found in any box!");
    }
    if (typeid(target) == typeid(3)){
        if (target<0)
            throw logic_error("Target can not be negative");
    
    }

    return boxes[i];

}

int main()
{
    Box<int> intBox;
    Box<string> stringBox;

    intBox.setItem(7); 
    stringBox.setItem("seven");

    cout<<intBox.getItem()<<endl;
    cout<<stringBox.getItem()<<endl;


    Box<string> list[10];
    Box<string> searchBox;
    list[0].setItem("Go");
    list[1].setItem("Giants");

    try{
        searchBox = findBox(list, 2, "Giants");
    }
    catch (logic_error logErr)
    {
        cout<<logErr.what() <<endl;
        searchBox.setItem("Nothing");
    }
    cout<<searchBox.getItem()<<" is found in the list"<<endl; 


    Box<int> mylist[10];
    Box<int> mySearchBox;
    for (int i = 0; i<10; i++){
        mylist[i].setItem(i+1);
    }
    
    int ssNum;
    cout<<"                                                           _______________"<<endl;
    cout<<"Please enter the social security number in to search box: |";
    cin>>ssNum;

    try{
        mySearchBox = findBox(mylist, 10, ssNum);
    }
    catch (logic_error logErr)
    {
        cout<<logErr.what() <<endl;
  
    }
    if (!mySearchBox.getItem())
        {}
    else
        cout<<mySearchBox.getItem()<<" is found in the list"<<endl;


    return 0;
}

