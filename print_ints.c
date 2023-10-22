#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int print_int(signed int num)
{
	int chars_written = 0;

	if (num < 0)
	{
	putchar('-');
	chars_written += 1;
	num = num * -1;
	}

	if (num / 10 != 0)
	{
		print_int(num / 10);
	}

	putchar(num % 10 + 48);
	chars_written += 1;

	return (chars_written);
}
