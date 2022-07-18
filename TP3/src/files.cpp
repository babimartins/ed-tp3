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
                int userKey, emailKey;
                input >> userKey >> emailKey;
                Node<Email> email = hash.search(userKey, emailKey);
                std::string message = (email.data.key == -1) ? "MENSAGEM INEXISTENTE" : email.data.message;
                output << "CONSULTA " << userKey << " " << emailKey << ": " << message << std::endl;
            } else if (command == "APAGA") {
                int userKey, emailKey;
                input >> userKey >> emailKey;
                bool removed = hash.remove(userKey, emailKey);
                std::string message = removed ? "OK: MENSAGEM APAGADA" : "ERRO: MENSAGEM INEXISTENTE";
                std::cout << message << std::endl;
            }
        }
    }
}
