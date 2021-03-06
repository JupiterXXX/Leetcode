/*
https://leetcode.com/problems/two-sum/description/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<vector>
#include<algorithm>
#include<unordered_map>
using std::vector;
using std::unordered_map;

//Brute force
//Time complexity: O(N^2); Time complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i<nums.size()-1; ++i){
            for(int j = i+1; j<nums.size();++j){
                if(nums[i]+nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                }                    
            }
        }
        return res;
        
    }
};

//using hash table
//throw nums[i] and i into hash=w=
//Time complexity: O(N); Space complexity: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> s;
        for(int i = 0; i<nums.size(); ++i){
            int tofind = target - nums[i];
            if(s.find(tofind)!=s.end()){
                res.push_back(s[tofind]);
                res.push_back(i);
                break;
            }
            s[nums[i]]  = i;
        }
        return res;        
    }
};
