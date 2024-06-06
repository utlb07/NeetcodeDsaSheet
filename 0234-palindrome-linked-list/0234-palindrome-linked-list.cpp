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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       if(head==NULL)
        {
            return true;
        }
        if(head->next==NULL)
        {
            //single Node
            return true;
        }
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL)
        {
          fast=fast->next;
          if(fast!=NULL)
          {
              fast=fast->next;
              slow=slow->next;
          }
        }
        ListNode* temp=head;
        ListNode* temp2=reverse(slow->next);
        while(temp2!=NULL)
        {
          if(temp->val!=temp2->val)
          {
              return false;
          }
              temp=temp->next;
              temp2=temp2->next;
        }
        return true;
    }
};