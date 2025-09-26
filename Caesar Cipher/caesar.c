#include "cs50.h" // For get_int and string
#include <stdio.h>
#include <string.h> // For strlen

int main(int argc, string argv[]) // Changed to use string for argv
{
    // The argc == 1 condition means no command-line argument was provided
    if (argc == 1)
    {
        // 1. Get the key from the user
        int key = get_int("Key: ");

        if (key > 0)
        {
            key = key % 26;

            // 2. Get the plaintext string from the user using CS50's get_string
            string plain = get_string("Plaintext: ");

            // 3. Declare the cipher string
            // It needs to be the length of the plaintext + 1 for the null terminator (\0)
            char cipher[strlen(plain) + 1];
            for (int i = 0; i < strlen(plain); i++)
            {

                if (plain[i] > 64 && plain[i] < 91)
                {
                    if(plain[i] + key > 90){
                    plain[i] = ((plain[i] + key)%90) + 64;
                    cipher[i] = plain[i];
                    }else {
                        plain[i] = plain[i] + key;
                        cipher[i] = plain[i];
                    }
                }

                else if (plain[i] > 96 && plain[i] < 123)
                {
                    if(plain[i] + key > 122){
                    plain[i] = ((plain[i] + key)%122)+96;
                    cipher[i] = plain[i];
                    }else {
                        plain[i] = plain[i] + key;
                        cipher[i] = plain[i];
                    }
                }else {
                    cipher[i] = plain[i];
                }

            }
            cipher[strlen(plain)] = '\0';
            printf("ciphertext: %s\n", cipher);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Error Arguments \n");
        return 1;
    }
}
