#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){

    char* opts = (char*)":f:t:m:r:hv";
    int opt;

    char* filename;
    int indent = 1;
    int redline = 2;
    char* symb = (char*)".";

    while((opt = getopt(argc, argv, opts)) != -1){
        switch(opt){
            case 'f':
                filename = optarg;
                break;
            case 't':
                if (optarg) indent = atoi(optarg);
                break;
            case 'm':
                if (optarg) symb = optarg;
                break;
            case 'r':
                if (optarg) redline = atoi(optarg);
                break;
            case 'h':
                std::cout << "help is printed" << std::endl;
                break;
            case 'v':
                std::cout << "version 0" << std::endl;
                break;
            case '?':
                std::cout << "undefined option -" << (char)optopt << std::endl;
                break;
        }
    }

    std::cout << "Filename is \"" << filename << "\"" << std::endl;
    std::cout << "Indent is " << indent << " spaces" << std::endl;
    std::cout << "Redline is " << redline << std::endl;
    std::cout << "List marker is " << symb << std::endl;

    return 0;
}