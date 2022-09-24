#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//
//������ 01.05.һ�α༭
//
//�ַ��������ֱ༭���� : ����һ��Ӣ���ַ���ɾ��һ��Ӣ���ַ������滻һ��Ӣ���ַ��� ���������ַ�������дһ�������ж������Ƿ�ֻ��Ҫһ��(�������)�༭��

//��������ַ�����������ַ����ϣ���ô�ǲ�����һ�α༭��
//��������ַ���ֻ���һ���ַ�����ôֻ��ֻ��һ���ַ�������һ���ַ���ͬ��
//��������ַ���������ȣ���ô��Ӧ��λ�õ��ַ�ֻ��һ����ͬ��
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size(), m = second.size();
        if (n - m == 1) {
            return  _oneEditAway(first, second);
        }
        else if (m - n == 1) {
            return _oneEditAway(second, first);
        }
        else if (n == m) {
            //�ַ������ʱ
            int flag = 0;//��¼��ͬ�ַ��ĸ���
            for (int i = 0; i < n; i++) {
                if (first[i] != second[i]) {
                    flag++;
                }
                if (flag > 1)return false;
            }

        }
        else {
            return false;
        }
        return true;
    }

    bool _oneEditAway(string& longstr, string& shortstr) {
        int pos1 = 0, pos2 = 0;
        while (pos1 < longstr.size() && pos2 < shortstr.size()) {
            if (longstr[pos1] == shortstr[pos2]) {
                pos1++;
                pos2++;
            }
            else {
                pos1++;
            }

            if (pos1 - pos2 > 1) {
                return false;
            }
        }
        return true;
    }
};