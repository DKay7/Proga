#include <stdio.h>
#include <math.h>


/*
-----------------------------------------------------------------------------
This program is a counter of solutions of equation
a^2 + b^2 = n type for a and b.

The program main goal is it's working
time is rea-a-a-lly smal. It can solve 
under 1000 tests in less than 0.25 sec.
(This time was didcated by problem's requiriments)
-----------------------------------------------------------------------------
*/


void zero_massive(int* a, int size);	// Turns all massive elements to zero

void print_massive(int* a, int size);	//Prints massive

//-----------------------------------------------------------------------------

int main() {
	const int max_tests = 1000;
	int tests = 0;
	int n = 0, solutions = 0;
	int results[max_tests];
	double a = 0, b = 0, square_root = 0;
	double last_a = 0, last_b = 0;

	//Input the massive and turns 
	//all it's elements to 0
	scanf("%d", &tests);
	zero_massive(results, tests);


	for (int test = 0; test < tests; test++) {
		
		
		/*
		-----------------------------------------------------------------------------
		Since the equation is actually a circle and we consider only the I-th quarter 
		of the Cartesian plane and look for intersections of the quarter of the circle 
		with integers a and b then all such solutions will be symmetric with respect 
		to the radius of the vector deposited at an angle of 45 degrees. Therefore, it 
		is enough to pass only half a quarter of a circle (an arc of 45 degrees), and 
		then, if there is a solution a=b=r=n*sqrt(2), multiply the number of 
		solutions by 2, and then subtract 1, to not to repeat twice the solution 
		a=b=r=n*sqrt(2), if there is no solution a=b=r=n*sqrt(2), then simply multiply 
		the number of found solutions by 2.
		-----------------------------------------------------------------------------
		*/
		
		solutions = 0;
		last_a = 0;
		last_b = 0;


		scanf("%d", &n);

		square_root = sqrt(n / 2.0);

		for (a = 1; a <= square_root; a++) {
			b = sqrt(n - a * a);

			if (b == (int)b && a > 0 && b > 0) {
				last_a = a;
				last_b = b;
				solutions += 1;
			}

		}

		if (last_a == last_b && last_a == square_root) {
			results[test] = 2 * solutions - 1;
		}
		else
			results[test] = 2 * solutions;
	}


	print_massive(results, tests);

	return 0;
}

void zero_massive(int* a, int size) {
	for (int i = 0; i < size; i++)
		* (a + i) = 0;
}

void print_massive(int* a, int size) {
	for (int i = 0; i < size; i++)
		printf("%d\n", *(a + i));
}
