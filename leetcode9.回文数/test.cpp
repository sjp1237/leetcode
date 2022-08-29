#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//
////leetcode 9.回文数
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//例如，121 是回文，而 123 不是。

//输入：x = 121
//输出：true


//将数字转换为string中，可以不用考虑int类型溢出
//时间复杂度为O(n)
//空间复杂度为O(n)
class Solution1 {
public:
    static bool isPalindrome(int x) {
        if (x < 0)return false;
        string s = to_string(x);
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++, right--;
        }
        return true;
    }
};


//将数字进行逆序，如果逆序后的数字与原来的数字相同，则为回文串
//时间复杂度为O(1)
//空间复杂度为O(n)
class Solution2 {
public:
    static bool isPalindrome(int x) {
        if (x < 0)return false;
        int base = 1;//判断数字有多少位
        long tmp = x;
        while (tmp / 10) {
            base *= 10;
            tmp /= 10;
        }

        long res = 0;
        tmp = x;
        //进行逆序
        while (tmp) {
            res += (tmp % 10) * base;
            base /= 10;
            tmp /= 10;
        }
        return x == res ? true : false;
    }
};
int main() {
    cout << Solution1::isPalindrome(121)<< endl;
    cout << Solution2::isPalindrome(121) << endl;
    cout << Solution1::isPalindrome(-121) << endl;
    cout << Solution2::isPalindrome(-121) << endl;
    cout << Solution1::isPalindrome(1211) << endl;
    cout << Solution2::isPalindrome(1211) << endl;


}