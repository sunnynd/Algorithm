#include<iostream>

using namespace std;

int n;
char arr[16][101];

bool check(bool alpa[]) {
	for (int cnt1 = 0; cnt1 < 26; cnt1++) {
		if (alpa[cnt1] == false) return false;
	}
	return true;
}

int arr_size(int index) {
	for (int cnt1 = 0; cnt1 < 101; cnt1++) {
		if (arr[index][cnt1] == NULL) {
			return cnt1;
		}
	}
	return 101;
}

void arr_check(int index, bool alpa[]) {
	for (int cnt1 = 0; cnt1 < arr_size(index); cnt1++) {
		alpa[arr[index][cnt1] - 'a'] = true;
	}
}

int gub(int index) {
	int a = 1;
	for (int cnt1 = 1; cnt1 <= n - index; cnt1++) {
		a *= 2;
	}
	return a;
}
int dp(int index, bool alpa[]) {
	if (check(alpa)) return gub(index);
	if (index == n) return 0;
	
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

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int cnt1 = 0; cnt1 < 16; cnt1++) {
			for (int cnt2 = 0; cnt2 < 101; cnt2++) {
				arr[cnt1][cnt2] = NULL;
			}
		}

		bool alpa[26];

		for (int cnt1 = 0; cnt1 < 26; cnt1++) {
			alpa[cnt1] = false;
		}

		cin >> n;

		for (int cnt1 = 0; cnt1 < n; cnt1++) {
			cin >> arr[cnt1];
		}

		cout << "#" << test_case << " " << dp(0, alpa) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}