#pragma once

#include <iostream>
#include <unordered_map>

using namespace std;
namespace august_week1
{
    namespace test1 {
        //Design a logger system that receive stream of messages along with its timestamps,
        //each message should be printed ifand only if it is not printed in the last 10 seconds.
        
        class Logger {
        public:
            /** Initialize your data structure here. */
            Logger() {
                ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
            }

            /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
                If this method returns false, the message will not be printed.
                The timestamp is in seconds granularity. */

            bool shouldPrintMessage(int timestamp, string message) {
                auto it = mLastTime.find(message);
                if (it == mLastTime.end())
                {
                    mLastTime[message] = timestamp;
                    return true;
                }
                else if (timestamp - it->second >= 10)
                {
                    it->second = timestamp;
                    return true;
                }
                return false;
            }

        private:
            std::unordered_map<string, int> mLastTime;

        };

        inline void test_logger()
        {
            Logger logger;

            // logging string "foo" at timestamp 1
            logger.shouldPrintMessage(1, "foo"); //returns true;

            // logging string "bar" at timestamp 2
            logger.shouldPrintMessage(2, "bar"); //returns true;

            // logging string "foo" at timestamp 3
            logger.shouldPrintMessage(3, "foo"); //returns false;

            // logging string "bar" at timestamp 8
            logger.shouldPrintMessage(8, "bar"); //returns false;

            // logging string "foo" at timestamp 10
            logger.shouldPrintMessage(10, "foo"); //returns false;

            // logging string "foo" at timestamp 11
            logger.shouldPrintMessage(11, "foo"); //returns true;
        }
    }
};
