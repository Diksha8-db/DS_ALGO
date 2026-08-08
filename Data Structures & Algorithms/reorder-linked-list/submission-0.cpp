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
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* next = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        // 1 . Reverse the mid to end of the linked list
        // Find the mid of the linked list
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow points to the mid of the linked list
        ListNode* second = reverseList(slow->next);
        slow->next = NULL; 

        // 2. Now chnage the pointers to point to valid value in the list
        ListNode* first = head;
        while(second != NULL){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second; 
            second->next = tmp1;   

            first = tmp1;
            second = tmp2;
        }
    }
};
