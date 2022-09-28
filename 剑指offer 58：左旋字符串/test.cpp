#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，
//该函数将返回左旋转两位得到的结果"cdefgab"。

class Solution {
public:
    static  void _swap(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    static string reverseLeftWords(string& s, int n) {
        n = n % s.size();
        _swap(s, 0, n - 1);
        _swap(s, n, s.size() - 1);
        _swap(s, 0, s.size() - 1);
        return s;
    }
};


int main() {
    string s = "abcdef";
    Solution::reverseLeftWords(s, 3);
    cout << s << endl;
    return 0;
}