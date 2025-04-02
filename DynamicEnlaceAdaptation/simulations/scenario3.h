#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "SpecMessage_m.h"

void DeclarativeSpecsApp::initialize() {
    // Lista dos arquivos de especificações para este experimento
    std::vector<std::string> fileNames = {
        "scenario3_multicast_source_S.json",
        "scenario3_multicast_hostA_in5s_out15s.json",
        "scenario3_multicast_hostB_in5s.json",
        "scenario3_multicast_hostC_in10s.json"
    };

    // Itera sobre cada arquivo, lendo o conteúdo e enviando a mensagem correspondente
    for (const auto &fileName : fileNames) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            EV << "Erro ao abrir o arquivo: " << fileName.c_str() << "\n";
            continue;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string jsonContent = buffer.str();

        // Cria uma mensagem de especificação e atribui o JSON lido
        SpecMessage *specMsg = new SpecMessage("SpecFromFile");
        specMsg->setSpec(jsonContent.c_str());

        // Envia a mensagem pela gate 'specOut'
        send(specMsg, "specOut");
    }
}
