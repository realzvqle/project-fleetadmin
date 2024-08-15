#include "saving.h"


#define STRING_SIZE 50




bool save_file(char* filename, void* data, size_t data_size, size_t count){
    FILE* fp = fopen(filename, "wb");
    if(!fp){
        return false;
    }
    fwrite(data, data_size, count, fp);
    fclose(fp);
    return true;
}

bool check_if_file_exists(char* filename){
    FILE* fp = fopen(filename, "r");
    if(!fp) return false;
    else return true;
}

bool read_file(char* filename, void* data, size_t data_size, size_t count){
    FILE* fp = fopen(filename, "rb");
    if(!fp){
        return false;
    }
    fread(data, data_size, count, fp);
    fclose(fp);
    return true;
}