#include <stdio.h> 
#include <string.h> 
#define size 1000

int main() 
{ 
    int counter = 0, res = 0; 
    char array[size];
    int i = 0;
    int len;
    int last_sym = 0;

    printf("Enter the string: "); 

    while((array[i] = getchar()) != EOF)
    {
        i += 1;
    }
    
    len = i - 1;
    printf("\n\n");
    for (i = 0; i<len; i++)
        printf("%c", array[i]);
        
    

    for (int i = 0; array[i] != EOF; i++) 
    {  

        if (array[i] != ' ' && array[i] != '\n') 
        {   
            last_sym = 1;

            for (int j = i;  j < len && array[j] != '\n' && array[j] != ' '; j++) 
            { 
                if (array[i] == array[j] && i != j) counter++; 
            }
        }

        if (last_sym != 0 && (array[i] == ' ' || array[i] == EOF || array[i] == '\n'))
        {   
            last_sym = 0;
            if (counter == 0) res++; 
            counter = 0; 
        }
    }

    printf("\n%d\n", res); 
    return 0; 
}