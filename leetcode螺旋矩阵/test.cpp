#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//leetcode54����������
//����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int i = 0, j = 0;
        res.push_back(matrix[i][j]);
        matrix[i][j] = 101;
        while (true) {
                
            while (j + 1 < matrix[0].size() && matrix[i][j + 1] != 101) {
                j++;
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
            }
            while (i + 1 < matrix.size() && matrix[i + 1][j] != 101) {
                i++;
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
            }
            while (j - 1 >= 0 && matrix[i][j - 1] != 101) {
                j--;
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;

            }
            while (i - 1 >= 0 && matrix[i - 1][j] != 101) {
                i--;
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
            }
            if (i - 1 >= 0 && matrix[i - 1][j] != 101
                || j - 1 >= 0 && matrix[i][j - 1] != 101
                || i + 1 < matrix.size() && matrix[i + 1][j] != 101
                || j + 1 < matrix[0].size() && matrix[i][j + 1] != 101) {
                continue;
            }
            break;
        }
        return res;
    }
};

int main() {

	return 0;
}