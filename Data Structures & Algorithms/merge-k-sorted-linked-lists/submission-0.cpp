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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode* out;
        if (lists[0] != nullptr) {
            out = new ListNode(lists[0]->val, lists[0]->next);
        } else {
            out = nullptr;
        }

        ListNode* temp = new ListNode();
        ListNode* curr_temp = temp;
        for (int k = 1; k < lists.size(); k++) {
            if (out == nullptr && lists[k] == nullptr)
                continue;
            while (out != nullptr && lists[k] != nullptr) {
                if (out->val > lists[k]->val) {
                    curr_temp->val = lists[k]->val;
                    lists[k] = lists[k]->next;
                } else if (out->val < lists[k]->val) {
                    curr_temp->val = out->val;
                    out = out->next;
                } else {
                    curr_temp->val = out->val;
                    curr_temp->next = new ListNode(out->val);
                    curr_temp = curr_temp->next;
                    out = out->next;
                    lists[k] = lists[k]->next;
                }
                if (lists[k] != nullptr || out != nullptr) {
                    curr_temp->next = new ListNode();
                    curr_temp = curr_temp->next;
                }
            }
            if (out != nullptr) {
                while (out != nullptr) {
                    curr_temp->val = out->val;
                    if (out->next != nullptr) {
                        curr_temp->next = new ListNode();
                        curr_temp = curr_temp->next;
                    }
                    out = out->next;
                }
            } else if (lists[k] != nullptr) {
                while (lists[k] != nullptr) {
                    curr_temp->val = lists[k]->val;
                    if (lists[k]->next != nullptr) {
                        curr_temp->next = new ListNode();
                        curr_temp = curr_temp->next;
                    }
                    lists[k] = lists[k]->next;
                }
            }

            out = temp;
            temp = new ListNode();
            curr_temp = temp;
        }
        return out;
    }
};