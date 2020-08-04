// TestLeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/******************************************************************************
                      Online C++ Compiler.
       Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
#include <iostream>

#include "array/testArray.hpp"
#include "recursion/testrecursion.hpp"
#include "week1/test1-1.hpp"
#include "week1/test1-2.hpp"
#include "week1/test1-3.hpp"
#include "week1/test1-5.hpp"
#include "week1/test1-7.hpp"
#include "week2/test2-1.hpp"
#include "week2/test2-2.hpp"
#include "week2/test2-3.hpp"
#include "week2/test2-4.hpp"
#include "week2/test2-5.hpp"

using namespace std;

int end()
{
    cout << "*** Press Enter ***" << endl;
    cin.get();
    return 0;
}

void begin()
{
    cout << endl << "*** Leetcode Test ***" << endl;
}

auto main() -> int
{
    begin();
    //test1_1();
    //test1_2();
    //test1_3();
    //test1_5::test();
    //test1_7::test();

    //test2_3::test();
    //test2_4::test();
    //test2_5::test();

    //test_array::test_removeDuplicates();
    //test_array::test_checkDuplicates();
    //test_array::test_checkMountain();
    //test_array::test_replaceElements();
    //test_array::test_sortArrayByParity();
    //test_recursion::test_reverseString();
    test_recursion::swapNodes::test_swapNodes();

    return end();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
