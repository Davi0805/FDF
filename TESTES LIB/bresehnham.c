#include <stdio.h>

typedef struct s_coord
{
	int x;
	int	y;
	int z;
}				t_coord;

typedef struct s_decis
{
	int	decis1;
	int	decis2;
}				t_decis;

void appendpoint(t_coord point, t_coord points[100], int* points_index)
{
    points[*points_index] = point;
    (*points_index)++;
}

t_coord	*bresenhamn(t_coord source, t_coord destination, t_coord points[100], int* points_index)
{
	t_coord d;
	t_coord step;
	t_coord current;
	t_decis decis;


	d.x = ((destination.x) -  (source.x));
	d.y = ((destination.y) -  (source.y));
	d.z = ((destination.z) -  (source.z));

	if (destination.x >= source.x)
		step.x = 1;
	else
		step.x = -1;
	if (destination.y >= source.y)
		step.y = 1;
	else
		step.y = -1;
	if (destination.z >= source.z)
		step.z = 1;
	else
		step.z = -1;

	if (destination.x >= destination.y && destination.x >= destination.z)
	{
		decis.decis1 = (2 * destination.y - destination.x);
		decis.decis2 = (2 * destination.z - destination.x);
	}
	else if (destination.y >= destination.x && destination.y >= destination.z)
	{
		decis.decis1 = (2 * destination.x - destination.y);
		decis.decis2 = (2 * destination.z - destination.y);
	}
	else
	{
		decis.decis1 = (2 * destination.y - destination.z);
		decis.decis2 = (2 * destination.x - destination.z);
	}
    current = source;

    appendpoint(current, points, points_index);

	if (destination.x >= destination.y && destination.x >= destination.z)
	{
		while (current.x != destination.x)
		{
			if (decis.decis1 >= 0)
			{
				current.y += step.y;
				decis.decis1 -= 2 * destination.x;
			}
			if (decis.decis2 >= 0)
			{
				current.z += step.z;
				decis.decis2 -= 2 * destination.x;
			}
			decis.decis1 += 2 * destination.y;
			decis.decis2 += 2 * destination.z;
			current.x += step.x;
			appendpoint(current, points, points_index);
		}
	}
	else if (destination.y >= destination.z && destination.y >= destination.z)
	{
		while (current.y != destination.y)
		{
			if (decis.decis1 >= 0)
			{
				current.x += step.x;
				decis.decis1 -= 2 * destination.y;
			}
			if (decis.decis2 >= 0)
			{
				current.z += step.z;
				decis.decis2 -= 2 * destination.y;
			}
			decis.decis1 += 2 * destination.x;
			decis.decis2 += 2 * destination.z;
			current.y += step.y;
			appendpoint(current, points, points_index);
		}
	}
	else
	{
		while (current.z != destination.z)
		{
			if (decis.decis1 >= 0)
			{
				current.y += step.y;
				decis.decis1 -= 2 * destination.z;
			}
			if (decis.decis2 >= 0)
			{
				current.x += step.x;
				decis.decis2 -= 2 * destination.z;
			}
			decis.decis1 += 2 * destination.y;
			decis.decis2 += 2 * destination.x;
			current.z += step.z;
			appendpoint(current, points, points_index);
		}
	}

	appendpoint(current, points, points_index);

	return points;
}

int main(void)
{
    t_coord inicio;
    t_coord fim;

    inicio.x = 2;
    inicio.y = 2;
    inicio.z = 2;

    fim.x = 10;
    fim.y = 5;
    fim.z = 7;

    int points_index = 0;
    t_coord points[100];

    bresenhamn(inicio, fim, points, &points_index);

    for (int i = 0; i < points_index; i++) {
        printf("(%d, %d, %d)\n", points[i].x, points[i].y, points[i].z);
    }

    return 0;
}
