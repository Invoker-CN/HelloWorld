#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int rounds = 0;
	cin >> rounds;
	map<string, int> board;
	map<string, int>::iterator it;
	vector<string> names;
	string name="\0";
	vector<int> scores;
	int score = 0;
	//接收处理并储存输入信息
	for(int i=1;i<=rounds;i++)
	{
		cin >> name >> score;
		board[name] += score;
		names.push_back(name);
		scores.push_back(score);
	}
	//找出最高分
	int max = board.begin()->second;
	for (map<string, int>::iterator it = board.begin(); it != board.end(); ++it)
	{
		if ((it->second) > max)
		{
			max = it->second;
		}
	}
	//找出最高分对应的name
	vector<string> pre_winners;
	for (map<string, int>::iterator it = board.begin(); it != board.end(); ++it)
	{
		if (it->second == max)
		{
			pre_winners.push_back(it->first);
		}
	}
	//判断有几个
	if (pre_winners.size() == 1)
	{
		cout << pre_winners[0] << endl;
	}
	else
	{
		for (map<string, int>::iterator it = board.begin(); it != board.end(); ++it)
		{
			it->second = 0;
		}
		int i = 0;
		for (i = 0; i < names.size(); i++)
		{
			board[names[i]] += scores[i];
			if (board[names[i]] >= max && (find(pre_winners.begin(), pre_winners.end(), names[i]) != pre_winners.end()))
			{
				cout << names[i];
				break;
			}
		}
	}

	return 0;
}