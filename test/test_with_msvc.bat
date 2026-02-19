@echo on
setlocal
del intsafe.h
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" -arch=x86
cl /TC run_tests.cpp
run_tests
cl /std:c++17 run_tests.cpp
run_tests

call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" -arch=x64
cl /TC run_tests.cpp
run_tests
cl /std:c++17 run_tests.cpp
run_tests
