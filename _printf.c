#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = o;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = (char) va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					while (*s)
					{
						putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return count;
