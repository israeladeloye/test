#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int key;
    // For verifying the command-line argument
    if (argc == 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // convert the second command-line argument to an integer

        key = atoi(argv[1]);
        if (key < 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get the plain text
    string plain = get_string("plaintext: ");

    // Start printing the cipher text
    printf("ciphertext: ");

    // Loop and check each character
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        // Solution if it is in lowercase
        if (islower(plain[i]))
        {
            int l = ((int)plain[i] - 97 + key) % 26;
            printf("%c", l + 97);
        }
        else if (isupper(plain[i])) // Solution if it is in uppercase
        {
            int u = ((int)plain[i] - 65 + key) % 26;
            printf("%c", u + 65);
        }
        else // If it is none of the above then just prin the character
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0; // Exit the program

}
