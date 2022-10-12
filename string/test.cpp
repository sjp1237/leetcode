#define _CRT_SECURE_NO_WARNINGS 1
#include"string.hpp"



int main() {
	string s("hello world");


	sjp::string s1("hello sjp");
	sjp::string s2(s1);
	s2 += "abc";
	s2.insert(0, 'z');
	s2.erase(1);
	s2.pop_back();
	s2.reverse(20);
	s2.resize(24, 'a');
	for (auto ch : s2) {
		cout << ch;
	}
	return 0;
}