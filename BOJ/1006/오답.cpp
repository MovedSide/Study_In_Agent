#include<iostream>

int main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, W, t = 0;
		std::cin >> N >> W;
		int* an = new int[N * 2]();
		for (int j = 0; j < N * 2; j++)
		{
			std::cin >> an[j];
		}
		int** set = new int* [N * 3]();
		for (int i = 0; i < N * 3; i++)
			set[i] = new int[2]();
		for (int j = 0; j < N; j++)
		{
			if (an[j] + an[(j + 1) % N] <= W)
			{
				set[t][0] = j;
				set[t][1] = (j + 1) % N;
				t++;
			}
			if (an[j] + an[j + N] <= W)
			{
				set[t][0] = j;
				set[t][1] = j + N;
				t++;
			}
		}
		for (int j = N; j < N * 2; j++)
		{
			if (an[j] + an[(j + 1) % N + N] <= W)
			{
				set[t][0] = j;
				set[t][1] = (j + 1) % N + N;
				t++;
			}
		}
		int max = 0;

		for (int x = 0; x < t; x++)
		{
			int cnt = 0;
			int* sw = new int[N * 2]();
			for (int y = x; y < t; y++)
			{
				if (sw[set[y][0]] == 0 && sw[set[y][1]] == 0)
				{
					sw[set[y][0]] = -1;
					sw[set[y][1]] = -1;
					cnt++;
				}
			}
			if (max < cnt)
				max = cnt;
			delete[]sw;
		}
		std::cout <<"*"<< max + (N * 2 - max * 2) << std::endl;
	}

	return 0;
}