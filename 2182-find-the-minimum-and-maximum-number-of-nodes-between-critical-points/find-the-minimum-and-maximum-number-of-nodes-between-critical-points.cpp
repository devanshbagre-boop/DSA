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
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;
        int currentIndex = 1;

        while (curr->next != nullptr) {
            // Local Maxima or Local Minima
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstCritical == -1) {
                    firstCritical = currentIndex;
                } else {
                    minDistance = std::min(minDistance, currentIndex - prevCritical);
                }
                prevCritical = currentIndex;
            }
            
            prev = curr;
            curr = curr->next;
            currentIndex++;
        }

        // If fewer than 2 critical points were found
        if (firstCritical == -1 || prevCritical == firstCritical) {
            return {-1, -1};
        }

        int maxDistance = prevCritical - firstCritical;
        return {minDistance, maxDistance};
    }
};