#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    struct stat st;

    if(stat(filename, &st) == 0) {
        printf("st_dev: %d\n", st.st_dev);
        printf("st_ino: %d\n", st.st_ino);
        printf("st_mode: %x\n", st.st_mode);
        printf("st_nlink: %d\n", st.st_nlink);
        printf("st_uid: %d\n", st.st_uid);
        printf("st_gid: %d\n", st.st_gid);
        printf("st_rdev: %d\n", st.st_rdev);
        printf("st_size: %d\n", st.st_size);
        printf("st_blksize: %ld\n", st.st_blksize);
        printf("st_blocks: %ld\n", st.st_blocks);
        printf("st_atime: %d\n", st.st_atime);
        printf("st_mtime: %d\n", st.st_mtime);
        printf("st_ctime: %d\n", st.st_ctime);
    }

}
