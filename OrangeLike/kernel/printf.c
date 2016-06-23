


#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"


int printf(const char *fmt, ...)
{

	int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);
	write(buffer, i);

	return i;
}

int printf_A(const char *fmt, ...)
{

	int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);
	write_A(buffer, i);

	return i;
}
int printf_B(const char *fmt, ...)
{

	int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);
	write_B(buffer, i);

	return i;
}
int printf_C(const char *fmt, ...)
{

	int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);
	write_C(buffer, i);

	return i;
}

int printinfo(const char *fmt,...)
{
    int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);


	write_info(buffer, i);

	return i;

}

int printinfo_A(const char *fmt,...)
{
    int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);


	write_info_A(buffer, i);

	return i;

}

int printinfo_B(const char *fmt,...)
{
    int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);


	write_info_B(buffer, i);

	return i;

}
int printinfo_C(const char *fmt,...)
{
    int i;
	char buffer[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);
	i = vsprintf(buffer, fmt, arg);


	write_info_C(buffer, i);

	return i;

}
