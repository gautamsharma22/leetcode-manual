/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Floyd's Circle Detection algorithm Using slow and fast;
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            //Cycle is present break the loop
            if(slow==fast){
                break;
            }
        }
        //Reset one pointer to head (Distance between head to Duplicate Pointer will Be same as slow to duplicate pointer... )
        fast=head;

        //Increment both pointers till they match 
        while(fast!=slow && slow!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        // return the duplicate pointer.
        return slow;

    }
};