#include "bfs.h"

int main(int argc, char* argv[])
{   
    if (argc != 5)
    {
        printf ("Incorrect arguments\n");
        return 0;
    }

    BFSUnitTest(atoi(argv[1]), argv[2], argv[3], argv[4]);
}