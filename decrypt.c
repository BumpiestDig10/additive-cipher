#include<stdio.h>
#include <string.h>
#include<ctype.h>

void decrypt(int key, char text[]);

char text_encrypted[100], text_decrypted[100]; // to store maximum of 100 characters

void main()
{
    int key;
    printf("Type the Encrypted text to decrypt: "); // prompting user to input the text to be decrypted
    fgets(text_encrypted, sizeof(text_encrypted), stdin); // fgets() stores the input in text_encrypted

    printf("Enter the key: "); // prompting user to input the key
    scanf("%d", &key);

    decrypt(26-key, text_encrypted); // calling decrypt function

    printf("\nEncrypted Text : %s", text_encrypted); // printing encrypted text
    printf("Decrypted Text : %s", text_decrypted); // printing decrypted text
}

void decrypt(int key, char text[])
{
    int length, i;

    length = strlen(text); // calculating length of the string

    if (key>26)
    key = key % 26; // keeping the value of key between 0 - 25

    for (i = 0; i < length; i++)
    {
        if(isupper(text[i])) // checking if an alphabet is upper case
        text_decrypted[i] = ((text[i] - 'A' + key) % 26) + 'A'; // shifting the characters

        else if(islower(text[i])) // checking if an alphabet is lower case
        text_decrypted[i] = ((text[i] - 'a' + key) % 26) + 'a'; // shifting the characters

        else
        text_decrypted[i] = text[i]; // if a charecter and not an alphabet, do nothing
    }

}