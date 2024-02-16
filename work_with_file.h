//
// Created by Thund on 15.02.2024.
//

#ifndef SECONDLAB_WORK_WITH_FILE_H
#define SECONDLAB_WORK_WITH_FILE_H

#include<iostream>

class File{
private:
    std::FILE *ptr;
    const char * filename;
    bool is_open;
public:
    File();

    File(const char * name_of_file);

    void open_file();

    void close_file();

    std::string get_file_name();

    void write_string_to_file(const std::string *data);

    void write_number_to_file(const int &data);

    void write_number_to_file(const double &data);

    bool is_file_open();
};
#endif //SECONDLAB_WORK_WITH_FILE_H
