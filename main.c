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

    return (0);
}
