#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

namespace test2_3
{
    class MinStack
    {
    public:
        static const int size = 100;
        /** initialize your data structure here. */
        MinStack()
        {
            stack = new int[size];
        }

        ~MinStack()
        {
            delete[] stack;
        }

        void push(int x)
        {
            minim = (next >= 0) ? min(x, minim) : x;
            stack[++next] = x;
        }

        void pop()
        {
            if (next >= 0)
            {
                if (stack[next] == minim)
                {
                    minim = stack[0];
                    for (auto i = 1; i < next; i++)
                    {
                        minim = min(stack[i], minim);
                    }
                }
                --next;
            }
        }

        int top() const
        {
            return stack[next];
        }

        int getMin() const
        {
            return minim;
        }

        int* stack;
        int next = -1;
        int minim = -1;
    };

    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(x);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */

    inline void test()
    {
        MinStack minStack = {};
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin(); // return -3
        minStack.pop();
        minStack.top();    // return 0
        minStack.getMin(); // return -2
    }
};
