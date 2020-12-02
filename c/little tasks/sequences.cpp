#include <stdio.h>
#include <math.h>


/*
-----------------------------------------------------------------------------

This program is a finder of all permutations for sequences from 1 to n.
All permutations finding and printing according to lexicographical order.
-----------------------------------------------------------------------------
*/

void fill_massive(int* a, int size); 	//Fills masive with int. digit fron 1 to n

void print_massive(int* a, int size);	//Prints massive

void swap(int* a, int index1, int index2);	//Swaps two elements in massive.

int next_set(int* a, int size);	//Generates next lexicographical set to sequence a.

//-----------------------------------------------------------------------------

int main() {
	const int max_n = 8;
	int seq[max_n];
	int n = 0;

	scanf_s("%d", &n);

	fill_massive(seq, n);
	print_massive(seq, n);

	
	while (next_set(seq, n)) {
		print_massive(seq, n);
	}


	return 0;
}

void fill_massive(int* a, int size) {

	for (int i = 0; i < size; i++)
		a[i] = i + 1;
}


void swap(int* a, int index1, int index2) {
	int temp = 0;
	temp = *(a + index1);
	*(a + index1) = *(a + index2);
	*(a + index2) = temp;
}


int next_set(int* a, int size) {

	int first = size - 2;
	int second = size - 1;

	/*for (first; first > -1; first--)
		if (!(a[first] >= a[first + 1]))	break;*/
	while (first != -1 && a[first] >= a[first + 1])
		first -= 1;

	if (first == -1)
		return 0;

	/*for (second; second >= 0; second--)
		if (!(a[second] <= a[first])) break;*/

	while (a[second] <= a[first])
		second -= 1;

	swap(a, first, second);
	printf("%d, %d\n", first, second);

	for (int left = first + 1, right = size - 1; left < right; left++, right--)
		swap(a, left, right);

	return 1;
}


void print_massive(int* a, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);

	printf("\n");
}
