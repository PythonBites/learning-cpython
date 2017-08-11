#include <iostream>
#include <Python.h>

int main(int argc, char *argv[])
{
    Py_Initialize();
    PyRun_SimpleString("a = 1");
    PyRun_SimpleString("b = 2");
    PyRun_SimpleString("print(a+b)");
    Py_Finalize();
    return 0;
}
