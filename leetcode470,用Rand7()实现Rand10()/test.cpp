#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//��Ŀ��
//�������� rand7 ������[1, 7] ��Χ�ڵľ��������������дһ������ rand10 ����[1, 10] ��Χ�ڵľ������������


//˼·��
// ��rand������ܹ���������0��1�ĺ���
//Ȼ�����ɵ�0��1������λ���ܹ����ɾ�������0000~1111
//0000~1111��ȡֵ��Χ��0~15�����������1~10�����֣���������ֱ���ܹ�����1~10�����֣���˾��ܹ���������1~10

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

//���Դ���
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