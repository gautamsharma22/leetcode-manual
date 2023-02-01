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
    ListNode* reverse(ListNode* &list){
        ListNode* prev=NULL;
        ListNode* current=list;
        ListNode* temp=list;
        while(current!=NULL){
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* temp=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            }
        if(slow==NULL){
            cout<<"yes";
        }
        ListNode* check=reverse(slow);
        while(temp!=NULL && check!=NULL){
            if(temp->val==check->val){
            cout<<temp->val<<"  "<<check->val;
            temp=temp->next;
            check=check->next;
            }else{
                return false;
            }
        }
        return true;
    }
};