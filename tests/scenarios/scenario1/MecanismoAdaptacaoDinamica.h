// MecanismoAdaptacaoDinamica.h
#ifndef __DYNAMICENLACEADAPTATION_MECANISMOADAPTACAODINAMICA_H_
#define __DYNAMICENLACEADAPTATION_MECANISMOADAPTACAODINAMICA_H_

#include <omnetpp.h>
#include "SpecMessages_m.h"

using namespace omnetpp;

class MecanismoAdaptacaoDinamica : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
