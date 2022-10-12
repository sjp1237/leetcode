#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
#include<assert.h>
using namespace std;
namespace sjp {
	class string {
		typedef char* iterator;
	public:
		string(const char* s = "") {
			if (s == nullptr)return;
			size = strlen(s);
			capacity = size;
			str = new char[size+1];
			strcpy(str, s);
		}

		//
		void swap(string& s) {
			std::swap(s.str, str);
			std::swap(s.size, size);
			std::swap(s.capacity, capacity);
		}

		//拷贝构造函数涉及深拷贝问题
		//创建一个临时对象，然后交换其资源
		string(const string& s) {
			string tmp(s.str);
			this->swap(tmp);
		}

		//涉及深拷贝的问题
		string& operator=(string s) {
			this->swap(s);
			return *this;
		}

		void reverse(size_t newcapacity) {
			if (newcapacity > capacity) {
				char* newstr = new char[newcapacity+1];
				strcpy(newstr, str);
				capacity = newcapacity;
				delete[] str;
				str = newstr;
			}
		}

		void resize(size_t newsize, char ch = '\0') {
			if (newsize > capacity) {
				reverse(newsize);
				memset(str + size, ch, newsize - size);
			}
			str[newsize] = '\0';
			size = newsize;
		}

		void push_back(char ch) {
			if (size == capacity) {
				reverse(capacity * 2);
			}
			str[size++] = ch;
			str[size] = '\0';
		}

		void insert(int pos, const char ch = ' ') {
			assert(pos >= 0 && pos <= size);
			if (size == capacity) {
				reverse(2 * capacity);
			}
			
			int cur = size ;
			while (cur>=pos) {
				str[cur + 1] = str[cur];
				cur--;
			}
			size++;
			str[pos] = ch;
		}

		void erase(int pos) {
			assert(pos >= 0 && pos <= size);
			int cur = pos;
			while (cur < size) {
				str[cur] = str[cur + 1];
				cur++;
			}
			size--;
		}

		void pop_back() {
			erase(size-1);
		}

		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}

		string& operator += (const char* s) {
			int _size = strlen(s);
			if (size + _size > capacity) {
				reverse(2 * capacity + _size);
			}

			strcpy(str + size, s);
			size += _size;
			return *this;
		}

		char& operator[](int pos)const {
			return str[pos];
		}

		char& operator[](int pos) {
			return str[pos];
		}

		~string() {
			if (str) {
				delete[] str;
				str = nullptr;
			}
		}


		iterator begin() {
			return str;
		}

		iterator end() {
			return str + size;
		}

		int Size() {
			return size;
		}

		bool empty() {
			return size == 0;
		}


	private:
		char* str;
		int size = 0;
		int capacity = 0;
	};
}