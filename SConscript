
from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c') + Glob('*.cpp')
path    = [cwd]

group = DefineGroup('algorithm_ntc', src, depend = ['PKG_USING_ALGORITHM_NTC'], CPPPATH = path)

Return('group')
