#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

//����
//һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        int tmp = 0;
        *num1 = 0;
        *num2 = 0;
        for (auto& num : data)//���ó�������ͬ�����ֵ������
        {
            tmp ^= num;
        }

        int i;
        for (i = 0; i < 32; i++)//�ҳ������һ��bitλ1
        {
            if ((tmp >> i) & 1)
            {
                break;
            }
        }

        for (auto& num : data)
        {
            if ((num >> i) & 1)//����λ�õ�1�������ó���һ��ֻ����һ�ε�����
                (*num1) ^= num;
            else//����λ�õ�0�������ó�������ֻ����һ�ε�����
                (*num2) ^= num;
        }

    }
};

int main()
{

}
