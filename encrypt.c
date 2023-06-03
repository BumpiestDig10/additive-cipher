#include<stdio.h>
#include<ctype.h>
#include<string.h>

void encrypt(int key, char text_plain[]);

char text_plain[100], text_encrypt[100]; // to store maximum of 100 characters

void main()
{
    int key;
    printf("Type the plain text to encrypt: "); // prompting user to input the text to be Encrypted
    fgets(text_plain, sizeof(text_plain), stdin); // fgets() stores the input in text_plain

    printf("Enter the key: ");  // prompting user to input the key
    scanf("%d", &key);

    encrypt(key, text_plain); // calling encrypt function

    printf("\nPlain Text: %s", text_plain); // printing plain text
    printf("Encrypted Text: %s", text_encrypt); // printing encrypted text
}

void encrypt(int key, char text[])
{
    int length, i;

    length = strlen(text); // calculating length of the string

    if (key>26)
    key = key % 26; // keeping the value of key between 0 - 25

    for (i = 0; i < length; i++)
    {
        if(isupper(text[i])) // checking if an alphabet is upper case
        text_encrypt[i] = ((text[i] - 'A' + key) % 26) + 'A'; // shifting the characters

        else if(islower(text[i])) // checking if an alphabet is lower case
        text_encrypt[i] = ((text[i] - 'a' + key) % 26) + 'a'; // shifting the characters

        else
        text_encrypt[i] = text[i]; // if a charecter and not an alphabet, do nothing
    }

}