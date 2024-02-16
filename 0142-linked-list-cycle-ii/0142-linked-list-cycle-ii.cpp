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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> um;
        
        while(head != nullptr)
        {
            if(um[head] != false) return head;
            um[head] = true;
            head = head->next;
        }
        
        return nullptr;
    }
};