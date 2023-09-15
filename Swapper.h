//Created by Emre Yuce.
// No Copyright :)

template<class ItemType>

class Swapper
{
    public:
        ItemType* temp;
        void swap(ItemType*& obj_1, ItemType*& obj_2){
            temp = obj_1;
            obj_1 = obj_2;
            obj_2 = temp; 
        }
};