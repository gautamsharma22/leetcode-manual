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
    ListNode *head = NULL;
    int size=0;
    Solution(ListNode* head) {
        srand(time(0));     //Call this only once 
        this->head = head;
        ListNode *temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
    }
    int helper(){
        int j = rand() % (size);    //Generate a random number within 0 to Size
        ListNode *temp=head;
        while(j-- and temp->next!=NULL){
            temp=temp->next;
        }
        return temp->val;
    }
    int getRandom() {
        return helper();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */