#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

//All tests on Arrays without using C++ std functions

namespace test_array
{
    //Remove Duplicates in array
    int removeDuplicates(vector<int>& nums)
    {
        int len = static_cast<int>(nums.size());
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

    int removeDuplicates2(vector<int>& nums)
    {
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
        std::vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        int size = removeDuplicates2(nums);

        cout << "Duplicates:" << endl;
        for (int i = 0; i < size; i++)
            cout << (nums[i]) << endl;
    }

    //----------------------------------------------------------------------
    //Checks Duplicates in array
    bool checkIfExist(vector<int>& arr)
    {
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
        std::vector<int> arr = { 7, 1, 14, 11 };
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
        for (; i < A.size() - 1;)
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
    vector<int> replaceElements_old(vector<int>& arr)
    {
        int i = 0;
        for (; i < arr.size() - 1; ++i)
        {
            const auto i1 = i + 1;
            auto max = arr[i1];
            for (int j = i1; j < arr.size(); ++j)
            {
                if (j > i1&& max < arr[j])
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

    vector<int> replaceElements(vector<int>& arr)
    {
        int max = -1;
        for (auto i = arr.size(); i > 0; --i)
        {
            const auto i1 = i - 1;
            const auto val = arr[i1];
            arr[i1] = max;
            if (max < val)
                max = val;
        }
        return arr;
    }

    inline void test_replaceElements()
    {
        vector<int> arr = { 17, 18, 5, 4, 6, 1 };
        auto v = replaceElements(arr);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
    //-------------------------------------------------------------------------
    vector<int> sortArrayByParity(vector<int>& A)
    {
        if (A.size() <= 1)
            return A;
        int j = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] % 2 == 0)
            {
                swap(A[i], A[j]);
                ++j;
            }
        }
        return A;
        //This works too...
        /*for (auto v: A)
        {
            if (v % 2)
                odd.emplace_back(v);
            else
                even.emplace_back(v);
        }
        std::copy(odd.begin(), odd.end(), std::back_inserter(even));

        return even;*/
    }

    inline void test_sortArrayByParity()
    {
        vector<int> arr = { 3, 1, 2, 4 };
        auto v = sortArrayByParity(arr);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
    //-------------------------------------------------------------------------
    int heightChecker(vector<int>& heights)
    {
        return -1;
    }

    //-------------------------------------------------------------------------
    namespace test_array {

        // Input: nums = [1,2,3,4,5,6,7], k = 3
        // Output: [5, 6, 7, 1, 2, 3, 4]
        class Solution {
        public:
            void rotate1(vector<int>& nums, int k) {
                for (int i = 0; i < k; ++i)
                {
                    const auto v = nums.back();
                    nums.pop_back();
                    nums.insert(nums.begin(), v);
                }
            }
            //Wow didn't expected that is faster...obviously
            void rotate(vector<int>& nums, int k) {
                vector<int> app;
                const auto kk = k % nums.size();
                std::copy(nums.end() - kk, nums.end(), back_inserter(app));
                nums.erase(nums.end() - kk, nums.end());

                std::copy(app.begin(), app.end(), std::inserter(nums, nums.begin()));
            }
        };

        inline void test_sortRotate()
        {
            vector<int> arr = { -1 };
            Solution sol; sol.rotate(arr, 2);

            //  vector<int> arr = { -1, -100, 3, 99 };
            //  Solution sol; sol.rotate(arr, 2);

            for (int i : arr)
                cout << i << endl;
        }
    }

    //-------------------------------------------------------------------------
    // Other tests
    //-------------------------------------------------------------------------
    //Avoiding unordered_map :)
    bool containsDuplicate1(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (!nums.empty())
        {
            int last = nums[0];
            for (auto i = 1; i < nums.size(); ++i)
            {
                if (nums[i] == last) return true;
                last = nums[i];
            }
        }
        return false;
    }
    //with unordered_map (ps: count is faster than find, it avoids a constructor call
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> map;
        for (const auto& v : nums)
        {
            if (map.count(v))
                return true;
            map[v] = true;
        }

        return false;
    }

    //-------------------------------------------------------------------------
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>  maxres;
        const vector<int>& v1 = (nums1.size() > nums2.size()) ? nums1 : nums2;
        const vector<int>& v2 = (nums1.size() > nums2.size()) ? nums2 : nums1;

        int b = 0; int e = 0; int j = 0;
        for (int i = 0; i < v1.size(); ++i)
        {
            for (int j = 0; j < v2.size(); ++j)
            {
                if (v1[i] == v2[j])
                {
                    res.clear();
                    int jj = j;
                    int ii = i;
                    while (ii < v1.size() && jj < v2.size())
                    {
                        if (v1[ii] == v2[jj])
                        {
                            res.emplace_back(v2[jj]);
                        }
                        ++jj;
                        ++ii;
                    }
                    if (res.size() > maxres.size())
                    {
                        maxres.clear();
                        std::copy(res.begin(), res.end(), back_inserter(maxres));
                    }
                }
            }
        }

        return maxres;
    }

    //Not the best solution, but less memory usage apparently
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;

        const vector<int>& v2 = (nums1.size() > nums2.size()) ? nums1 : nums2;
        const vector<int>& v1 = (nums1.size() > nums2.size()) ? nums2 : nums1;
        int ii = 0;

        vector<int> v3;
        std::copy(v2.begin(), v2.end(), back_inserter(v3));

        for (int v : v1)
        {
            auto it = std::find(v3.begin(), v3.end(), v);

            if (it != v3.end())
            {
                res.emplace_back(v);
                v3.erase(it);
            }

        }

        return res;
    }

    inline void test_intersect()
    {
        std::vector<int> v1 = { 4, 9, 5 };
        std::vector<int> v2 = { 9, 4, 9, 8, 4 };

        std::vector<int> res = intersect(v1, v2);
        for (int i : res)
            cout << i << endl;
    }

    //-------------------------------------------------------------------------
/*
    Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
    Input: [4, 3, 2, 1]
    Output : [4, 3, 2, 2]
    Explanation : The array represents the integer 4321.
*/
    vector<int> plusOne(vector<int>& digits) {

        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i)
        {
            auto& d = digits[i];
            if (d < 9)
            {
                ++d;
                return digits;
            }
            d = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }

    //-------------------------------------------------------------------------
    //Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    //Given nums = [2, 7, 11, 15], target = 9,
    //
    //Because nums[0] + nums[1] = 2 + 7 = 9,
    //    return[0, 1].



    // Runtime: 8 ms, faster than 99.78% of C++ online submissions for Two Sum.
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> sum;
        unordered_map<int, int> id;
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            int r = target - n;

            if (sum.count(r) && n + sum[r] == target)
            {
                return { id[r], i };
            }
            sum[n] = n;
            id[n] = i;
        }
        return {};



