#include <Python.h>

int main(int argc, char *argv[])
{
    Py_Initialize();
    PyRun_SimpleString("a = \"Hello, \"");
    PyRun_SimpleString("b = \"World!\"");
    PyRun_SimpleString("print(a+b)");
    Py_Finalize();
    return 0;
}
