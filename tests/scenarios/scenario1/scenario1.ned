package dynamicenlaceadaptation.simulations;

import inet.linklayer.ethernet.switch.EthernetSwitch;
import inet.common.misc.ThruputMeteringChannel;
import dynamicenlaceadaptation.specifications.HostWithDeclarativeSpecsApp;
import dynamicenlaceadaptation.specifications.DeclarativeSpecsApp;
import dynamicenlaceadaptation.communication.SpecCommunicator;
import dynamicenlaceadaptation.adaptation.MecanismoAdaptacaoDinamicaSimple;

channel Eth100M extends ThruputMeteringChannel {
    delay = 0.1ms;
    datarate = 100Mbps;
}

network scenario1
{
    submodules:
        host: HostWithDeclarativeSpecsApp;
        switch: EthernetSwitch;
        specComm: SpecCommunicator;
        adaptation: MecanismoAdaptacaoDinamicaSimple;

    connections allowunconnected:
        // L2 normal
        host.eth[0] <--> Eth100M <--> switch.eth[0];

        // Conexão lógica para especificações
        host.specsApp.specOut --> specComm.specIn;
        specComm.specOut --> adaptation.specIn[0];
}
