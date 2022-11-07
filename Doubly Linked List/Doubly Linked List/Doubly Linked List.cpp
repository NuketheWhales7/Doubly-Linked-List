// Doubly Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Christopher Miller
//CIS-2542

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList a;
    std::cout << a;
    a.Insert(12, 7);
    std::cout << a;
    a.Insert(-3, 2);
    std::cout << a;
    a.Insert(0, 4);
    std::cout << a;
    a.Insert(12, 8);
    std::cout << a;
    a.Insert(3, 17);
    std::cout << a;
    a.Insert(1, 22);
    std::cout << a;
    a.Insert(6, 52);
    std::cout << a;
    a.Insert(6, 76);
    std::cout << a;

    a.Erase(-1);
    std::cout << a;
    a.Erase(0);
    std::cout << a;
    a.Erase(5);
    std::cout << a;
    a.Erase(2);
    std::cout << a;







    /*
    a.PushFront(19);
    std::cout << a;
    a.PushFront(22);
    std::cout << a;
    a.PushFront(12);
    std::cout << a;
    a.PushFront(52);
    std::cout << a;
    a.PushFront(77);
    std::cout << a;

    while (true)
    {
        int x;
        std::cout << "Enter find value: ";
        std::cin >> x;
        std::cout << a.Find(x) << std::endl;

    }

    for(int i=-2; i<=7; ++i)
        std::cout << i << ": " << a[i] << std::endl; //prints elements in the list

   
    while (a.Empty() == false)
    {
        a.PopFront();
        std::cout << a;
    }
    a.PopFront();
    */
    system("PAUSE");
    return 0;
}
