#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
//�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2��
//�ú�������������ת��λ�õ��Ľ��"cdefgab"��

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