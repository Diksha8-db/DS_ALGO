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
    ListNode* reverseList(ListNode* head) {
        // APPROACH 1 : INPLACE CHANGE IN POINTER T.C = O(len of list)
        /*
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next = head;

        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
        */
        // APPROACH 2 : CREATE A NEW LIST
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        vector<int> value;
        while(head != NULL){
            value.push_back(head->val);
            head = head->next;
        }
        
        for(int i = value.size()-1; i >= 0; i--){
            ListNode* node = new ListNode(value[i]);
            temp->next = node;
            temp = temp->next; 
        }

        temp->next = NULL;
        return newHead->next;
    }
};
