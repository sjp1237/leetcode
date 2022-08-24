#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



//�����ⷨ
class Solution1 {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (target == nums[i] + nums[j]) {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

//��ϣ�������Ƚ� ����-�±� ӳ�䵽��ϣ���У�Ȼ�����������ÿһ�����ݣ����target-nums[i]���ڹ�ϣ���У���num[i] �� target-num[i]���±귵��
class Solution2 {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hp;
        for (int i = 0; i < nums.size(); i++) {
            hp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hp.count(target - nums[i]) && hp[target - nums[i]] != i) {
                res.push_back(i);
                res.push_back(hp[target - nums[i]]);
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<int> v1 = { 2,7,11,15 };
    int target = 9;

    vector<int> res1 = Solution1::twoSum(v1, target);
    vector<int> res2 = Solution2::twoSum(v1, target);


    for (auto i : res1) {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : res2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}