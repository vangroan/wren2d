

env = Environment(
    tools=['mingw'], 
    CPPPATH='lib/wren/src/include/;lib/wren/src/vm/;lib/wren/src/optional/',
    CCFLAGS='-Wall -std=c99',
    )
sources = (
        Glob('lib/wren/src/optional/*.c'),
        Glob('lib/wren/src/vm/*.c'),
        Glob('src/*.cpp'),
    )
env.Program('build/wren2d', sources)

