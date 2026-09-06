class Solution {
    public:
  
        ListNode* reverseList(ListNode* head) {
            ListNode* previous = nullptr;
            while (head) {
                ListNode* following = head->next;
                head->next = previous;
                previous = head;
                head = following;
            }
            return previous;
        }
    };
            
      