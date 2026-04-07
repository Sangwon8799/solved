#include <iostream>
#include <cmath>

#define MAX_SIZE 3
#define MAX_DIST 100000.0

struct point
{
	int x;
	int y;
};

bool is_collinear (struct point[MAX_SIZE]);
double get_dist (struct point *, struct point *);

static inline int
get_index (int i)
{
	return i >= MAX_SIZE ? (i - MAX_SIZE) : i;
}

int
main ()
{
	struct point pos[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
		scanf ("%d %d", &pos[i].x, &pos[i].y);

	if (!is_collinear (pos))
	{
		double max = 0.0;
		double min = MAX_DIST;

		for (int i = 0; i < MAX_SIZE; i++)
		{
			double sum = get_dist (&pos[i], &pos[get_index (i + 1)]) +
									 get_dist (&pos[i], &pos[get_index (i + 2)]);

			max = sum > max ? sum : max;
			min = sum < min ? sum : min;
		}

		printf ("%.16lf\n", 2.0 * (max - min));
	}
	else
		printf ("%.1lf\n", -1.0);
}

bool
is_collinear (struct point pos[MAX_SIZE])
{
	struct point v_a = {pos[0].x - pos[1].x, pos[0].y - pos[1].y};
	struct point v_b = {pos[0].x - pos[2].x, pos[0].y - pos[2].y};
	long long cross = (v_a.x * v_b.y) - (v_a.y * v_b.x);

	return cross == 0;
}

double
get_dist (struct point *a, struct point *b)
{
	return sqrt (pow (a->x - b->x, 2) + pow (a->y - b->y, 2));
}
