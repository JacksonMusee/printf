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
	size_t current_size = sizeof(char);
	char * buffer = malloc(current_size);
	int i = 0;
	ssize_t bytes_written;

	va_list my_args;
	
	va_start(my_args, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char actv_para = va_arg(my_args, int);
					buffer = realloc(buffer, current_size + 1);
					current_size += 1;
					buffer[i] = actv_para;
					i++;
			
			}
			else if (*format == 's')
			{
				char *actv_para = va_arg(my_args, char *);
				if (actv_para)
				{
					while(*actv_para != '\0')
					{
						buffer = realloc(buffer, current_size + 1);
						current_size += 1;
						buffer[i] = *actv_para;
						actv_para++;
						i++;
					}
				}
				
			}
			else if (*format == '%')
			{
				buffer = realloc(buffer, current_size + 1);
				current_size += 1;
				buffer[i] = '%';
				i++;
			}
			format++;

		}
		if (*format != '%')
		{
		buffer = realloc(buffer, current_size + 1);
		current_size += 1;
		buffer[i] = *format;
		i++;
		format++;
		}
	}
	buffer[i] = '\0';
	va_end(my_args);

	bytes_written = write(1, buffer, i);

	free(buffer);

	return (bytes_written);
}
