#include <stdio.h>

int main()
{
    int data_segments[10][4], checksum[4], sum[4] = {0}, carry = 0, n_data, i, j;

    printf("Receiver Side - Checksum Verification\n");

    // Input the number of 4-bit segments for the received data
    printf("Enter the number of 4-bit segments for the received data: ");
    scanf("%d", &n_data);

    // Input received data segments (each segment is 4 bits, MSB first)
    for (i = 0; i < n_data; i++)
    {
        printf("Enter the received data segment %d (4 bits one after another): ", i + 1);
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &data_segments[i][j]);
        }
    }

    // Input received checksum (4 bits, MSB first)
    printf("Enter the received checksum (4 bits one after another): ");
    for (j = 0; j < 4; j++)
    {
        scanf("%d", &checksum[j]);
    }

    // Perform checksum addition for each 4-bit segment with the received checksum
    for (i = 0; i < n_data; i++)
    {
        carry = 0;
        for (j = 3; j >= 0; j--) // Start from LSB for addition
        {
            int temp_sum = sum[j] + data_segments[i][j] + carry;
            sum[j] = temp_sum % 2; // Update the sum bit
            carry = temp_sum / 2;  // Carry for the next higher bit
        }

        // Wrap around any remaining carry by adding it to the LSB
        if (carry == 1)
        {
            for (j = 3; j >= 0 && carry == 1; j--)
            {
                int temp_sum = sum[j] + carry;
                sum[j] = temp_sum % 2;
                carry = temp_sum / 2;
            }
        }
    }

    // Add the checksum to the computed sum
    carry = 0;
    for (j = 3; j >= 0; j--) // Start from LSB for addition
    {
        int temp_sum = sum[j] + checksum[j] + carry;
        sum[j] = temp_sum % 2; // Update the sum bit
        carry = temp_sum / 2;  // Carry for the next higher bit
    }

    // Wrap around any remaining carry by adding it to the LSB
    if (carry == 1)
    {
        for (j = 3; j >= 0 && carry == 1; j--)
        {
            int temp_sum = sum[j] + carry;
            sum[j] = temp_sum % 2;
            carry = temp_sum / 2;
        }
    }

    // Perform inversion (one's complement) to check for errors
    int error_detected = 0;
    printf("Final checksum (inverted): ");
    for (j = 0; j < 4; j++)
    {
        int inverted_bit = (sum[j] == 1) ? 0 : 1; // Invert each bit
        printf("%d", inverted_bit);
        if (inverted_bit != 0) // If any bit is not 0, error is detected
        {
            error_detected = 1;
        }
    }
    printf("\n");

    if (error_detected)
    {
        printf("Checksum FAILED: Received data is Corrupted.\n");
    }
    else
    {
        printf("Checksum PASSED: Received data is Correct.\n");
    }

    return 0;
}