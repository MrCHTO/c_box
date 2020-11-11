#include <stdio.h>
#include <stdlib.h>
void Bubble(int arr[], int length)
{
	int temp;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
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
	Bubble(test, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", test[i]);
	}
	printf("\n ");
	system("pause");
}
