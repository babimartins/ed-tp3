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
                node.keyA = emailKey;
                node.keyB = destKey;
                for (int i = 1; i < messageSize; ++i) {
                    std::string aux;
                    input >> aux;
                    email += " " + aux;
                }
                node.data = email;
                hash.insert(destKey % mod, node);

                output << "OK: MENSAGEM " << node.keyA << " PARA " << node.keyB << " ARMAZENADA EM " << destKey % mod << std::endl;

            } else if (command == "CONSULTA") {
                int destKey, emailKey;
                input >> destKey >> emailKey;

                Node<std::string> email = hash.search(destKey % mod, emailKey, destKey);
                std::string message = (email.keyA == -1 || email.keyB == -1) ? "MENSAGEM INEXISTENTE" : email.data;

                output << "CONSULTA " << destKey << " " << emailKey << ": " << message << std::endl;

            } else if (command == "APAGA") {
                int destKey, emailKey;
                input >> destKey >> emailKey;

                bool removed = hash.remove(destKey % mod, emailKey, destKey);
                std::string message = removed ? "OK: MENSAGEM APAGADA" : "ERRO: MENSAGEM INEXISTENTE";

                output << message << std::endl;
            }
        }
    }
}
