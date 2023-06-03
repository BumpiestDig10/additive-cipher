#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

void Read();
void Input(int key, char password[], char username[]);
void encryptUser(int key, char text_plain[]);
void encryptPass(int key, char text_plain[]);

char pass[100], user[100], text_plain[100], text_user[100], text_pass[100];  //Global Variables
int key = 7;    //So that Everything in file has common encryption

int main()
{
    //printf("Enter encryption key: ");
    //scanf("%d", &key);

    printf("Enter username: ");
    fgets(user, sizeof(user), stdin);   //Inputs Username

    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);   //Inputs Password

    Input(key, pass, user);  //calls function Input()

    char option;

    printf("Do you wish to read all entries?(y/n): ");
    scanf("%c", &option);   //To check whether to show all entries or not

    if(option == 'y' || option == 'Y')
    {
        Read(); //Show all entries
        printf("\n");
    }
    else if(option == 'n' || option == 'N')
    {
        return 0;   //End program
    }
    else
    {
        printf("Invalid Input!\n");
    }

    return 0;
}

void Read()
{
    FILE * fp;
    char read;

    fp = fopen("password_username.txt", "r");   //Opens (or) creates password_username.txt and reads the file

    if(fp == NULL)
    {
        printf("Error!\n");
        exit(1);
    }

    while((read = getc(fp)) != EOF) //read each character until End Of File (EOF)
    {
        printf("%c", read); //Print each read character
    }

    fclose(fp); //Closes the open file
}

void Input(int key, char password[], char username[])
{
    FILE * ptr;

    ptr = fopen("password_username.txt", "a+"); //Opens (or) creates password_username.txt and continues writing from its last line.

    if(ptr == NULL)
    {
        printf("Error!\n");
        exit(1);
    }

    fprintf(ptr, "\n");
    
    fprintf(ptr, "Username: ");
    encryptUser(key, username); //Run encryption
    fprintf(ptr, "%s", text_user);   //Prints Username in the opened file

    fprintf(ptr, "Password: ");
    encryptPass(key, password); //Run encryption
    fprintf(ptr, "%s", text_pass);   //Prints Password in the opened file

    fclose(ptr);    //Closes the open file
}

void encryptUser(int key, char text[])  //To Encrypt Username
{
    int length = 0, i;

    length = strlen(text); // calculating length of the string

    if (key>26)
    key = key % 26; // keeping the value of key between 0 - 25

    for (i = 0; i < length; i++)
    {
        if(isupper(text[i])) // checking if an alphabet is upper case
        text_user[i] = ((text[i] - 'A' + key) % 26) + 'A'; // shifting the characters

        else if(islower(text[i])) // checking if an alphabet is lower case
        text_user[i] = ((text[i] - 'a' + key) % 26) + 'a'; // shifting the characters

        else
        text_user[i] = text[i]; // if a charecter and not an alphabet, do nothing
    }
}

void encryptPass(int key, char text[])  //To Encrypt Password
{
    int length = 0, i;

    length = strlen(text); // calculating length of the string

    if (key>26)
    key = key % 26; // keeping the value of key between 0 - 25

    for (i = 0; i < length; i++)
    {
        if(isupper(text[i])) // checking if an alphabet is upper case
        text_pass[i] = ((text[i] - 'A' + key) % 26) + 'A'; // shifting the characters

        else if(islower(text[i])) // checking if an alphabet is lower case
        text_pass[i] = ((text[i] - 'a' + key) % 26) + 'a'; // shifting the characters

        else
        text_pass[i] = text[i]; // if a charecter and not an alphabet, do nothing
    }
}

//Had to encrypt username and password because of an error:
//  If username's length was greater than password's length,
//      encryption of password kept the username's part after the end of password's encrytion.

//Using key of 7 for encryption.

//Decrypter not included in this code as there would be no point of encryption if string gets decrypted right after.

//This code is not a 100% right as the key is global and cannot be taken as input from the user.