        /*for (auto i = 0; i < nums.size() - 1; ++i)
        {
            const auto n1 = nums[i];
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    if (n1 + nums[j] == target)
                    {
                        return { i,j };
                    }
                }
        }
        return {};*/
    }
    inline void test_twoSum()
    {
        //std::vector<int> v1 = { 2,7,11,15};
        //std::vector<int> res = twoSum(v1, 9);

        std::vector<int> v1 = { 0,4,3,0 };
        std::vector<int> res = twoSum(v1, 0);

        /*std::vector<int> v1 = { 230, 863, 916, 585, 981, 404, 316, 785, 88, 12, 70, 435, 384, 778, 887, 755, 740, 337, 86, 92, 325, 422, 815, 650, 920, 125, 277, 336, 221, 847, 168, 23, 677,
            61, 400, 136, 874, 363, 394, 199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422, 927, 783, 930, 282, 306, 506, 44, 926, 691, 568, 68, 730, 933, 737, 531, 180, 414, 751,
            28, 546, 60, 371, 493, 370, 527, 387, 43, 541, 13, 457, 328, 227, 652, 365, 430, 803, 59, 858, 538, 427, 583, 368, 375, 173, 809, 896, 370, 789 };
        std::vector<int> res = twoSum(v1, 542);*/


        for (int i : res)
            cout << i << endl;
    }



    //-------------------------------------------------------------------------

    bool isValidSudoku(vector<vector<char>>& board) {

        std::unordered_map<int, int> list;
        for (int c = 0; c < 9; ++c)
        {
            list.clear();
            for (int r = 0; r < 9; ++r)
            {
                const auto v = board[r][c];
                if (v != '.' && list.count(v) > 0)
                    return false;
                list[v]++;
            }
        }

        for (int c = 0; c < 9; ++c)
        {
            list.clear();
            for (int r = 0; r < 9; ++r)
            {
                const auto v = board[c][r];
                if (v != '.' && list.count(v) > 0)
                    return false;
                list[v]++;
            }
        }

        for (int q = 0; q < 9; ++q)
        {
            const int offx = q % 3;
            const int offy = q / 3;
            list.clear();
            for (int r = 0; r < 3; ++r)
            {
                for (int c = 0; c < 3; ++c)
                {
                    const auto v = board[offx * 3 + c][offy * 3 + r];
                    if (v != '.' && list.count(v) > 0)
                    {
                        return false;
                    }
                    list[v]++;
                }
            }
        }
        return true;
    }

    void test_sudoku()
    {
        vector<vector<char>> sud_true = {
            {'5','3','.','.','7','.','.','.','.'} ,
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        vector<vector<char>> sud_false = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };


        vector<vector<char>> sud_false2 = {
            {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
            {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
            {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
            {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
        };
        //  cout << (isValidSudoku(sud_false) ? "true" : "false") << endl;
        cout << (isValidSudoku(sud_false) ? "true" : "false") << endl;
    }



    void rotate(vector<vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size());

        for (int r = 0; r < n; r++)
        {
            for (int c = r; c < n; c++)
            {
                std::swap(matrix[c][r], matrix[r][c]);
                /*int temp = matrix[c][r];
                matrix[c][r] = matrix[r][c];
                matrix[r][c] = temp;*/
            }
        }

        const int s1 = n - 1;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n / 2; c++)
            {
                std::swap(matrix[r][s1 - c], matrix[r][c]);
                /*int temp = matrix[r][s1 - c];
                matrix[r][s1 - c] = matrix[r][c];
                matrix[r][c] = temp;*/
            }
        }

    }
    void test_rotate()
    {

        vector<vector<int>> matrix = {
               { 5, 1, 9, 11},
               {2, 4, 8, 10},
               {13, 3, 6, 7},
               {15, 14, 12, 16}
        };

        cout << "Before" << endl;
        const int n = static_cast<int>(matrix.size());
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                cout << matrix[r][c] << ends;
            }
            cout << endl;
        }

        cout << "After" << endl;
        rotate(matrix);
        const int n2 = static_cast<int>(matrix.size());
        for (int r = 0; r < n2; r++)
        {
            for (int c = 0; c < n2; c++)
            {
                cout << matrix[r][c] << ends;
            }
            cout << endl;
        }
    }

};
