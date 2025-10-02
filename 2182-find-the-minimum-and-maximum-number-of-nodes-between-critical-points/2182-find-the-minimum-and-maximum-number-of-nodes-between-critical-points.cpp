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

        vector<int> positions;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1; // curr ka position

        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                positions.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (positions.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < positions.size(); i++) {
            minDist = min(minDist, positions[i] - positions[i-1]);
        }

        int maxDist = positions.back() - positions.front();

        return {minDist, maxDist};
    }
};
