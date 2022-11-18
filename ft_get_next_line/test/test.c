#define BUFF_SIZE 10
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int read_file(char *buff, int fd);

int main()
{
    int fd = open("testfile.txt", O_RDONLY);
    char buff[BUFF_SIZE];
    int read_size;

    while (1)
    {
        read_size = read_file(buff, fd);
        if (read_size < BUFF_SIZE)
            break;
        memset(buff, 0, BUFF_SIZE);
    }

    close(fd);
    /*
    while (read_size > 0)
    {
        write(1, buff, read_size);
        if (read_size < BUFF_SIZE)
            break;
        memset(buff, 0, BUFF_SIZE);
        read_size = read(fd, buff, BUFF_SIZE);
        printf("\nfd : %d\n", fd);
    }
    */
}

int read_file(char *buff, int fd)
{
    int read_size;

    memset(buff, 0, BUFF_SIZE);
    read_size = read(fd, buff, BUFF_SIZE);
    write(1, buff, read_size);
    return (read_size);
}