class Solution {
public:
    ListNode* reveselist(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i = 0; i < k; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while(true){
            ListNode* kth = prevGroup;

            for(int i = 0; i < k; i++){
                kth = kth->next;
                if(kth == NULL)
                    return dummy->next;
            }

            ListNode* groupHead = prevGroup->next;
            ListNode* nextGroup = kth->next;

            kth->next = NULL;

            ListNode* newHead = reveselist(groupHead, k);

            prevGroup->next = newHead;
            groupHead->next = nextGroup;

            prevGroup = groupHead;
        }
    }
};