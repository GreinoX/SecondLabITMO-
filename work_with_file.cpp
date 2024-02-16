//
// Created by Thund on 15.02.2024.
//

#include "work_with_file.h"

File::File(){
    ptr = nullptr;
    filename = "";
    is_open = false;
}

File::File(const char * name_of_file){
    ptr = nullptr;
    filename = name_of_file;
    is_open = false;
}

void File::open_file(){
    ptr = fopen(filename, "wb");
    if(ptr == nullptr){
        std::cout << "Can not open file.";
    }else is_open = true;
}

void File::close_file(){
    if(is_open){
        fclose(ptr);
        ptr = nullptr;
        filename = "";
        is_open = false;
    }
}

std::string File::get_file_name(){
    return filename;
}

void File::write_string_to_file(const std::string *data){
    if(is_open){
        std::fwrite(data, sizeof(char), data->length(), ptr);
        std::cout << "Successfully written.";
    }
}

void File::write_number_to_file(const int &data){
    if(is_open){
//            std::fwrite(data, sizeof(int), 1, ptr);
        std::fprintf(ptr, "%d", data);
        std::cout << "Successfully written.";
    }
}

void File::write_number_to_file(const double &data){
    if(is_open){
        std::fprintf(ptr, "%f", data);
        std::cout<<"Successfully written.";
    }
}

bool File::is_file_open(){
    return is_open;
}