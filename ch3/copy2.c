
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int open_if_not_exist(const char *file_path, int oflag, mode_t mode); 

main() {

    char block[1024];
    int in, out;
    int nread;
    char *file_in = "/home/gekun/temp/file.in"; 
    char *file_out = "/home/gekun/temp/file.out";

    in = open(file_in, O_RDONLY);
    out = open(file_out, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    printf("file_in_des = %d, file_in: %s\n", in, file_in);
    printf("file_out_des = %d, file_out: %s\n", out, file_out);

    while((nread = read(in, &block, sizeof(block))) > 0)
        write(out, &block, nread);

    exit(0);

}
