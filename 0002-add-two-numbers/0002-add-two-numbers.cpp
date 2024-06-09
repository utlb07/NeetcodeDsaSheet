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
        ListNode* ans=new ListNode(-1);
        ListNode* dummy=ans;
        int carry=0;
        while(l1!=NULL||l2!=NULL||carry>0)
        {
            int data=0;
            if(l1!=NULL)
            {
                data+=l1->val;
            }
            else
            {
                data+=0;
            }
            if(l2!=NULL)
            {
                data+=l2->val;
            }
            else
            {
                data+=0;
            }
            data+=carry;
            carry=data/10;
            dummy->next=new ListNode(data%10);
            dummy=dummy->next;
            if(l1!=NULL)
            {
                l1=l1->next;
            }
             if(l2!=NULL)
            {
                l2=l2->next;
            }
            
        }
        return ans->next;
    }
};