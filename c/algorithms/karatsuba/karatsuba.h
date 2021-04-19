#include <assert.h>
#include <malloc.h>

#define and &&
#define or ||

typedef int coeff_type;
typedef int len_type;

typedef struct Poly{
    coeff_type *coeffs;
    len_type len;
} Poly;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


Poly* ctor(len_type);                       // Creates new polynomial
void fill(Poly*, coeff_type*);             // Fill passed polynomial with passed values
Poly* sum(Poly*, Poly*);                    // Finds the sum of the two passed polynomials
Poly* substract(Poly*, Poly*);              // Finds the difference of the two passed polynomials
Poly* karatsuba(Poly*, Poly*);              // Finds the multiplication of the two passed polynomials
Poly* get_halves(Poly*);                    // Findes two halves of the passed polynomial
len_type shortest(Poly*, Poly*);            // Findes the shortest of the passed polynomials


