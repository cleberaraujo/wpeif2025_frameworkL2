#include "MulticastModule.h"

Define_Module(MulticastModule);

void MulticastModule::initialize() {
    // Inicialização
}

void MulticastModule::handleMessage(cMessage *msg) {
    // Realiza operações de multicast
    EV << "Processing multicast configuration: " << msg->getName() << "\n";
    delete msg;
}
