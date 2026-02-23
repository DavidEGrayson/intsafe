@echo on
setlocal
echo #include ^<intsafe.h^> > intsafe_under_test.h
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" -arch=x86
cl /external:W1 /external:I . /TC run_tests.cpp
run_tests
cl /external:W1 /external:I . /std:c++17 run_tests.cpp
run_tests

call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" -arch=x64
cl /external:W1 /external:I . /TC run_tests.cpp
run_tests
cl /external:W1 /external:I . /std:c++17 run_tests.cpp
run_tests
