#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0, len = 0, temp;
	int test[100];
	printf("please input number:\n");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		printf("please input the %d:\n", i + 1);
		scanf("%d", &test[i]);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (test[j] > test[j + 1])
			{
				temp = test[j];
				test[j] = test[j + 1];
				test[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", test[i]);
	}
	printf("\n ");
}
