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
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        ListNode* temp=new ListNode(-1);
        ListNode* dummy=temp;
        while(head1!=NULL&&head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                dummy->next=head1;
                dummy=head1;
                head1=head1->next;
            }
            else
            {
                dummy->next=head2;
                dummy=head2;
                head2=head2->next;
            }
            if(head1!=NULL)
            {
                dummy->next=head1;
            }
             if(head2!=NULL)
            {
                dummy->next=head2;
            }
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
       if(head == NULL || head ->next == NULL)
            return head;   
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;          
            fast = fast ->next ->next;  
            
        }   
        temp -> next = NULL;            
        ListNode* l1 = sortList(head);  //2   
        ListNode* l2 = sortList(slow);  //1 
        return merge(l1, l2);   
    }
};