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

			if (*format == 'c')
			{

				char actv_para = va_arg(my_args, int);
				putchar(actv_para);
				chars_written += 1;
				format++;
			
			}
			else if (*format == 's')
			{
				chars_written += print_str(my_args);
				format++;
			}
			else if (*format == '%')
			{
				putchar('%');
				chars_written += 1;
				format++;
			}
			else
			{
			putchar('%');
			chars_written += 1;
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
