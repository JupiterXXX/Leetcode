/*
https://leetcode.com/problems/jump-game/description/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

*/
//This is a greedy problem.
//If we keep track of this left-most GOOD position as a separate variable, we can avoid searching for it in the array.
//Time complexity: O(N); Space complexity: O(1)
#include <vector>
using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastpos = nums.size() - 1;
        for(int i = nums.size() - 1; i >=0; --i){
            if(i + nums[i]>=lastpos)
                lastpos = i;            
        }
        return lastpos == 0;
    }
};
