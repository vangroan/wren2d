

env = Environment(
    tools=['mingw'], 
    CPPPATH='lib/wren/src/include/:lib/wren/src/vm/',
    CCFLAGS='-Wall',
    LIBS='wren',
    )
sources = (
        Glob('src/*.cpp'),
        Glob('lib/wren/src/vm/*.c'),
    )
env.Program('wren2d', sources)

