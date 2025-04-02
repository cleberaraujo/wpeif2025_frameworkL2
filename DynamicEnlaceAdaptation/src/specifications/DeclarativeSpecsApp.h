#ifndef DECLARATIVE_SPECS_APP_H
#define DECLARATIVE_SPECS_APP_H

#include <omnetpp.h>

using namespace omnetpp;

class DeclarativeSpecsApp : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif // DECLARATIVE_SPECS_APP_H
