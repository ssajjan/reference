/*
5.7
An array A contains all the integers from 0 through n, except for one number which is
missing. In this problem, we cannot access an entire integer in A with a single opera-
tion. The elements of A are represented in binary, and the only operation we can use
to access them is "fetch thejth bit ofAfi]," which takes constant time. Write code to
find the missing integer. Can you do it in 0(n) time?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void printBits(unsigned int num) {
        if (num == 0) {
                printf("Bit pattern is: ");
        }
        else {
                printBits(num/2);
                printf("%d",num%2);
        }
}

int count1s(unsigned int num) {
	int c1 = 0;
	unsigned int c = num;

	while (c != 0) {
		if ( c & 1 == 1) {
			c1++;
		}
		c = c >> 1;
	}
	return c1;
}

bool getjBit(unsigned int num, int bit) {
	return ((num & (1<<bit)) != 0);
}

int main(int argc, char *argv[]) {
	/*
	printf("Argument count: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Argument vector values:%s at %p memory\n", argv[i], argv[i]);
		for (char *j=argv[i]; *j!='\0'; j++) {
			printf("Another way to print argument vector values: "
                               "%c at %p memory\n", *j, j);
		}
	}
	*/

	int n = 16, miss = 0, count = 0;
	unsigned int A[n];
	int index = 0, bitindex;
	unsigned int total = n*(n+1)/2, num = 0, sum = 0;

	while (index < n) {
		if (count != miss) {
			A[index] = count;
			index++;
		}
		count++;
	}

	index = 0;
	while (index < n) {
		bitindex = 0;
		while (bitindex <= log2(n)) {
			sum = sum + getjBit(A[index],bitindex)*(pow(2,bitindex));
			bitindex++;
		}
		index++;
	}

	num = total-sum;
	printf("Sum: %u\n",sum);
	printf("Total: %u\n",total);
	printf("Num missing: %u\n",num);
	printf("Algorithm complexity: O(nlogn)\n");

	return 0;
}
