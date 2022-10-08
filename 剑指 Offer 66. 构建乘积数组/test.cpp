#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//剑指 Offer 66. 构建乘积数组
//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
//即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
//思路一
//建立左累计乘和右边的累计乘的数组
//最后再将左累计乘和右边的累计乘进行相乘即为每个位置的答案
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.size() == 0)return a;
        vector<int> res(a.size(), 0);
        res[0] = 1;
        for (int i = 1; i < a.size(); i++) {
            res[i] = res[i - 1] * a[i - 1];
        }

        int right = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            res[i] = res[i] * right;
            right *= a[i];
        }

        return res;
    }
};



//思路二：
//将res数组中先从左向右先进行相对应位置的左累计乘
//然后再逆序的从右向左进行相对应的右边的累计乘。
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.size() == 0)return a;
        vector<int> res(a.size(), 0);
        res[0] = 1;
        for (int i = 1; i < a.size(); i++) {
            res[i] = res[i - 1] * a[i - 1];
        }

        int right = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            res[i] = res[i] * right;
            right *= a[i];
        }

        return res;
    }
};


int main() {

    
}