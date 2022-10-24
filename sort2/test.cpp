#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<mutex>

//—°‘Ò≈≈–Ú
void selectsort(vector<int>& v) {
	int tmp = 0;
	for (int i = 1; i < v.size(); i++) {
		tmp = v[i];
		int j = i - 1;
		for (j = i - 1; j >= 0; j--) {
			if (v[j] > tmp) {
				v[j + 1] = v[j];
			}
			else {
				break;
			}
		}
		v[j + 1] = tmp;
	}
}




class HungryMan {
public:
	HungryMan* getindex() {
		return index;
	}
private:
	static HungryMan* index;
private:
	HungryMan() {};
	HungryMan(HungryMan&) = delete;
	HungryMan* operatro(HungryMan& const) = delete;
};
HungryMan* HungryMan::index = new HungryMan();

//∂—≈≈–Ú
//πÈ≤¢≈≈–Ú

//¿¡∫∫ƒ£ Ω
//

class LazyMan {
public:
	LazyMan* getindex(){
		if (index == nullptr) {
			lock.lock();
			if (index == nullptr) {
				index = new LazyMan();
			}
			lock.unlock();
		}
		return index;
	}
private:
	LazyMan() {};
private:
	static LazyMan* index;
	static mutex lock;
private:
	LazyMan(LazyMan& const) = delete;
	LazyMan* operator=(LazyMan& const) = delete;
};
LazyMan* LazyMan::index = nullptr;
mutex LazyMan::lock;




int main() {
	vector<int> v = { 324,54312,54,32,1,2 };
	selectsort(v);
	for (auto i : v) {
		cout << i << " ";
	}

	//HungryMan* l1 = new HungryMan();
	return 0;
}
