#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* temp = head;
                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp; 
            }
        }
        return NULL; 
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;
    Solution s;
    ListNode* cycleNode = s.detectCycle(head);
    if (cycleNode != NULL) {
        cout << "Cycle detected at node with value: "
             << cycleNode->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
}
