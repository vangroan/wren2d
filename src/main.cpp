

#include "../lib/wren/src/include/wren.h"


int main(void) {

    WrenConfiguration config;
    wrenInitConfiguration(&config);
    WrenVM* vm = wrenNewVM(&config);

    wrenInterpret(vm, "System.print(\"Hello World\")");

    wrenFreeVM(vm);

    return 0;
}