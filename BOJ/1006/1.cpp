#include<iostream>


int a[10001];
int b[10001];
int c[10001];
int** an;
int N;
int W;


void carc(int st);
int min(int a, int b);

int main()
{
	int T, cnt;
	std::cin >> T;
	while (T--)
	{
		cnt = 9999999;
		std::cin >> N >> W;
		an = new int* [2]();
		for (int i = 0; i < 2; i++)
		{
			an[i] = new int[N];
		}
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < N; i++)
			{
				std::cin >> an[j][i];
			}
		}
		a[0] = 0;
		b[0] = 1;
		c[0] = 1;
		carc(0);
		cnt = min(cnt, a[N]);
		if (N > 1 && an[0][0] + an[0][N - 1] <= W && an[1][0] + an[1][N - 1]<=W)
		{
			a[1] = 0;
			b[1] = 1;
			c[1] = 1;
			carc(1);
			cnt = min(cnt, a[N - 1] + 2);
		}
		if (N > 1 && an[0][0] + an[0][N - 1] <= W)
		{
			a[1] = 1;
			b[1] = 2;
			c[1] = an[1][0] + an[1][1] <= W ? 1 : 2;
			carc(1);
			cnt = min(cnt, c[N - 1] + 1);
		}
		if (N > 1 && an[1][0] + an[1][N - 1]<=W)
		{
			a[1] = 1;
			b[1] = an[0][0] + an[0][1] <= W ? 1 : 2;
			c[1] = 2;
			carc(1);
			cnt = min(cnt, b[N - 1] + 1);
		}
		std::cout << cnt << std::endl;
	}

	return 0;
}

int min(int a, int b)
{
	if (a > b) return b;
	return a;
}
void carc(int st)
{
	for (int i = st; i < N; i++)
	{
		a[i + 1] = min(b[i], c[i]) + 1;
		if (an[0][i] + an[1][i] <= W)
		{
			a[i + 1] = min(a[i + 1], a[i] + 1);
		}
		if (i > 0 && an[0][i - 1] + an[0][i] <= W && an[1][i - 1] + an[1][i] <= W)
		{
			a[i + 1] = min(a[i + 1], a[i - 1] + 2);
		}
		if (i != N)
		{
			b[i + 1] = a[i + 1] + 1;
			if (an[0][i] + an[0][i + 1] <= W)
				b[i + 1] = min(b[i + 1], c[i] + 1);
			c[i + 1] = a[i + 1] + 1;
			if (an[1][i] + an[1][i + 1] <= W)
				c[i + 1] = min(c[i + 1], b[i] + 1);
		}
	}
}