#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
//给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

//输入:n=10
//输出；9
// 
//输入: n = 1234
//输出 : 1234

//输入: n = 332
//输出 : 299


//思路：
//从左向右找到递减的数字，并将它的数字-1，如果前面有相同的数字，则找到相同数字的第一个
//其余后面的所有的数字都设置为9
class Solution {
public:
    static int monotoneIncreasingDigits(int n) {
        string s = to_string(n);//转换为字符串
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > s[i + 1]) {
                while (i - 1 >= 0 && s[i - 1] == s[i]) {
                    i--;
                }
                s[i] = s[i] - 1;
                i++;
                while (i < s.size()) {
                    s[i] = '9';
                    i++;
                }
            }
        }
        int res = stoi(s);
        return res;
    }
};


int main() {

    cout << Solution::monotoneIncreasingDigits(1232) << endl;
    cout << Solution::monotoneIncreasingDigits(2341) << endl;
    cout << Solution::monotoneIncreasingDigits(22221) << endl;
    cout << Solution::monotoneIncreasingDigits(267782) << endl;
    cout << Solution::monotoneIncreasingDigits(332) << endl;


	return 0;
}