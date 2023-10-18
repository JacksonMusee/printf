#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int closed_main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Character:[%c]\n", 'H');
    _printf("Character:[%c]\n", 'H');

    printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");

    printf("Length:[%d, %d]\n", len, len2);

    return (0);
}