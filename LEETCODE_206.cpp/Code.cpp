#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        vector<int> arr(count);
        ListNode* curr = head;
        for (int i = 0; i < count; i++) {
            arr[i] = curr->val;
            curr = curr->next;
        }
        ListNode* pre = head;
        for (int i = count - 1; i >= 0; i--) {
            pre->val = arr[i];
            pre = pre->next;
        }
        return head;
    }
};
void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    head = s.reverseList(head);
    display(head);
}