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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumNode = new ListNode();
        ListNode* temp = sumNode;
        int c = 0;
        
        while(l1 != nullptr && l2 != nullptr)
        {
            ListNode* newNode = new ListNode();
            int sum;
            sum = l1->val + l2->val + c;
            
            c = (sum/10) ? 1 : 0;
            newNode->val = sum%10;
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr)
        {
            ListNode* newNode = new ListNode();
            int sum;
            sum = l1->val + c;
            c = (sum/10) ? 1 : 0;
            newNode->val = sum%10;
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2 != nullptr)
        {
            ListNode* newNode = new ListNode();
            int sum;
            sum = l2->val + c;
            c = (sum/10) ? 1 : 0;
            newNode->val = sum%10;
            temp->next = newNode;
            temp = temp->next;
            l2 = l2->next;
        }
        
        if(c)
        {
            ListNode* newNode = new ListNode();
            newNode->val = c;
            temp->next = newNode;
        }
        
        return sumNode->next;
    }
};