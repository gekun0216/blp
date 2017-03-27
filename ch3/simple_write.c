#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// write __n from __buf to __fd
// extern ssize_t write (int __fd, __const void *__buf, size_t __n) __wur;
// read __nbytes from __fd to __buf
// extern ssize_t read (int __fd, void *__buf, size_t __nbytes) __wur;

int main() {

    int char_num_to_write, char_num_actually_write;
    int i = 0, ch_len = 0;
    char *ch1 = "here is some data\n";

    for (i = 0; ch1[i] != '\0'; i++) {
        ch_len++;    
    }
    printf("ch_len = %d\n", ch_len);
//    char_num_to_write = ch_len;

//    The buffer is bigger than the ch array
    char_num_to_write = ch_len;
    printf("char_num_to_write = %d\n", char_num_to_write);

    char_num_actually_write = write(1, "here is some data\n", char_num_to_write);
    printf("char_num_actually_write = %d\n", char_num_actually_write);
        

    if (char_num_actually_write != char_num_to_write)
        write(2, "a write error has occurred on file descriptor 1\n", 46);

    exit(0);

}
