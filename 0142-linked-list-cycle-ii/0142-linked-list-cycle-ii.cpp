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
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* entry=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
              
                //cout<<slow->val<<" "<<fast->val<<endl;
                while(slow!=entry)
                {
                    entry=entry->next;
                    slow=slow->next;
                }
                //cout<<entry->val<<endl;
                return entry;
            }
        }
        return NULL;
    }
};