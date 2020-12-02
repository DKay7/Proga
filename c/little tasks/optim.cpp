#include <stdio.h>
#include <math.h>
#define DeBug ptintf
/*
-----------------------------------------------------------------------------
This program finds solution for this task:

Task 1G. About sprite [0.5 sec, 256 mb]
8b class decided to take a lot of Sprite for the rally. To do this, they gathered to construct
create a portable refrigerator a x b x C that will hold exactly n cubic cans
A 1 × 1 × 1 sprite To get the lemonade as cold as possible, they want
minimize heat loss; that is, minimize the surface area.
For example, if the refrigerator capacity should be 12, the following options are possible
options:
3 2 2 - > 32
4 3 1 -> 38
6 2 1 - 40
12 1 1 50
In this example, the refrigerator 322 is optimal.
Help 8b find the optimal refrigerator in the General case.

//-----------------------------------------------------------------------------
Firlstly, we find the first divider of n wich should be smaller or equals to n^(1/3).
Then, we divides n by found divider and find the second divider but now for (n/div_1),
it should be smaller or equals to (n/div_1)^(1/2). Then we find the third divider by
dividind n by first two ones.
-----------------------------------------------------------------------------
*/

int main() {
int n=1,
    dividers[3] = {1, 1, 1},
    min = 1e6, idx_min = 0,
    max = 0, idx_max = 0;

scanf("%d", &n);


for(int i = ceil(pow(n, 1.0 / 3)); i > 1; i--)
    if(n % i == 0 && i > dividers[0])
        dividers[0] = i;

for(int i = ceil(pow(n / dividers[0], 1.0 / 2)); i > 1; i--)
    if((n / dividers[0]) % i == 0 && i > dividers[1])
        dividers[1] = i;


dividers[2] = n / (dividers[0] * dividers[1]);


for(int i=0; i<3; i++){
    if(dividers[i] < min){
        min = dividers[i];
        idx_min = i;
    }

    if(dividers[i] >= max){
        max = dividers[i];
        idx_max = i;
    }
}

printf("\n%d %d %d",  min, dividers[3 - idx_max - idx_min], max);
printf("\n%d %d %d", dividers[0], dividers[1], dividers[2]);
return 0;
}