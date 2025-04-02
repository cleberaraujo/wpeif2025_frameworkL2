#include "ConfigApplier.h"

Define_Module(ConfigApplier);

void ConfigApplier::initialize() {
    EV << "AplicadorDeConfiguracoes inicializado.\n";
}

void ConfigApplier::handleMessage(cMessage *msg) {
    EV << "AC received config command: " << msg->getName() << "\n";
    if (strcmp(msg->getName(), "SetLatencyCommand") == 0) {
        int latencyValue = msg->par("latencyValue").intValue();
        EV << "AC applying NETCONF command: Setting latency to " << latencyValue << " ms on the switch.\n";
        // // a API NETCONF aplicar o comando.
    }
    delete msg;
}
