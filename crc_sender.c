#include <stdio.h>
int main()
{
    int m[20], p[20], d[10], i, j, k, len, rem[10], divlen;

    printf("\nAt the sender end\n");

    // Input divisor
    printf("\n Enter the length of divisor:\n");
    scanf("%d", &divlen);
    printf("\n Enter the divisor:\n");
    for (i = 0; i < divlen; i++)
    {
        scanf("%d", &d[i]);
    }

    // Input data
    printf("\n Enter the length of data:\n");
    scanf("%d", &len);
    printf("\n Enter the data:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &m[i]);
        p[i] = m[i]; // Copy data to a separate array
    }

    // Append zeros to the data
    for (i = len; i < len + (divlen - 1); i++)
    {
        m[i] = 0;
    }

    printf("\n The appended value is: ");
    for (i = 0; i < len + (divlen - 1); i++)
    {
        printf("%d", m[i]);
    }

    // XOR operation (Division step) to calculate the remainder (CRC)
    for (i = 0; i < len; i++)
    {
        if (m[i] == 1)
        { // If the current bit is 1, start XOR operation
            for (j = 0; j < divlen; j++)
            {
                if (m[i + j] == d[j])
                {
                    rem[j] = 0; // XORing 1 with 1 or 0 with 0 gives 0
                }
                else
                {
                    rem[j] = 1; // XORing 1 with 0 or 0 with 1 gives 1
                }
            }
            // Update the data with the result of XOR
            for (k = 0; k < divlen; k++)
            {
                m[i + k] = rem[k];
            }
        }
        else
        { // If the current bit is 0, just copy the value
            for (k = 0; k < divlen; k++)
            {
                rem[k] = m[i + k];
            }
        }
    }

    printf("\n CRC = ");
    for (i = 1; i < divlen; i++)
    { // Start from 1 to ignore the first bit (since it's always 0)
        printf("%d", rem[i]);
    }

    printf("\n The complete data + CRC (sent to receiver): ");
    for (i = 0; i < len; i++)
    {
        printf("%d", p[i]);
    }
    for (i = 0; i < divlen - 1; i++)
    { // Append CRC to the sent data
        printf("%d", rem[i]);
    }

    return 0;
}
