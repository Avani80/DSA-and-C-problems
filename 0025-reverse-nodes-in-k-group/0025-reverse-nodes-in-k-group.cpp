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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // List empty , k == 1;
        if(!head || k == 1) return head;
        ListNode * temp = new ListNode(0);
        temp->next = head;

        ListNode * curr = head;
        ListNode * prevEnd= temp , *next = nullptr;// store prev group
      
      while(true){
        ListNode * check = curr;
        for(int i=0;i<k;i++){
            if(!check) return temp->next;
            check = check->next;
        }
        ListNode * prev = nullptr;
        ListNode * start = curr; // starting node;
        for(int i=0;i<k;i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prevEnd->next = prev;
        start->next = curr;
        prevEnd = start;

      } 
      return temp->next;;
    }
};