package dynamicenlaceadaptation.modules;

simple MulticastModule
{
    parameters:
        @display("i=device/switch");
    gates:
        input configIn;
        output configOut;
}
