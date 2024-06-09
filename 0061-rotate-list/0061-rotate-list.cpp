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

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
        {
            return head;
        }
        //1 2 3 4 5
        //5 1 2 3 4 5
        //
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            len++;
            temp=temp->next;
        }
        k=k%len;
        temp->next=head;
        int end=len-k;
        while(end--)
        {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};