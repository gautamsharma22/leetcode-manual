#include<iostream>
using namespace std;

class Solution {
public:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    ListNode* swapPairs(ListNode* &head) {
        if(head==NULL){
            return NULL;
        }
        int pair=2;
        int count=0;
        ListNode* prev=NULL;
        ListNode* current=head;
        ListNode* temp;
        while(current!=NULL && count<pair){
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
            count++;
        }
        cout<<"hi";
        if(temp!=NULL){
            head->next=swapPairs(temp);
        }
        return prev;
    }
};