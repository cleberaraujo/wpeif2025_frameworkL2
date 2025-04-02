#include <fstream>
#include <sstream>
#include "SpecMessage_m.h"

void DeclarativeSpecsApp::initialize() {
    // Lê o conteúdo do arquivo JSON
    std::ifstream file("scenario2_hostA.json");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonContent = buffer.str();

    // Cria uma mensagem SpecMessage e define o campo 'spec' com o conteúdo JSON lido
    SpecMessage *specMsg = new SpecMessage("SpecFromFile");
    specMsg->setSpec(jsonContent.c_str());

    send(specMsg, "specOut");
}
