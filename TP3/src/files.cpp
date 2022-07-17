#include "../include/files.h"
#include "../include/hash.h"

void handleFiles(const std::string &inputFilename, const std::string &outputFilename) {
    std::fstream input;
    input.open(inputFilename, std::fstream::in);
    std::fstream output;
    output.open(outputFilename, std::fstream::out);


    if (input.is_open()) {
        std::string command;

        int mod;
        input >> mod;

        Hash<int> hash = Hash<int>(mod);

        while (input >> command) {
            if (command == "ENTREGA") {
            } else if (command == "CONSULTA") {
            } else if (command == "APAGA") {
            }
        }
    }
}
