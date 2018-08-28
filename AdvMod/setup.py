from distutils.core import setup, Extension, DEBUG

AdMod = Extension('AdvMod', sources = ['Admod.cpp'])

setup(name = 'AdvMod', version = '1.0',
    description = 'Python Package For Advantech digital I/O.',
    ext_modules = [AdMod]
    )