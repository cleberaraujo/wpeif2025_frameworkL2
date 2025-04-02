#ifndef MULTICAST_MODULE_H
#define MULTICAST_MODULE_H

#include <omnetpp.h>

using namespace omnetpp;

class MulticastModule : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif // MULTICAST_MODULE_H
