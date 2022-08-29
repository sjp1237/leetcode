#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//
////leetcode 9.������
//����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��
//��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
//���磬121 �ǻ��ģ��� 123 ���ǡ�

//���룺x = 121
//�����true


//������ת��Ϊstring�У����Բ��ÿ���int�������
//ʱ�临�Ӷ�ΪO(n)
//�ռ临�Ӷ�ΪO(n)
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


//�����ֽ����������������������ԭ����������ͬ����Ϊ���Ĵ�
//ʱ�临�Ӷ�ΪO(1)
//�ռ临�Ӷ�ΪO(n)
class Solution2 {
public:
    static bool isPalindrome(int x) {
        if (x < 0)return false;
        int base = 1;//�ж������ж���λ
        long tmp = x;
        while (tmp / 10) {
            base *= 10;
            tmp /= 10;
        }

        long res = 0;
        tmp = x;
        //��������
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