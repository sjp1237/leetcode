#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//��Ŀ��ʢ���ˮ������
//����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵���(i, 0) ��(i, height[i]) ��
//�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
//�����������Դ�������ˮ����
//˵�����㲻����б������

//˼·����������ָ�룬����ָ��ľ����������ĵ�
//�ҵ����ұߵ���С�ߣ����������=�����ĵ�*��С��
//��¼������������ֵ���ٽ���С�ߵı����м俿£���ظ����ϲ���

class Solution {
public:
    static int maxArea(vector<int>& height) {
        long res = 0;//��¼����ʢ����ˮ
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int minheight = min(height[left], height[right]);
            long tmp = (long)(right - left) * minheight;
            res = max(res, tmp);
            if (minheight == height[left])left++;
            else right--;
        }
        return res;
    }
};


int main() {
    vector<int> tmp = { 1, 8, 6, 2, 5, 4, 8, 3, 7,100 };
    int res = Solution::maxArea(tmp);
    cout << res << endl;
    return 0;
}