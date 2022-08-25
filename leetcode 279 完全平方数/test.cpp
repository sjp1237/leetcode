#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//279. ��ȫƽ����
//����һ������ n ������ ��Ϊ n ����ȫƽ�������������� ��
//��ȫƽ���� ��һ����������ֵ������һ��������ƽ�������仰˵����ֵ����һ�������Գ˵Ļ������磬1��4��9 �� 16 ������ȫƽ�������� 3 �� 11 ���ǡ�


//��̬�滮
class Solution1 {
public:
    static int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
int main() {

    int res1=Solution1::numSquares(10);
    cout << res1 << endl;
	return 0;
}
