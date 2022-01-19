// #include "get_next_line.h"
// #include "get_next_line_utils.c"
#include "get_next_line.c"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	int fd2;
	char *yo = "1234";
	char *ww;
	int i = 1;
	int j = 0;
	int l = 0;

	// if ((fd = open ("./empty_lines.1.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	if ((fd = open ("./empty_lines.2.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("test/files/alternate_line_nl_with_nl", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("test/files/alternate_line_nl_with_nl", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("test/files/43_no_nl", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("./empty_lines.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("test/files/42_with_nl", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("test/files/41_with_nl", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	// if ((fd = open ("test/files/multiple_line_no_nl", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	{
		while(i < 33)
		{
			ww = get_next_line(fd);
			if (ww == NULL)
				break ;
			printf("%d_ret_fd(%d)_Line_%d= -|%s|-\n",i, fd, l + 1, ww);
			l++;
			// while(1)
			// 	continue ;
			// system("leaks main_gnl");
			ww[0] = 'Y';
			free(ww);
			i++;
		}
	}
printf("------- closed1(%d) ------ ", close(fd));
}
