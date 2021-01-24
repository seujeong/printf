#include "ft_printf.h"

void    check_width_precision(va_list my_list, char *format, f_info *info, int i)
{

}

int     print_format(const char *format, va_list my_list)
{
    int     index;
    int     result;

    index = 0;
    result = 0;
    while (format[index] != '\0')
    {

    }
}

int     ft_printf(const char *format, ...)
{
    int     result;
    va_list my_list;

    va_start(my_list, format);

    va_end(my_list);
    return(result);
}
