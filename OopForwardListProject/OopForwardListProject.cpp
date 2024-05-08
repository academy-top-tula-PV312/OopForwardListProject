#include <iostream>
#include "ForwardList.h"

int main()
{
    ForwardList<int> list1;
    for (int i{}; i < 5; i++)
        list1.PushHead((i + 1) * 100);
    list1.Show();
    std::cout << "\n";

    for (auto it = list1.GetIterator(); !it.EndOf(); it.Next())
        std::cout << it.Current() << "\n";
    std::cout << "\n";

    //std::cout << "pop = " << list1.PopHead() << "\n\n";


    /*ForwardList<int> list2(std::move(list1));
    list2.Show();
    std::cout << "\n";

    list2.PushHead(600);
    list2.Show();
    std::cout << "\n";

    list1.PushHead(1000);*/
    
    //list1.Insert(list1.Size() - 1, 700);

    //std::cout << list1.Remove(list1.Size() + 5) << "\n\n";

    /*try
    {
        list1[-1] = 1000;
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << "\n";
    }
    

    list1.Show();
    std::cout << "\n";*/
}
