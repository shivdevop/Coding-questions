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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL || (head->next==NULL && head->val==val))
        return NULL;

        if(head->val==val)
        {
            while(head!=NULL && head->val==val)
            head=head->next;
        }
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        while(temp2!=NULL)
        {
            if(temp2->val==val)
            {
                temp1->next=temp2->next;
                temp2=temp1->next;
            }
            else
            {
                temp2=temp2->next;
                temp1=temp1->next;
            }


        }  

        return head;


       
    }
};