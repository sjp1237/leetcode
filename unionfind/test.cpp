#define _CRT_SECURE_NO_WARNINGS 1
#include"unionfind.hpp"


void test1() {
	string s[] = { "abc","acd","eee","akdfjk" };
	unionfind<string> f(s, 4);
	f.Union(s[0], s[1]);

}
int main() {
	test1();
	return 0;
}