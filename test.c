#include <stdio.h>
#include <math.h>
#define float double
int main()
{
	float x = 0, y = 0, sum = 0, m, n;
	int i;
	for (i = 0; i <= 18; i++)
	{
		if (i % 2 != 0)
		{
			m = 2 * i + 1;
			m = pow(3, i) / m;
			x = x + m;
		}
		else
		{
			n = 2 * i + 1;
			n = pow(3, i) / n;
			x = x + n;
		}
	}
	printf("%.5f\n", n - m);
	system("pause");
}