#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i_array[10] = {260, 259, 258, 257, 256, 255, 254, 253, 252, 251};
    unsigned char uc_array[10];

	//TODO: write a program, which copies the values from the given array to an unsigned char array
    //print out the elements of the unsigned char array, with the "%d" format specifier
    //what do you see?

    //can copy values as characters

    memcpy(uc_array, i_array, strlen(i_array)+1);
    int i = 0;
    while (i < 10) {
        printf("%d\n", i_array[i]);
        i++;
    }


    return 0;
}
