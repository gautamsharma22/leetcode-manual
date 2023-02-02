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
    ListNode* middle(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }
    ListNode* mergelist(ListNode* left,ListNode* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp1=dummy;

        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                temp1->next=left;
                left=left->next;
            }
            else{
                temp1->next=right;
                right=right->next;
            }
            temp1=temp1->next;
            if(left!=NULL){
                temp1->next=left;
            }
            if(right!=NULL){
                temp1->next=right;
            }
        }

        return dummy->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=middle(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);

        ListNode* final=mergelist(left,right);
        return final;
    }
};