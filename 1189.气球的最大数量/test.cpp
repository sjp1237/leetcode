#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
//字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。


//输入：text = "nlaebolko"
//输出：1
//
//输入：text = "loonbalxballpoon"
//输出：2


//思路:统计balon中的次数，
//如果是l或者o则，则将数字除以2
//则将统计balon中最小的次数，既可拼"balloon"的最小次数

class Solution {
public:
    static int maxNumberOfBalloons(string text) {
        int arr[26] = { 0 };
        for (auto ch : text) {
            arr[ch - 'a']++;
        }
        string s = "ablon";
        int res = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            int count = arr[s[i] - 'a'];
            if (s[i] == 'l' || s[i] == 'o') {
                count /= 2;
            }
            res = min(count, res);
        }
        return res;
    }
};


int main() {
    int i = Solution::maxNumberOfBalloons("loonbalxballpoon");
    cout << i << endl;
	return 0;
}