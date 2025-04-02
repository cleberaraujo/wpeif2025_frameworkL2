// MecanismoAdaptacaoDinamica.cc
#include "MecanismoAdaptacaoDinamica.h"

Define_Module(MecanismoAdaptacaoDinamica);

void MecanismoAdaptacaoDinamica::initialize()
{
    EV << "Mecanismo de Adaptação Dinâmica inicializado." << endl;
}

void MecanismoAdaptacaoDinamica::handleMessage(cMessage *msg)
{
    // Recebe a mensagem de especificação
    if (DeclarativeSpecification *spec = dynamic_cast<DeclarativeSpecification *>(msg)) {
        EV << "Recebida especificação do " << spec->getRequesterName()
           << " - BW:" << spec->getRequiredBandwidth() << "Mbps, Lat:" << spec->getMaxLatency() << "ms" << endl;
        // Futuramente, passamos por Controlador de Admissão, etc.
    }
    delete msg;
}
