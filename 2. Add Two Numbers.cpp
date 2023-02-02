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
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=0;
            int val1=0,val2=0;

            if(l1!=NULL){
                val1=l1->val;
            }

            if(l2!=NULL){
                val2=l2->val;
            }

            sum=val1+val2+carry;
            int digit =sum%10;
            cout<<digit;
            carry=sum/10;
            ListNode* ans=new ListNode(digit);
            temp->next=ans;
            temp=temp->next;
            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }

        }
        return dummy->next;
    }
};