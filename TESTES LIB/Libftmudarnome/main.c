#include "ft_printf.h"

int main()
{
    int org;
    int ft;
    char *str = "avi";
    

    org = printf("%c%s Melo Cardozo\n",'D', str);
    ft = ft_printf("%c%s Melo Cardozo\n",'D', str);
    printf("org: %d | ft: %d\n", org, ft);
    ft_printf("org: %d | ft: %d\n", org, ft);
    org = printf("Ano: %x | %X\n", 2004, 2004);
    ft = ft_printf("Ano: %x | %X\n", 2004, 2004);
    printf("org: %i | ft: %i\n", org, ft);
    ft_printf("org: %i | ft: %i\n", org, ft);
    org = printf("Endereco: %p\n", str);
    ft = ft_printf("Endereco: %p\n", str);
    printf("org: %i | ft: %i\n", org, ft);
    ft_printf("org: %i | ft: %i\n", org, ft);
    org = printf("%% %%\n");
    ft = ft_printf("%% %%\n");
    printf("org: %i | ft: %i\n", org, ft);
    ft_printf("org: %i | ft: %i\n", org, ft);
    org = printf("%\n");
    ft = ft_printf("%\n");
    printf("org: %i | ft: %i\n", org, ft);
    ft_printf("org: %i | ft: %i\n", org, ft);
    return 0;
}