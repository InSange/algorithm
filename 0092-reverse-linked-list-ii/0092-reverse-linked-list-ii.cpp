/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> v;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            v.push_back(temp);
            temp = temp->next;
        }
        
        right--;
        left--;
        while(right > left)
        {
            ListNode* node = v[right];
            v[right] = v[left];
            v[left] = node;
            right--;
            left++;
        }
        head = v[0];
        int len = v.size();
        for(int i = 0; i < len-1; i++)
        {
            v[i]->next = v[i+1];
        }
        v[len-1]->next = nullptr;

        return head;
    }
};