
extern "C" {
    #include <wren.h>
}

#include <stdio.h>

void writeFn(WrenVM* vm, const char* text) {
    printf(text);
}

int main(void) {

    printf("In C\n");

    WrenConfiguration config;
    wrenInitConfiguration(&config);

    config.writeFn = writeFn;

    WrenVM* vm = wrenNewVM(&config);

    WrenInterpretResult result = wrenInterpret(vm, "System.print(\"Hello World\")");
    printf("Result: %d\n", result);

    wrenFreeVM(vm);

    return 0;
}