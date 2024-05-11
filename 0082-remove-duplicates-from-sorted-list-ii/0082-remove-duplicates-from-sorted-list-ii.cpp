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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
ListNode* x = new ListNode(-1);
x->next = head;
ListNode* prev = x;
while (head!=NULL) 
{
    bool dup=false;
    while (head->next && head->next->val == head->val) {
        head = head->next;
        dup = true;
    }
    if (dup==true) {
        prev->next = head->next;
    } else {
        prev = head;
    }

    head = head->next;
}

return x->next;

        
    }
};