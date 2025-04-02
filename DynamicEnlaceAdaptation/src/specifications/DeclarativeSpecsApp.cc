#include "DeclarativeSpecsApp.h"
#include "SpecMessages_m.h" // Gerado a partir do SpecMessages.msg

Define_Module(DeclarativeSpecsApp);

void DeclarativeSpecsApp::initialize() {
    // Inicialize o módulo (por exemplo, enviar uma especificação declarativa)
    // Exemplo: Enviar mensagem JSON com requisitos.
    cMessage *msg = new cMessage("specification");
    send(msg, "specOut");
}

void DeclarativeSpecsApp::handleMessage(cMessage *msg) {
    // Processa mensagens de resposta ou atualizações
    EV << "Received message: " << msg->getName() << "\n";
    delete msg;
}
