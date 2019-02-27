#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


int k;
string str;
vector<string> str_list;


bool compare(string s1, string s2) {
	transform(s1.begin(), s1.end(), s1.begin(), tolower);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);

	return strcmp(s1.c_str(), s2.c_str()) < 0;
	//return s1.compare(s2) < 0;
}

int main() {
	int test_cnt;
	cin >> test_cnt;
	for (int t = 0; t < test_cnt; t++) {
		cin >> k >> str;
		str_list.clear();
		if (k > str.size()) {
			cout << "#" << t + 1 << " none" << endl;
		}
		for (int i = str.size() - 1; i >= 0; i--) {
			str_list.push_back(str.substr(i, str.size() - i));
		}
		sort(str_list.begin(), str_list.end(), compare);
		/*
		for (int i = 0; i < str_list.size(); i++) {
			cout << i << " : " << str_list[i] << endl;
		}*/
		
		cout << "#" << t+1 << " " << str_list[k-1] << endl;
	}
}