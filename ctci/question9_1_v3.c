/*
9.1
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or
3 steps at a time. Implement a method to count how many possible ways the child
can run up the stairs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 36

int totalways(int n, int *count) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	else if (count[n] != 0) {
		return count[n];
	}
	else {
		count[n] = totalways(n-1,count) + totalways(n-2,count) + totalways(n-3,count);
		return count[n];
	}
}

int main(int argc, char *argv[]) {
	int count[N+1] = {0};
	printf("Total Number of ways to climb %d steps: %d\n",N,totalways(N,count));
	return 0;
}
