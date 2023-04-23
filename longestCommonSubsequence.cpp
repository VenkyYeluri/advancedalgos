#include <iostream>
#include <vector>

using namespace std;

void longestCommonSubsequence(string text1, string text2)
{
	int x = text1.length();
	int y = text2.length();
	vector<vector<int>> tab(x + 1, vector<int>(y + 1, 0));
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (text1[i - 1] == text2[j - 1])
			{
				tab[i][j] = tab[i - 1][j - 1] + 1;
			}
			else
			{
				tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
			}
		}
	}
	cout << tab[x][y] << endl;
}

int main(int argc, char* argv[])
{
	string text1, text2;
	cin >> text1 >> text2;
	longestCommonSubsequence(text1, text2);
	return 0;
}
