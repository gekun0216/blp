#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

// int open(const char *pathname, int flags);
// int open(const char *pathname, int flags, mode_t mode);

//TODO: the how to use global errno?

int main() {

    char *file_path = "/home/gekun/temp/hello.sh";
    char *script = "echo \"hello world\"\n";
    int file_des = 0;
    int ret = 0;
    int file_opened = 0;

    file_des = open(file_path, O_WRONLY | O_APPEND);
    if (file_des != -1) {
        printf("%s already exists, file_des = %d\n", file_path, file_des);
        file_opened = 1; 
    } else {
        printf("file_des = -1, %s must NOT exist, try to create it\n", file_path);
        file_des = open(file_path, O_CREAT | O_WRONLY, 
                        S_IRUSR | S_IWUSR| S_IXUSR | S_IXOTH);
        
        if (file_des != -1) { 
            printf("create file %s, file_des = %d\n", file_path, file_des);
            file_opened = 1; 
        } else {
            printf("file_des = -1, something wrong while create %s.\n", file_path);
            exit(1);
        }
    }

    if (file_opened) {
        ret = write(file_des, script, 21);
        if (ret == -1)
            printf("something wrong while write to %s, pls check.\n", file_path);

        ret = close(file_des);
        if (ret != 0)
            printf("something wrong while closing %s, pls check.\n", file_path);
    }

}
