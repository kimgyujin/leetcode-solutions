/*
struct ListNode 
{
    int val;
    struct ListNode *next;
};
*/

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* start;
    struct ListNode* end;
    
    start = list2;
    end = list2;
    while(1)
    {
        if(end->next==NULL)
        {
            break;
        }
        end = end->next;
    }
    
    struct ListNode* pos1;
    struct ListNode* pos2;
    
    int idx = 0;
    struct ListNode* node = list1;
    while(1)
    {
        if(idx==b+1)
        {
            pos2 = node;
        }
        else if(idx==a-1)
        {
            pos1 = node;
        }
        if(node->next==NULL)
        {
            break;
        }
        node = node->next;
        idx++;
    }
    
    pos1->next = start;
    end->next = pos2;
    
    return list1;
}
