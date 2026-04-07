#include <stdio.h>
#include <stdbool.h>

int get_value (int);

int N = 0;

int
main (int argc, char **argv)
{
	int sum = 0;

	printf ("input >> ");
	scanf ("%d", &N);

	sum += get_value (3);
	sum += get_value (5);
	sum -= get_value (15);

	printf ("%d\n", sum);
}

int
get_value (int n)
{
	int val = n + n * (N / n);
	return val * ((N / n) / 2) + ((N / n) % 2 == 1 ? val / 2 : 0);
}
