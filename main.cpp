#include <iostream>
#include "work_with_file.h"
#define nl() std::cout << '\n'
#define declaration "There is commands: ['/input-filename', '/open-file', '/close-file', '/write-string', '/get-file-name', '/exit']."



class Menu{
public:
    void check(const std::string &option, File &workflow){
        if(option == "/input-filename") {
            if(workflow.get_file_name().empty()){
                char filename[100];
                std::cout << "Type name of the file:";
                std::cin >> filename;
                workflow = filename;
            }else std::cout << "Another file in the process.";
        }else if(option == "/open-file"){
            open_file(workflow);

        }else if(option == "/close-file"){
            close_file(workflow);
        }else if(option == "/write-string") {
            write_string(workflow);
        }else if(option == "/get-file-name"){
            std::cout << get_file_name(workflow);
        }else if(option == "/exit"){
            exit_command(workflow);
        }
    }

    std::string get_file_name(File &workflow){
        std::string filename = workflow.get_file_name();
        if(filename.empty()){
            return filename;
        }else return "Was not specified file!";
    }

    void exit_command(File &workflow){
        if(workflow.get_file_name().empty()){
            workflow.close_file();
        }
        exit(0);
    }

    void input_filename(File * workflow){

    }

    void open_file(File &workflow){
        if(workflow.get_file_name().empty()){
            workflow.get_file_name();
        }else std::cout << "Was not specified file!";
    }

    void write_string(File &workflow){
        if(workflow.get_file_name().empty()){
            std::string data_to_write;

            std::cout << "Type string to write:";
            std::cin >> data_to_write;
            nl();
            workflow.write_string_to_file(&data_to_write);
        }else std::cout << "Was not specified file!";
    }

    void close_file(File &workflow){
        if(workflow.get_file_name().empty()){
            workflow.close_file();
        }else std::cout << "Was not specified file!";
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Menu menu;
    File file_to_write;
    std::string option;


    std::cout << declaration;

    nl();
    while(true){
        std::cout << "Command |---> ";
        std::cin >> option;
        nl();
        menu.check(option, file_to_write);
        nl();
        option = "";
    }
}
