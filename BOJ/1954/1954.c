#include <stdio.h>
#include <stdlib.h>


int main()
{

	int a[100], b[100], t[100];
	int i, n, m;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
		t[i] = 1;
	}
	scanf("%d", &m);

	while (1)
	{
		int gas = a[0] * t[0] + b[0];
		int sw = 0;
		for (i = 1; i < n; i++)
		{
			if (gas > (a[i] * t[i] + b[i]))
			{
				++t[i];
				sw = 1;
				break;
			}
			else if (gas < (a[i] * t[i] + b[i]))
			{
				++t[0];
				sw = 1;
				break;
			}

		}
		if (sw == 0)
		{
			int sum = 0;
			for (i = 0; i < n; i++)
			{
				sum += t[i];
			}
			if (sum == m)
			{
				printf("%d", gas);
				break;
			}
			else if (sum > m)
			{
				printf("0");
				break;
			}
			else
			{
				++t[0];
			}
		}



	}






	return 0;
}