package dynamicenlaceadaptation.adaptation;

simple MecanismoAdaptacaoDinamicaSimple
{
    @class(MecanismoAdaptacaoDinamica);
    gates:
        input specIn[]; // Permite receber de múltiplas fontes
        output configOut[]; // Saídas para configurar a rede
}
