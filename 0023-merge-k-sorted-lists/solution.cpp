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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode root(0);
        ListNode* tail = &root;
        while(1)
        {
            int x = 1e9;
            int idx = -1;
            for(int i=0;i<lists.size();i++)
            {
                if(lists[i]==nullptr) continue;
                if(lists[i]->val < x)
                {
                    x = lists[i]->val;
                    idx = i;
                }
            }
            if(idx==-1) break;
            tail->next = lists[idx];      
            tail = tail->next;              
            lists[idx] = lists[idx]->next;  
        }
        return root.next;
    }
};
