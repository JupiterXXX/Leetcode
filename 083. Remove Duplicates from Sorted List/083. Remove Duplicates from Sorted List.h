/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};

//IF THIS LIST IS UNSORTED!!!!!!!!
//USE A HASH MAP TO RECORD NUMBER MET
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* res = head;
        unordered_set<int> tmp;
        tmp.insert(head->val);        
        while(head->next != NULL){
            if(tmp.find(head->next->val) == tmp.end()){
                tmp.insert(head->next->val);
                head = head->next;
            }else{
                head->next = head->next->next;
            }
            
        }
        return res;
        
    }
};
