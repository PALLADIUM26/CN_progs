#include <stdio.h>
int main()
{
    int m1[20], rem1[10], d[10], i, j, k, len, divlen;

    printf("\nAt the receiver end\n");

    // Input divisor
    printf("\nEnter the length of divisor:\n");
    scanf("%d", &divlen);
    printf("\nEnter the divisor:\n");
    for (i = 0; i < divlen; i++)
    {
        scanf("%d", &d[i]);
    }

    // Input received data (includes CRC)
    printf("\nEnter the length of received data:\n");
    scanf("%d", &len);
    printf("\nEnter the encoded data:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &m1[i]);
    }

    // Display the encoded data
    printf("\nEncoded data (received data + CRC): ");
    for (i = 0; i < len; i++)
    {
        printf("%d", m1[i]);
    }
    printf("\n");

    // Perform XOR operation (Division step) to check for errors
    for (i = 0; i < len - (divlen - 1); i++)
    {
        if (m1[i] == 1)
        { // If the current bit is 1, start XOR operation
            for (j = 0; j < divlen; j++)
            {
                if (m1[i + j] == d[j])
                {
                    rem1[j] = 0; // XORing 1 with 1 or 0 with 0 gives 0
                }
                else
                {
                    rem1[j] = 1; // XORing 1 with 0 or 0 with 1 gives 1
                }
            }
            // Update the data with the result of XOR
            for (k = 0; k < divlen; k++)
            {
                m1[i + k] = rem1[k];
            }
        }
        else
        { // If the current bit is 0, just copy the value
            for (k = 0; k < divlen; k++)
            {
                rem1[k] = m1[i + k];
            }
        }
    }

    // Print the remainder (CRC result)
    printf("\nCRC = ");
    j = 0;
    for (i = 1; i < divlen; i++)
    { // Start from 1 to ignore the first bit (since it's always 0)
        printf("%d", rem1[i]);
        j += rem1[i]; // Sum the bits to check for errors
    }

    // If the sum of the bits in the remainder is 0, then no error was detected
    if (j == 0)
    {
        printf("\nThere is no error\n");
    }
    else
    {
        printf("\nThere is an error\n");
    }

    return 0;
}
