package dynamicenlaceadaptation.simulations;

import inet.linklayer.ethernet.switch.EthernetSwitch;
import inet.node.inet.StandardHost;
import inet.common.misc.ThruputMeteringChannel;

import dynamicenlaceadaptation.specifications.DeclarativeSpecsApp;
import dynamicenlaceadaptation.communication.SpecCommunicator;
import dynamicenlaceadaptation.adaptation.MecanismoAdaptacaoDinamicaSimple;

channel Eth100M extends ThruputMeteringChannel {
    delay = 0.1ms;
    datarate = 100Mbps;
}

module HostWithDeclarativeSpecsApp extends StandardHost
{
    submodules:
        specsApp: DeclarativeSpecsApp {
            @display("p=50,50");
        }
    connections allowunconnected:
        // se quiser, conectar specsApp internamente
}

network scenario1
{
    submodules:
        host: HostWithDeclarativeSpecsApp {
            @display("p=100,100");
        }
        switch: EthernetSwitch {
            @display("p=300,100");
        }
        specComm: SpecCommunicator {
            @display("p=200,200");
        }
        adaptation: MecanismoAdaptacaoDinamicaSimple {
            @display("p=400,200");
        }

    connections allowunconnected:
        host.eth[0] <--> Eth100M <--> switch.eth[0];
        host.specsApp.specOut --> specComm.specIn;
        specComm.specOut --> adaptation.specIn[0];
}
