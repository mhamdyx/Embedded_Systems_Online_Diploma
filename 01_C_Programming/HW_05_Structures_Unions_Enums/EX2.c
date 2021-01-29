/*
 * EX2.c
 *
 *  Created on: Jan 29, 2021
 *      Author: MahmoudH
 */

/* Libraries */
#include <stdio.h>

/* Declarations */
struct distance_s
{
	int feet;
	float inches;
};

/* Function Prototypes */
struct distance_s read_distance(char dist_number[]);

struct distance_s add_distances(struct distance_s d1, struct distance_s d2);

/* Main Program */
int main(void)
{
	struct distance_s dist1, dist2, result;

	dist1 = read_distance("1st");
	dist2 = read_distance("2nd");
	result = add_distances(dist1, dist2);

	printf("\nSum of distances=%d\'-%.1f\"\n", result.feet, result.inches);

	return 0;
}

/* Function Definitions */
struct distance_s read_distance(char dist_number[])
{
	struct distance_s distance;

	printf("\nEnter information for %s distance\n", dist_number);
	
    printf("Enter feet: ");
	scanf("%d", &distance.feet);

	printf("Enter inches: ");
	scanf("%f", &distance.inches);

	return distance;
}


struct distance_s add_distances(struct distance_s d1, struct distance_s d2)
{
	struct distance_s result;

	result.feet = d1.feet + d2.feet;
	result.inches = d1.inches + d2.inches;

	while(result.inches > 12)
	{
		result.inches -= 12;
		result.feet += 1;
	}

	return result;
}
