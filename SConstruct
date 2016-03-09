
import os

env = Environment(
    tools=['mingw'], 
    CPPPATH='lib/wren/src/include',
    CCFLAGS='-Wall',
    CFLAGS='-Wall -std=c99 -DWREN_OPT_META=0 -DWREN_OPT_RANDOM=0',
    ENV={'PATH' : os.environ['PATH']},
    )
sources = (
        Glob('src/*.cpp'),
        Glob('lib/wren/src/vm/*.c'),
    )
env.Program('build/wren2d', sources)

