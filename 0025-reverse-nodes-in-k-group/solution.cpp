/**
 * Definition for singly-linked list.
 struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = head;
        ListNode* trail = res;
        deque <int> dque;

        while(head!=nullptr)
        {
            dque.push_back(head->val);
            head = head->next;
            if(dque.size() == k)
            {
                while(!dque.empty())
                {
                    int x = dque.back();
                    dque.pop_back();
                    trail->val = x;
                    trail = trail->next;  
                }
            }
        }

        while(!dque.empty())
        {
            int x = dque.front();
            dque.pop_front();
            trail->val = x;
            trail = trail->next;  
        }

        return res;
    }
};
