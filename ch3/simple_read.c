#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// read __nbytes from __fd to __buf
// extern ssize_t read (int __fd, void *__buf, size_t __nbytes) __wur;


int BUFFER_SIZE = 128 * 8;

int main() {

    char buffer[BUFFER_SIZE];
    int nread;
    
    nread = read(0, buffer, 1024);
    printf("nread = %d\n\n", nread);    

    if (nread == -1)
        write(2, "a read error has ocurred\n", 26);

    if (write(1, buffer, nread) != nread)
        write(2, "a write error has occurred\n", 27);

    exit(0);

}
