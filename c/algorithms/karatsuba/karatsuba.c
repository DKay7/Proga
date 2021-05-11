#include "karatsuba.h"


Poly* ctor(len_type len)
{
    assert(len > 0);
    
    Poly *poly = (Poly*) calloc(1, sizeof(Poly));
    coeff_type* tmp_coeffs = (coeff_type*) calloc(len, sizeof(coeff_type));

    if(tmp_coeffs == NULL)
    {
        return NULL;
    }

    poly->len = len;
    poly->coeffs = tmp_coeffs;

    return poly;
}


void fill(Poly* p, coeff_type* values)
{   
    assert(p != NULL);
    assert(values != NULL);

    len_type values_len = sizeof(values) / sizeof(len_type);
    assert(values_len == p->coeffs);

    int i = 0;
    for(i; i < p->len; i++)
    {
        p->coeffs[i] = values[i];
    }
}


Poly* sum(Poly* p, Poly* q)
{   

    assert(p != NULL);
    assert(q != NULL);

    int i = 0;
    len_type shortest_len = shortest(p, q);
    
    for(i = 0; i < shortest_len; i++)
    {
        p->coeffs[i] += q->coeffs[i];
    }

    return p;
}


Poly* substract(Poly* p, Poly* q)
{   
    assert(p != NULL);
    assert(q != NULL);

    int i = 0;
    int shortest_len = shortest(p, q);

    for(i = 0; i < shortest_len; i++)
    {
        p->coeffs[i] -= q->coeffs[i];
    }

    return p;
}

Poly** get_halves(Poly* p)
{   
    assert(p != NULL);

    len_type first_half_len = (p->len / 2);
    len_type second_half_len = p->len - (p->len / 2);
    coeff_type first_half_values[first_half_len];
    coeff_type second_half_values[second_half_len];

    Poly* first_half = ctor(first_half_len);
    Poly* second_half = ctor(second_half_len);
    assert(first_half != NULL);
    assert(second_half != NULL);

    int i = 0;
    for(i; i < first_half_len; i++)
    {
        first_half_values[i] = p->coeffs[i];
    }

    int i = 0;
    for(i; i < second_half_len; i++)
    {
        second_half_values[i] = p->coeffs[i + first_half_len + 1];
    }

    fill(first_half, &first_half_values);
    fill(second_half, &second_half_values);

    Poly* result[2] = {first_half, second_half};
    return result;
}

Poly* unite(Poly* ac, Poly* ad_bc, Poly* bd, len_type p_len, len_type q_len)
{   
    assert(ac != NULL);
    assert(ad_bc != NULL);
    assert(bd != NULL);

    len_type new_ac_len = 
}

Poly* karatsuba(Poly* p, Poly* q)
{   
    // Take halfes a,b  = x
    // Take halfes c,d = y
    // Find n = a+b, m = c+d
    // Find nm, ac, bd
    // Find ad+bc = nm - ac - bd
    // Result base^k * ac + base^(k/2) * (ad + bc) + bd

    assert(p != NULL);
    assert(q != NULL);

    if(p->len < 2)
    {   
        int i = 0;
        len_type shortest_len = shortest(p, q);

        for(i; i < shortest_len; i++)
        {
            p->coeffs[0] *= q->coeffs[0];
        }

        return p;
    }

    Poly** halves_p = get_halves(p);
    Poly* a = halves_p[0];
    Poly* b = halves_p[1];

    Poly** halves_q = get_halves(q);
    Poly* c = halves_q[0];
    Poly* d = halves_q[1];

    Poly* n = sum(a, b);
    Poly* m = sum(c, d);

    Poly* nm = karatsuba(n, m);
    Poly* ac = karatsuba(a, c);
    Poly* bd = karatsuba(b, d);

    Poly* tmp = substract(nm, ac);
    Poly* ad_bc = substract(tmp, bd);

    Poly result = unite(ac, ad_bc, bd, p->len, q->len);


}