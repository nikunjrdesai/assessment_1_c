#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void concatenateStrings(char str1[], char str2[])
{
    strcat(str1, str2);
}

int isPalindrome(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

void copyString(char source[], char destination[])
{
    strcpy(destination, source);
}

int stringLength(char str[])
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

int countCharacterFrequency(char str[], char ch)
{
    int length = strlen(str);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }

    return count;
}

void countVowelsConsonants(char str[], int *vowels, int *consonants)
{
    int length = strlen(str);
    *vowels = 0;
    *consonants = 0;

    for (int i = 0; i < length; i++)
    {
        char ch = tolower(str[i]);

        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                (*vowels)++;
            }
            else
            {
                (*consonants)++;
            }
        }
    }
}

void countBlankSpacesDigits(char str[], int *blanks, int *digits)
{
    int length = strlen(str);
    *blanks = 0;
    *digits = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            (*blanks)++;
        }
        else if (isdigit(str[i]))
        {
            (*digits)++;
        }
    }
}

int main()
{
    char str[100];
    char choice;
    int vowels, consonants, blanks, digits;

    do
    {
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);

        // Remove newline character from fgets
        str[strcspn(str, "\n")] = '\0';

        printf("\nString Operations:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenation\n");
        printf("3. Palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of character in a string\n");
        printf("7. Find number of vowels and consonants\n");
        printf("8. Find number of blank spaces and digits\n");

        printf("\nEnter your choice (1-8): ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            reverseString(str);
            printf("Reversed string: %s\n", str);
            break;

        case '2':
            printf("Enter another string to concatenate: ");
            char str2[100];
            getchar(); // Consume the newline character from previous input
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            concatenateStrings(str, str2);
            printf("Concatenated string: %s\n", str);
            break;

        case '3':
            if (isPalindrome(str))
            {
                printf("The string is a palindrome.\n");
            }
            else
            {
                printf("The string is not a palindrome.\n");
            }
            break;

        case '4':
            printf("Copying the string...\n");
            char copy[100];
            copyString(str, copy);
            printf("Copied string: %s\n", copy);
            break;

        case '5':
            printf("Length of the string: %d\n", stringLength(str));
            break;

        case '6':

            printf("Enter a character to find its frequency: ");
            char ch;
            scanf("%c", &ch);
            int frequency = countCharacterFrequency(str, ch);
            printf("Frequency of '%c': %d\n", ch, frequency);
            break;

        case '7':
            countVowelsConsonants(str, &vowels, &consonants);
            printf("Number of vowels: %d\n", vowels);
            printf("Number of consonants: %d\n", consonants);
            break;

        case '8':
            countBlankSpacesDigits(str, &blanks, &digits);
            printf("Number of blank spaces: %d\n", blanks);
            printf("Number of digits: %d\n", digits);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

        getchar(); // Consume the newline character

        printf("\nDo you want to continue? (Y/N): ");
        char continueChoice;
        scanf(" %c", &continueChoice);

        if (continueChoice == 'N' || continueChoice == 'n')
        {
            break;
        }

        getchar();

        printf("\n");
    } while (1);

    return 0;
}