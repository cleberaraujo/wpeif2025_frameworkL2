#ifndef CONFIG_APPLIER_H
#define CONFIG_APPLIER_H

#include <omnetpp.h>

using namespace omnetpp;

class ConfigApplier : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif // CONFIG_APPLIER_H
