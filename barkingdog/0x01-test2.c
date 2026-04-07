#include <stdio.h>

int
main ()
{
	int arr[] = {4, 13, 63, 87};
	int seen[101] = {0};
	int N = 4;

	for (int i = 0; i < N; i++)
		seen[arr[i]] = 1;

	for (int i = 0; i < N; i++)
	{
		int need = 100 - arr[i];
		if (need != arr[i] && seen[need] == 1)
		{
			printf ("1\n");
			return 0;
		}
	}
	printf ("0\n");
}
