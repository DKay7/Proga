#include <stdio.h>


int main ()
{      
    const int m = 100;
    char buffer[m];
    char next_chr;
    int i = 0, j = 0, len;
    int counter = 0;
    int words = 0;

    scanf("%c", &next_chr);

    while (next_chr != '\n' && i < m)
    {
        buffer[i] = next_chr; 
        scanf("%c", &next_chr);
        i += 1;
    }

    len = i;

    for (i = 0; i < len; i++)
    {
        if(buffer[i] != ' ')
        {
            for (j=i+1; buffer[j] != ' '; j++)
            {
                if (buffer[i] == buffer[j] /*&& j != i*/)
                {
                    counter += 1;
                }
            }
        }

        else 
        {
            if (counter == 0)
            {
                words += 1;
            }

            counter = 0;
        }
        
    }

    printf("%d\n", words);
    return 0;
}
