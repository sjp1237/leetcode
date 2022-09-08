#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//947. �Ƴ�����ͬ�л�ͬ��ʯͷ

//n ��ʯͷ�����ڶ�άƽ���е�һЩ����������ϡ�ÿ������������ֻ����һ��ʯͷ��
//���һ��ʯͷ�� ͬ�л���ͬ�� ��������ʯͷ���ڣ���ô�Ϳ����Ƴ����ʯͷ��
//����һ������Ϊ n ������ stones ������ stones[i] = [xi, yi] ��ʾ�� i ��ʯͷ��λ�ã����� �����Ƴ���ʯ�� �����������


//˼·�����鼯���������ʯͷ������=ʯͷ����-ʯ�ӵļ��ϣ�����ͬ��������ͬ��
//���ò��鼯�����ܹ��ж��ٸ�����

class Solution {
public:
    static int removeStones(vector<vector<int>>& stones) {
        vector<int> v(stones.size(), -1);//���ĸ��ڵ�

        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                vector<int>& vx = stones[i];
                vector<int>& vy = stones[j];

                //ֻ�е�ͬ�л���ͬ�е�ʱ��Ž��кϲ�
                if (vx[0] == vy[0] || vx[1] == vy[1]) {
                    int rootx = i, rooty = j;
                    while (v[rootx] >= 0) {//�ҵ���ͬ�ĸ��ڵ�
                        rootx = v[rootx];
                    }

                    while (v[rooty] >= 0) {
                        rooty = v[rooty];
                    }

                    if (rootx != rooty) {
                        v[rootx] += v[rooty];
                        v[rooty] = rootx;
                    }
                }
            }
        }
        int res = 0;
        for (auto i : v) {
            if (i < 0) {
                res++;
            }
        }
        return stones.size() - res;
    }
};


int main() {
    vector<vector<int>> vv = { {0,0} ,{0,1},{1,0},{1,2},{2,1},{2,2} };
    cout << Solution::removeStones(vv)<<endl;

    return 0;
}