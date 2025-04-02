package dynamicenlaceadaptation.specifications;

import inet.node.inet.StandardHost;
import dynamicenlaceadaptation.specifications.DeclarativeSpecsApp;

module HostWithDeclarativeSpecsApp extends StandardHost
{
    submodules:
        specsApp: DeclarativeSpecsApp {
            @display("p=60,60");
        }
    connections allowunconnected:
        // conectar a interface eth[0] a specsApp,
        // o NED externo conecta specsOut e specIn
}
