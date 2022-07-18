#include "../include/files.h"
#include "../include/hash.h"
#include "../include/email.h"

void handleFiles(const std::string &inputFilename, const std::string &outputFilename) {
    std::fstream input;
    input.open(inputFilename, std::fstream::in);
    std::fstream output;
    output.open(outputFilename, std::fstream::out);


    if (input.is_open()) {
        std::string command;

        int mod;
        input >> mod;

        Hash<Email> hash = Hash<Email>(mod);

        while (input >> command) {
            if (command == "ENTREGA") {
                int n, dest;
                Email email = Email();
                input >> dest >> email.key >> n;
                for (int i = 0; i < n; ++i) {
                    std::string message;
                    input >> message;
                    email.message += message;
                }
                Node<Email> node = Node<Email>(email);
                hash.insert(node);
            } else if (command == "CONSULTA") {
            } else if (command == "APAGA") {
            }
        }
    }
}
