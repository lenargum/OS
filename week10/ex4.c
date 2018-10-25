#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
    char dir_name[100] = "tmp"; //dir_name = "tmp"
    DIR *opened_dir = opendir(dir_name);
    if(opened_dir == NULL) {
        return 1;
    }
    strcat(dir_name,"/"); //dir_name = "tmp/"



    struct stat statistics;
    struct dirent *dir_entity;

    while((dir_entity = readdir(opened_dir))!=NULL){
        char temp_path[100];                    //temp_path = ""
        strcpy(temp_path,dir_name);             //temp_path = "tmp/"
        strcat(temp_path,dir_entity->d_name);   //temp_path = "tmp/<next_file>"
        stat(temp_path,&statistics);

        if(statistics.st_nlink > 1){
            printf("Links for \"%s\": ",dir_entity->d_name);

            struct dirent *next_link;
            DIR *dir2 = opendir("tmp");
            while((next_link = readdir(dir2)) != NULL){
                if((next_link->d_ino == dir_entity->d_ino)!=0){
                    printf("%s ",next_link->d_name);
                }
            }
            printf("\n");
        }
    }
    return 0;
}