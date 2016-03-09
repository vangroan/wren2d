
extern "C" {
    #include <wren.h>
}

#include <stdio.h>
#include <iostream>
#include <fstream>

std::string load_source(const std::string& filepath) {
    std::ifstream t(filepath.c_str());
    t.seekg(0, std::ios::end);
    size_t size = t.tellg();
    printf("Size: %d\n", size);
    std::string buffer(size, ' ');
    t.seekg(0);
    t.read(&buffer[0], size);
    return buffer;
}

void writeFn(WrenVM* vm, const char* text) {
    printf(text);
}

int main(void) {
    printf("In C\n");

    WrenConfiguration config;
    wrenInitConfiguration(&config);

    config.writeFn = writeFn;

    WrenVM* vm = wrenNewVM(&config);
    
    std::string source = load_source("hello.wren");

    WrenInterpretResult result = wrenInterpret(vm, source.c_str());
    printf("Result: %d\n", result);

    wrenFreeVM(vm);

    return 0;
}