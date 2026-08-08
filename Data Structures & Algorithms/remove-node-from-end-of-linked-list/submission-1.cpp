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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Find the len of list
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        if(n == cnt) return head->next;
        // 2. Nth node from end = (len-N+1)th node from start
        temp = head;
        cnt = cnt-n;
        ListNode* prev = NULL;
        while(cnt != 0 && temp != NULL){
            prev = temp;
            temp = temp->next;
            cnt--;
            if(cnt == 0){
                prev->next = temp->next;
            }
        }

        return head;
    }
};
