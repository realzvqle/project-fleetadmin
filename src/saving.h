#ifndef SAVING_H_INCLUDED
#define SAVING_H_INCLUDED



#include "main.h"





bool save_file(char* filename, void* data, size_t data_size, size_t count);
bool check_if_file_exists(char* filename);
bool read_file(char* filename, void* data, size_t data_size, size_t count);








#endif