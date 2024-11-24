#include <stdio.h>

void main()
{
    int a[10], b[10], sum[10], checksum[10], carry = 0, n, i, p;

    printf("Sender Side - Checksum Generation\n");
    printf("Enter the number of bits for each segment: ");
    scanf("%d", &n);

    // Input first segment
    printf("Enter the first segment (%d bits one after another): ", n);
    for (i = n - 1; i >= 0; i--)
    {
        scanf("%d", &a[i]);
    }

    // Input second segment
    printf("Enter the second segment (%d bits one after another): ", n);
    for (i = n - 1; i >= 0; i--)
    {
        scanf("%d", &b[i]);
    }

    // Calculate the sum with carry
    for (i = 0; i < n; i++)
    {
        sum[i] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry) / 2;
    }

    // Print the sum
    printf("Sum: ");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
    printf("\n");

    // If there's carry left, wrap it around
    if (carry == 1)
    {
        for (i = 0; i < n; i++)
        {
            p = (sum[i] + carry) % 2;
            carry = (sum[i] + carry) / 2;
            sum[i] = p;
        }

        // Print the wrapped sum
        printf("Wrapped Sum: ");
        for (i = n - 1; i >= 0; i--)
        {
            printf("%d", sum[i]);
        }
        printf("\n");
    }

    // Generate checksum by inverting sum bits
    printf("Generated Checksum: ");
    for (i = n - 1; i >= 0; i--)
    {
        checksum[i] = (sum[i] == 1) ? 0 : 1;
        printf("%d", checksum[i]);
    }
    printf("\n");
}