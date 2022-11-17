#define BUFF_SIZE 10
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd = open("testfile.txt", O_RDONLY);
    char buff[BUFF_SIZE];
    int read_size;

    memset(buff, 0, BUFF_SIZE);
    read_size = read(fd, buff, BUFF_SIZE);
    while (read_size > 0)
    {
        printf("%s\n", buff);
        if (read_size < BUFF_SIZE)
            break;
        read_size = read(fd, buff, BUFF_SIZE);
    }
    close(fd);
}