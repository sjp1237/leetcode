#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//��ָ Offer 66. �����˻�����
//����һ������ A[0,1,��,n-1]���빹��һ������ B[0,1,��,n-1]������ B[i] ��ֵ������ A �г����±� i �����Ԫ�صĻ�, 
//�� B[i]=A[0]��A[1]������A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����
//˼·һ
//�������ۼƳ˺��ұߵ��ۼƳ˵�����
//����ٽ����ۼƳ˺��ұߵ��ۼƳ˽�����˼�Ϊÿ��λ�õĴ�
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



//˼·����
//��res�������ȴ��������Ƚ������Ӧλ�õ����ۼƳ�
//Ȼ��������Ĵ�������������Ӧ���ұߵ��ۼƳˡ�
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