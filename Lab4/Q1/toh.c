
    #include <stdio.h>
    void toh(int num, char frompeg, char topeg, char auxpeg)

    {
        if (num == 1)

        {
            printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
            return;
        }
        toh(num - 1, frompeg, auxpeg, topeg);
        printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
        toh(num - 1, auxpeg, topeg, frompeg);

    }   
    int main()

    {   int n=6;
        printf("Moves:\n");
        toh(6, 'A', 'C', 'B');
        return 0;

    }

    