#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./get/get_next_line.h"
#include "fdf.h"
//#include "libft.h"

int main(void)
{
    int fd;
    int i;
    char **str;
    char *line;

    fd = open("./test_maps/42.fdf", O_RDONLY);
    if (fd == -1)
        return (0);

    i = 0;
	line = get_next_line(fd);
	str = ft_split(line, ' ');
	while (i++ < 18)
		printf("%s\n", str[i]);
/* 	while (line)
	{
    	line = get_next_line(fd);
		printf("%s\n", line);
		str[i] = ft_split(line, ' ');
		free(line);
		i++;
	} */

    //printf("%s\n", str[0][0]);
    //printf("%s\n", str[1]);
    close(fd);
    return 0;
}
