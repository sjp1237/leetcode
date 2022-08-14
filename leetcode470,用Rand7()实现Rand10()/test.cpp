#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//题目：
//给定方法 rand7 可生成[1, 7] 范围内的均匀随机整数，试写一个方法 rand10 生成[1, 10] 范围内的均匀随机整数。


//思路：
// 将rand改造成能够均匀生成0和1的函数
//然后将生成的0和1进行移位就能够生成均匀生成0000~1111
//0000~1111的取值范围是0~15，如果不是在1~10的数字，就重做，直到能够生成1~10的数字，因此就能够均匀生成1~10

int rand7() {
	return rand() % 7 + 1;
}

class Solution {
public:
    static int rand2() {
        int i = -1;
        while (1) {
            int j = rand7();
            if (j <= 3) {
                i = 0;
                break;
            }
            else if (j >= 3 && j <= 6) {
                i = 1;
                break;
            }
        }
        return i;
    }
    static int rand10() {
        int res = -1;
        while (1) {
            int i0 = rand2(), i1 = rand2(), i2 = rand2(), i3 = rand2();       
            int tmp = i0 << 0;
            tmp += (i1 << 1);
            tmp += (i2 << 2);
            tmp += (i3 << 3);
            if (tmp >= 1 && tmp <= 10) {
                res = tmp;
                break;
            }
        }
        return res;
    }
};

//测试代码
void test(int i) {
    for (int j = 0; j < i; j++) {
        int tmp = Solution::rand10();
        if ( tmp>= 1 && tmp <= 10) {
            cout << tmp << "  ";
        }
        else {
            cout << "error" << endl;
        }
    }
}
int main() {
	srand(time(NULL));
    test(10000);

}