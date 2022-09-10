#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


template<class T>
class unionfind {
public:
	unionfind(T* x,size_t n) {
		for (int i = 0; i < n; i++) {
			v.push_back(-1);
			mp.insert(pair<T,size_t>(x[i], i));
		}
	}

	bool Find(const T x, const T y) {
		size_t index_x = mp[x];//映射到
		size_t index_y = mp[y];
		while (v[index_x] >= 0) {
			index_x = v[index_x];
		}

		while (v[index_y] >= 0) {
			index_y = v[index_y];
		}

		return index_x == index_y;
	}

	bool Union(const T x, const T y) {
		size_t index_x = mp[x];
		size_t index_y = mp[y];

		while (v[index_x] >= 0) {
			index_x = v[index_x];
		}

		while (v[index_y] >= 0) {
			index_y = v[index_y];
		}

		if (index_x == index_y) {
			//两个元素是在同一个集合上
			//合并失败
			return false;
		}

		v[index_x] += v[index_y];
		v[index_y] = index_x;
		return true;
	}

private:
	vector<int> v;
	unordered_map<T, int> mp;
};


class unionfind1 {
public:
	unionfind1(int* x, size_t n) {
		for (int i = 0; i < n; i++) {
			v.push_back(-1);
		}
	}

	bool Find(const int x, const int y) {
		int root_x = x, root_y = y;
		while (v[root_x] >= 0) {
			root_x = v[root_x];
		}

		while (v[root_y] >= 0) {
			root_y = v[root_y];
		}

		return root_x == root_y;
	}

	bool Union(const int x, const int y) {
		int root_x = x, root_y = y;
		while (v[root_x] >= 0) {
			root_x = v[root_x];
		}
		//此时root_x为负数，则为x相对应集合的根节点
		while (v[root_y] >= 0) {
			root_y = v[root_y];
		}
		//此时root_y为负数，则为y相对应集合的根节点
		if (root_x == root_y) {
			//两个元素是在同一个集合上
			//合并失败
			return false;
		}

		v[root_x] += v[root_y];
		v[root_y] = root_x;
		return true;
	}

private:
	vector<int> v;
};

