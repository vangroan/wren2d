
extern "C" {
    #include <wren.h>
}

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>


struct foreignFuncReg_t {
    char* module;
    char* className;
    bool isStatic;
    char* signature;
    WrenForeignMethodFn f;

    bool operator==(const foreignFuncReg_t& rhs) const {
        // NULL is not allowed in strcmp.
        return (strcmp(module,rhs.module) == 0
            && strcmp(className,rhs.className) == 0
            && isStatic == rhs.isStatic
            && strcmp(signature, rhs.signature) == 0
            && f == rhs.f);
    }
};


void myAddFunc(WrenVM* vm) {
    double a = wrenGetSlotDouble(vm, 1);
    double b = wrenGetSlotDouble(vm, 2);

    wrenSetSlotDouble(vm, 0, a+b);
}

void mySubFunc(WrenVM* vm) {
    double a = wrenGetSlotDouble(vm, 1);
    double b = wrenGetSlotDouble(vm, 2);

    wrenSetSlotDouble(vm, 0, a-b);
}


const foreignFuncReg_t methods[] = {
    {"main", "MyClass", true, "add(_,_)", myAddFunc},
    {"main", "MyClass", true, "sub(_,_)", mySubFunc},
    {NULL, NULL, false, NULL, NULL}
};

WrenForeignMethodFn bindForeignMethod(WrenVM* vm,
                                                const char* module,
                                                const char* className,
                                                bool isStatic,
                                                const char* signature) {
    
    printf("Loading:\n");
    printf("Module: %s; Class: %s; Static: %s; Signature: %s\n",
        module,
        className,
        isStatic ? "true" : "false",
        signature);

    size_t i = 0;
    foreignFuncReg_t m = methods[i];

    printf("Searching:\n");
    while (m.f != NULL) {
        
        printf("Module: %s; Class: %s; Static: %s; Signature: %s; Func: %d\n",
        m.module,
        m.className,
        m.isStatic ? "true" : "false",
        m.signature,
        m.f);

        if (strcmp(m.module, module) == 0 
            && strcmp(m.className, className) == 0
            && m.isStatic == isStatic
            && strcmp(m.signature, signature) == 0) { 
            printf("Found\n");
            return m.f; 
        } else {
            m = methods[++i];
        }
    }
    printf("Not found\n");
    return NULL;
}

void writeFn(WrenVM* vm, const char* text) {
    printf(text);
}

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


int main(void) {
    printf("In C\n");

    WrenConfiguration config;
    wrenInitConfiguration(&config);

    config.bindForeignMethodFn = bindForeignMethod;
    config.writeFn = writeFn;

    WrenVM* vm = wrenNewVM(&config);
    
    std::string source = load_source("hello.wren");

    WrenInterpretResult result = wrenInterpret(vm, source.c_str());
    printf("Result: %d\n", result);

    wrenFreeVM(vm);

    return 0;
}