#ifndef MECHANISM_ADAPTATION_DINAMICA_H
#define MECHANISM_ADAPTATION_DINAMICA_H

#include <omnetpp.h>

using namespace omnetpp;

class MechanismAdaptationDinamica : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif // MECHANISM_ADAPTATION_DINAMICA_H
