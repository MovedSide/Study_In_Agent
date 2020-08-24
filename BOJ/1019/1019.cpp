#include<iostream>

int num[10];

void calc(int& start, int& end, int& p);
void cnt(int index, int p);


int main()
{
	int N;
	int a[10] = { 0 };
	std::cin >> N;
	int start = 1;
	int end = N;
	int pa = 1;
	while (start < end)
	{
		calc(start, end, pa);
		pa *= 10;
	}
	if (end == 1) pa = pa * 10;
	if (start == end) cnt(start, pa/10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << num[i] << ' ';
	}
	return 0;
}


void calc(int& start, int& end, int& p)
{
	while (start != 10)
	{
		cnt(start, p);
		start++;
		if (start == end) return;
	}
	while (end % 10 != 9)
	{
		cnt(end, p);
		end--;
		if (start == end) return;
	}
	int k;
	end /= 10;
	start /= 10;
	k = end - start + 1;
	for (int i = 0; i < 10; i++)
	{
		num[i] += k * p;
	}
}
void cnt(int nm, int p)
{
	int t = nm;
	while (t != 0)
	{
		num[t % 10] += p;
		t /= 10;
	}
}
