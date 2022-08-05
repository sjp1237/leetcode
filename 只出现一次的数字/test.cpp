#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

//描述
//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        int tmp = 0;
        *num1 = 0;
        *num2 = 0;
        for (auto& num : data)//最后得出两个不同的数字的异或结果
        {
            tmp ^= num;
        }

        int i;
        for (i = 0; i < 32; i++)//找出结果第一个bit位1
        {
            if ((tmp >> i) & 1)
            {
                break;
            }
        }

        for (auto& num : data)
        {
            if ((num >> i) & 1)//将该位置的1进行异或得出第一个只出现一次的数字
                (*num1) ^= num;
            else//将该位置的0进行异或得出第两个只出现一次的数字
                (*num2) ^= num;
        }

    }
};

int main()
{

}
