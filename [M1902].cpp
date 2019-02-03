#include<iostream>
#include<string>

using namespace std;

int n;
char arr[16][101];

bool check(bool alpa[]) {
	for (int cnt1 = 0; cnt1 < 26; cnt1++) {
		if (alpa[cnt1] == false) return false;
	}
	return true;
}

void arr_check(int index, bool alpa[]) {
	for (int cnt1 = 0; cnt1 < arr[index].size(); cnt1++) {
		alpa[arr[index].at(cnt1) - 'a'] = true;
	}
}

int dp(int index, bool alpa[]) {

	if (index == n) return 0;
	if (check(alpa)) return 1;

	bool alpa_copy[26];
	for (int cnt1 = 0; cnt1 < 26; cnt1++) {
		alpa_copy[cnt1] = alpa[cnt1];
	}
	arr_check(index, alpa_copy);

	return dp(index + 1, alpa) + dp(index + 1, alpa_copy);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;

		for (int cnt1 = 0; cnt1 < n; cnt1++) {
			cin >> arr[cnt1];
		}

		bool alpa[26];

		cout << dp(0, alpa);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}