#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_str(va_list my_args);
int print_char(va_list my_args);
int main_helper(const char *format, va_list my_args, int chars_written);

#endif
