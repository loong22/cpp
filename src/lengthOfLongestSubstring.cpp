#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
#if 0
        // 哈希集合，记录每个字符是否出现过
        std::unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = std::max(ans, rk - i + 1);
        }
        return ans;
#endif

#if 1
        std::unordered_map<char, int> charIndex; // 存储字符最后出现的索引
        int maxLen = 0, start = 0; // 滑动窗口起点和最大长度

        for (int end = 0; end < s.size(); ++end) {
            // 如果字符已出现且在当前窗口内，更新起点
            if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
                start = charIndex[s[end]] + 1;
            }
            charIndex[s[end]] = end; // 更新字符最新索引
            maxLen = std::max(maxLen, end - start + 1); // 更新最大长度
        }
        return maxLen;
#endif

#if 0        
        std::vector<char> subStr;

        int maxDepth = 0;
        for (int i = 1; i < s.size(); ++i) {
            subStr.push_back(s[i - 1]);
            if(subStr.size() >= 1 && s[i] == subStr[i - 1]) {
                maxDepth = fmax(maxDepth, subStr.size());
                subStr.resize(0);
            }

            if (s[i] == subStr[0])
            {
                maxDepth = fmax(maxDepth, subStr.size());
                subStr.resize(0);
            }
        }

        return maxDepth;
#endif
    }
};

int main(int argc, char** argv) {
    std::string str = "pwwkew";

    Solution solution;
    solution.lengthOfLongestSubstring(str);

    
    return 0;
}