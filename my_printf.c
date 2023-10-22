#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 *_printf - an imitation of the standard C library printf functon
 *
 *@format: Point to specifiers to handle
 *
 *Return: number of bytes written
 *
 */

int _printf(const char *format, ...)
{
	int chars_written = 0;
	int new_chars_written;
	va_list my_args;

	if (format == NULL)
                return(-1);

	if (my_args == NULL)
		return(0);
	
	va_start(my_args, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);

			new_chars_written = main_helper(format, my_args, chars_written);

			if (new_chars_written > chars_written)
			{
				chars_written = new_chars_written;
				format++;
			}
		}
		else
		{
		putchar(*format);
		chars_written += 1;
		format++;
		}
	}
	va_end(my_args);

	return (chars_written);
}

/**
 *main_helper - Obvious
 *
 *@format: Pointer to current format symbol
 *@my_args: List of arguments to be printed
 *@chars_written: characters printed so far
 *
 *Return: Updated chars_written
 */
int main_helper(const char *format,va_list my_args, int chars_written)
{

	if (*format == 'c')
	{
		chars_written += print_char(my_args);
	}
	else if (*format == 's')
	{
		chars_written += print_str(my_args);
	}
	else if (*format == '%')
	{
		putchar('%');
		chars_written += 1;
	}
	else
	{
		putchar('%');
		putchar(*format);
		chars_written += 2;
	}

	return (chars_written);
}
/**
 *print_str - Help print a string
 *
 *@my_args: Variable of all arguments to be printed
 *
 *Return: Number of character printed
 */

int print_str(va_list my_args)
{
	int chars_written = 0;

	char *actv_para = va_arg(my_args, char *);

	if (actv_para == NULL)
		actv_para = "(null)";
	
	if (actv_para)
	{
		while(*actv_para != '\0')
		{
			putchar(*actv_para);
			chars_written += 1;
			actv_para++;
		}
	}

	return (chars_written);
}

/**
 *print_char - Help in printing characters
 *
 *@my_args: Arguments lst
 *
 *Return: Number of characters printed
 */

int print_char(va_list my_args)
{
	int chars_written = 0;

	char actv_para = va_arg(my_args, int);

	putchar(actv_para);
        chars_written += 1;

	return (chars_written);
}
