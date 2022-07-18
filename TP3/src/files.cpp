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

        Hash<std::string> hash = Hash<std::string>(mod);

        while (input >> command) {
            if (command == "ENTREGA") {
                int messageSize, destKey, emailKey;
                std::string email;
                Node<std::string> node;

                input >> destKey >> emailKey >> messageSize >> email;
                node.key = emailKey;
                for (int i = 1; i < messageSize; ++i) {
                    std::string aux;
                    input >> aux;
                    email += " " + aux;
                }
                node.data = email;
                hash.insert(node, destKey % mod);

                output << "OK: MENSAGEM " << node.key << " PARA " << destKey << " ARMAZENADA EM " << destKey % mod << std::endl;

            } else if (command == "CONSULTA") {
                int destKey, emailKey;
                input >> destKey >> emailKey;

                Node<std::string> email = hash.search(destKey % mod, emailKey);
                std::string message = (email.key == -1) ? "MENSAGEM INEXISTENTE" : email.data;

                output << "CONSULTA " << destKey << " " << emailKey << ": " << message << std::endl;

            } else if (command == "APAGA") {
                int destKey, emailKey;
                input >> destKey >> emailKey;

                bool removed = hash.remove(destKey % mod, emailKey);
                std::string message = removed ? "OK: MENSAGEM APAGADA" : "ERRO: MENSAGEM INEXISTENTE";

                output << message << std::endl;
            }
        }
    }
}
