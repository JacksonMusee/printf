#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Character:[%c]\n", 'H');
    _printf("Character:[%c]\n", 'H');
    _printf("Character:[%c]\n", '\0');

    printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");

    printf("Length:[%d, %d]\n", len, len2);

    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);

    printf(NULL);
    _printf(NULL);

    printf("%");
    _printf("%");

    printf("%!\n");
    _printf("%!\n");

    printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("%s", "This sentence is retrieved from va_args!\n");

   len = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
   len2 = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');

   printf("Length:[%d, %d]\n", len, len2);

   printf("Negative:[%d]\n", -762534);
   _printf("Negative:[%d]\n", -762534);

   printf("Positive:[%d]\n", 762534);
   _printf("Positive:[%d]\n", 762534);

    return (0);
}
