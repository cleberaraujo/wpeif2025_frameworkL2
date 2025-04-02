#include "MecanismoAdaptacaoDinamica.h"
#include "SpecMessage_m.h"  // Mensagem definida no .msg

Define_Module(MecanismoAdaptacaoDinamica);

void MecanismoAdaptacaoDinamica::initialize() {
    EV << "MecanismoAdaptacaoDinamica initialized.\n";
}

void MecanismoAdaptacaoDinamica::handleMessage(cMessage *msg) {
    // Supondo que a mensagem seja do tipo SpecMessage
    SpecMessage *specMsg = check_and_cast<SpecMessage *>(msg);
    std::string spec = specMsg->getSpec();
    EV << "MAD received spec: " << spec << "\n";

    // parsing simples, gera comandos
    if (spec.find("\"latency\": \"50") != std::string::npos) {
        // cria mensagem de comando comando NETCONF.
        cMessage *netconfCmd = new cMessage("SetLatencyCommand");
        netconfCmd->addPar("latencyValue") = 50;
        EV << "MAD mapped spec to NETCONF command: Set latency to 50 ms\n";
        // Envia a mensagem para o Aplicador de Configurações (AC)
        send(netconfCmd, "configOut");
    } else {
        EV << "Spec not recognized; no command generated.\n";
    }
    delete specMsg;
}
