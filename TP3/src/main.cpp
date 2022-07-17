#include <iostream>
#include <getopt.h>
#include "../include/files.h"
#include "../include/msgassert.h"

std::string inputFile, outputFile;

void parse_args(int argc, char** argv) {
    int c;
    extern char* optarg;

    inputFile = "";
    outputFile = "";

    while ((c = getopt(argc, argv, "i:I:O:o:")) != EOF) {
        switch (c) {
            case 'i':
            case 'I':
                inputFile = optarg;
                break;
            case 'o':
            case 'O':
                outputFile = optarg;
                break;
            default:
                exit(1);
        }
    }

    erroAssert(inputFile.length() > 0, "main - É necessário fornecer o nome do arquivo de entrada");
    erroAssert(outputFile.length() > 0, "main - É necessário fornecer o nome do arquivo de saída");
}


int main(int argc, char ** argv) {
    parse_args(argc, argv);
    handleFiles(inputFile, outputFile);
}