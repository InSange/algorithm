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

class cmp{
public:
    bool operator() (const int& a, const int& b)
    {
        return a > b;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();

        priority_queue<int, vector<int>, cmp> pq;

        for(auto* list : lists)
        {
            while(list != nullptr)
            {
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* temp = head;
        while(!pq.empty())
        {
            ListNode* cur = new ListNode(pq.top());
            pq.pop();

            temp->next = cur;
            temp = temp->next;
        }

        return head->next;
    }
};