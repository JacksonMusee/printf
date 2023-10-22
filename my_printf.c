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

	if (my_args == NULL || (my_args == NULL && format == NULL))
		return(0);
	
	va_start(my_args, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{

				char actv_para = va_arg(my_args, int);
				putchar(actv_para);
				chars_written += 1;
				format++;
			
			}
			else if (*format == 's')
			{
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
					format++;
				}
				
			}
			else if (*format == '%')
			{
				putchar('%');
				chars_written += 1;
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
