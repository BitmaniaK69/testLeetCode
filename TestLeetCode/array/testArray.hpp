#pragma once
#include <iostream>
#include <vector>

using namespace std;

//All tests on Arrays without using C++ std functions

namespace test_array
{
    //Remove Duplicates in array
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                for (int j = i; j < len - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                --i;
                len--;
            }
        }
        return len;
    }

    int removeDuplicates2(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto j = 0;
        for (auto i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[j])
            {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }

    void test_removeDuplicates()
    {
        //Remove Duplicates in array
        std::vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
        int size = removeDuplicates2(nums);

        cout << "Duplicates:" << endl;
        for (int i = 0; i < size; i++)
            cout << (nums[i]) << endl;
    }

    //----------------------------------------------------------------------
    //Checks Duplicates in array
    bool checkIfExist(vector<int>& arr) {
        for (auto i = 0; i < arr.size(); ++i)
        {
            for (auto j = i + 1; j < arr.size(); ++j)
            {
                if (2 * arr[i] == arr[j])
                {
                    return true;
                }

            }
        }
        return false;
    }
    void test_checkDuplicates()
    {
        //Checks Duplicates in array
        std::vector<int> arr = { 7,1,14,11 };
        cout << (checkIfExist(arr) ? "true" : "false") << endl;
    }
    //----------------------------------------------------------------------
    //Valid mountain array
    bool validMountainArray(vector<int>& A)
    {
        if (A.size() < 3)
        {
            return false;
        }

        auto i = 0;
        for (; i < A.size() - 1;)
        {
            if (A[i] >= A[i + 1])
                break;

            ++i;
        }

        if (i == 0 && i >= A.size() - 1)
        {
            return false;
        }
        for (; i < A.size() - 1; )
        {
            if (A[i] <= A[i + 1])
                return false;

            ++i;
        }
        return true;
    }
    void test_checkMountain()
    {
        //Valid mountain array
        //std::vector<int> arr = { 0, 3, 2, 1 };
        //std::vector<int> arr = { 2, 1 };

        std::vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        cout << (validMountainArray(arr) ? "true" : "false") << endl;
    }

    //----------------------------------------------------------------------
    // Replace Elements with Greatest Element on Right Side
    vector<int> replaceElements(vector<int>& arr) {
        int i = 0;
        for (; i < arr.size() - 1; ++i)
        {
           auto max = arr[i];
            for (int j = i + 1; i < arr.size()-1; ++j)
            {
                if (max < arr[j])
                {
                    max = arr[j];
                }
                //arr[j] = max;
            }
            arr[i] = max;
        }
        arr[i] = -1;
        return arr;
    }

    inline void test_replaceElements()
    {
        vector<int>  arr = { 17, 18, 5, 4, 6, 1 };
        auto v = replaceElements(arr);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;

    }
};
