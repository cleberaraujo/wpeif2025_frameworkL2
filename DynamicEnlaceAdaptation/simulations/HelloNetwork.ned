package dynamicenlaceadaptation.simulations;

import dynamicenlaceadaptation.specifications.DeclarativeSpecsApp;
import dynamicenlaceadaptation.adaptation.MechanismAdaptationDinamica;
import dynamicenlaceadaptation.configuration.ConfigApplier;
import dynamicenlaceadaptation.modules.MulticastModule;
import inet.linklayer.ethernet.EthernetSwitch;

network HelloNetwork
{
    submodules:
        host: DeclarativeSpecsApp {
            @display("p=100,200");
        }
        adaptation: MechanismAdaptationDinamica {
            @display("p=250,200");
        }
        applier: ConfigApplier {
            @display("p=400,200");
        }
        multicast: MulticastModule {
            @display("p=400,350");
        }
        switch: EthernetSwitch {
            @display("p=250,350");
        }
    connections allowunconnected:
        host.specOut --> adaptation.specIn[0];
        adaptation.configOut[0] --> applier.configIn[0];
        applier.configOut[0] --> multicast.configIn;
}
