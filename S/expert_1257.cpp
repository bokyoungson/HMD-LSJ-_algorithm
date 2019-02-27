#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <iterator>

using namespace std;

string str;
int k;
map<string, string> str_list;

int main() {
	int test_cnt;
	cin >> test_cnt;
	for (int t = 0; t < test_cnt; t++) {
		str_list.clear();
		cin >> k >> str;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 1; j < str.size() - i+1; j++) {
				string tmp = str.substr(i, j);
				transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
				str_list[tmp] = str.substr(i, j);
			}
		}
		if (k > str_list.size()) {
			cout << "#" << t + 1 << " none" << endl;
		}
		int count = 1;
		for (map<string, string>::iterator it = str_list.begin(); it != str_list.end(); it++) {
			if (count == k) {
				cout << "#" << t+1 << " " << it->second << endl;
				break;
			}
			count++;
		}
	}
}