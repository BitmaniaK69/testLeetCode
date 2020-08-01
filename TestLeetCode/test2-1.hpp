#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.



Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.


Note:

The number of nodes in the given list will be between 1 and 100.
*/

namespace test2_1
{

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) const {
        ListNode* middle = head;
        bool even = false;
        while (auto* next = head->next)
        {
            head = next;
            even = !even;
            if (even)
            {
                middle = middle->next;
            }
        }
        return middle;
    }

    /*ListNode* middleNode(ListNode* head) const {
        ListNode* middle = head;
        ListNode* next = head;

        if (head->next && head->next->next)
        {
            next = head->next->next;
        }
        while (next != nullptr)
        {
        
            middle = middle->next;
            if (next->next != nullptr && next->next->next != nullptr)
            {
                next = next->next->next;
            }
            else
            {
                next = nullptr;
            }
        }
        return middle;
    }*/
};

    void test()
    {
        Solution sol;
        {
            //ListNode arr() = { 1,2,3,4,5 };
            ListNode a5(5);
            ListNode a4(4, &a5);
            ListNode a3(3, &a4);
            ListNode a2(2, &a3);
            ListNode a1(1, &a2);
            
            cout << sol.middleNode(&a1)->val << endl;
        }
        
    }
};