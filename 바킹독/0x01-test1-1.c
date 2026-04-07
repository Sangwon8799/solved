#include <stdio.h>
#include <stdbool.h>

int five = 5;

int get_five (int);

int main()
{
	int sum = 0;
	int n = 3;
	int N = -1;

	printf ("input >> ");
	scanf ("%d", &N);

	while (n <= N)
	{
		sum += get_five (n);
		sum += n;
		n += 3;
	}
	printf ("%d\n", sum);
}

int
get_five (int n)
{
	int value = 0;
	if (n > five)
	{
		if (five % 3 != 0)
			value += five;
		five += 5;
	}
	return value;
}
