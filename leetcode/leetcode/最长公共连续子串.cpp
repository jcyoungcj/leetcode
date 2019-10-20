//���룺text1 = "abcde", text2 = "ace"
//�����3
//���ͣ�������������� "ace"�����ĳ���Ϊ 3��

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	
	int longestCommonSubstr(string text1, string text2) {
		if (text1.empty() || text2.empty()) return 0;
		int M = text1.size();
		int N = text2.size();
		int maxCommonLen = 0;
		int endIndex = 0; 
		// dp[i][j]����text1ǰi������text2ǰj���������ƥ��ֵ
		vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (text1[i] == text2[j]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				if (dp[i][j] > maxCommonLen) {
					endIndex = i;
					maxCommonLen = dp[i][j];
				}
			}
		}
		return maxCommonLen;
	}
};
