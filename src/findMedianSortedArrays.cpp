#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)  {
#if 1
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    
    while (left <= right) {
        int i = (left + right) / 2; // nums1 的分割点
        int j = (m + n + 1) / 2 - i; // nums2 的分割点
        
        // 获取左半部分和右半部分的边界值
        int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];
        int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];
        
        // 检查是否是有效分区
        if (left1 <= right2 && left2 <= right1) {
            // 总长度为奇数
            if ((m + n) % 2 == 1) {
                return std::max(left1, left2);
            }
            // 总长度为偶数
            return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
        }
        // 调整二分查找范围
        else if (left1 > right2) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }
    
    // 如果输入无效（理论上不会到达这里）
    return 0.0;

#endif

#if 0
        
#endif
    }
};

int main(int argc, char** argv) {
    std::vector<int> num1 = {2,2,4,4};
    std::vector<int> num2 = {2,2,4,4};
    Solution solution;

    double number = solution.findMedianSortedArrays(num1, num2);

    return 0;
}