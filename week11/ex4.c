#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    int input_file = open("ex1.txt", O_RDONLY, (mode_t)0600);
    off_t file_size = lseek(input_file, 0, SEEK_END);
    
    char *map_input = mmap(0, file_size, PROT_READ, MAP_PRIVATE, input_file, 0);


    int output_file = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t)0600);
    ftruncate(output_file, file_size);

    char* map_output = mmap(0, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, output_file, 0);

    memcpy(map_output, map_input, file_size);
    
    munmap(map_input, file_size);
    munmap(map_output, file_size);

    close(input_file);
    close(output_file);
    return 0;
}