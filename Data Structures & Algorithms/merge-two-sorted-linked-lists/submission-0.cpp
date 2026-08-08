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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val > temp2->val){
                // create a new node with the value of temp2
                ListNode* newNode = new ListNode(temp2->val);
                temp->next = newNode;
                temp2 = temp2->next;
            }
            else{
                ListNode* newNode = new ListNode(temp1->val);
                temp->next = newNode;
                temp1=temp1->next;
            }
            temp = temp->next;
        }
        while(temp1 != NULL){
            ListNode* newNode = new ListNode(temp1->val);
            temp->next = newNode;
            temp1=temp1->next;
            temp = temp->next;
        }
        while(temp2 != NULL){
            ListNode* newNode = new ListNode(temp2->val);
            temp->next = newNode;
            temp2=temp2->next;
            temp = temp->next;
        }

        return newHead->next;
    }
};
