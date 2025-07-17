#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
    ListNode(ListNode* next) : val(next->val), next(next) { }
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {       
#if 1
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
#else
        std::vector<int> v1;
        std::vector<int> v2;

        ListNode* iList = l1;
        ListNode* jList = l2;

        while (iList != nullptr)
        {
            v1.push_back(iList->val);
            iList = iList->next;
        }

        while (jList != nullptr)
        {
            v2.push_back(jList->val);
            jList = jList->next;
        }

        std::reverse(v1.begin(), v1.end());
        std::reverse(v2.begin(), v2.end());

        long long num1 = 0, num2 = 0;
        for (int i = 0; i < v1.size(); ++i) {
            num1 = num1 * 10 + v1[i]; // 每位左移并加当前数字
        }
        for (int i = 0; i < v2.size(); ++i) {
            num2 = num2 * 10 + v2[i];
        }

        long long sum = num1 + num2;

        std::vector<int> digits;

        if(sum == 0) {
            digits.push_back(0);
        }
        else{
            while (sum > 0) {
                digits.push_back(sum % 10); // 获取最低位
                sum /= 10;                  // 移除最低位
            }
        }
        
        std::reverse(digits.begin(), digits.end());
    
        ListNode* lSum = nullptr;

        int temp = 0;
        while (temp < digits.size())
        {
            lSum = new ListNode(digits[temp], lSum);
            ++temp;
        }

        return lSum;
#endif
    }
};


int main(int argc, char** argv) {
    Solution solution;

    std::vector<int> nums = { 3,2,4 };
    int val = 6;

    ListNode* l1 = nullptr;
    l1 = new ListNode(9, l1);

    ListNode* l2 = nullptr;
    l2 = new ListNode(1, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);

    ListNode* newLength = solution.addTwoNumbers(l1, l2);

    std::cout << "newLength: " << &newLength << std::endl;

    return 0;
}
