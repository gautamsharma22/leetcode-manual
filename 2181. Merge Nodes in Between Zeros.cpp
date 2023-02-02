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
    ListNode* mergeNodes(ListNode* head) {
           
        ListNode* dummy=new ListNode(0);
        ListNode* temp1=dummy;
        ListNode* temp=head;
        int sum=0;
        while(temp!=NULL){
            if(temp->val!=0){
                sum=sum+temp->val;
            }
            if(temp->val==0 && sum!=0){
                ListNode* a1=new ListNode(sum);
                sum=0;
                temp1->next=a1;
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};