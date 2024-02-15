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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, bool> um;

        while(temp != nullptr)
        {
            if(um[temp]) return true;
            um[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};