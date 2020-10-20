#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct entity {
    unsigned long long number;
    char* file_name;
};

int compare(const void* a, const void* b) {
    struct entity A = *((struct entity*)a);
    struct entity B = *((struct entity*)b);
    return A.number - B.number;
}

int main() {
    DIR* dirp;
    struct entity items[100];
    int index = 0; 

    struct dirent *entry;
    struct stat statbuf;
    
    dirp = opendir("tmp");
    if (dirp == NULL) {
        fprintf(stderr, "Error while open directory: tmp\n");
        return -1;
    }

    chdir("tmp");
    while ((entry = readdir(dirp)) != NULL) {
        lstat(entry->d_name,&statbuf);

        items[index].number = entry->d_ino;
        items[index].file_name = (char*)malloc(sizeof(char) * strlen(entry->d_name));
        strcpy(items[index].file_name, entry->d_name);
        index += 1;
        if (S_ISDIR(statbuf.st_mode)) {
            if(strcmp(".", entry->d_name) == 0 || strcmp("..",entry->d_name) == 0) {
                continue;
            }
            // printf("%s/\n", entry->d_name);
        }
    }
    chdir("..");
    closedir(dirp);
    
    qsort(items, index, sizeof(struct entity), compare);
    int i = 0;
    while (i < index - 1) {
        if (items[i].number == items[i + 1].number) {
            printf("%llu: %s ", items[i].number, items[i].file_name);
            while (i < index - 1 & items[i].number == items[i + 1].number) {
                printf("%s ", items[i + 1].file_name);
                i += 1;
            }
            printf("\n");
        } else {
            i += 1;
        }
    }

    exit(0);
}