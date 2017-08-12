#include <Python.h>

// Define C++ function
double square(double x)
{
    return x*x;
}

// Wrap C++ function in a Python function
static PyObject *wrapSquare(PyObject *self, PyObject *args)
{
    // Convert Python type to C++ type
    double x;
    if (!PyArg_ParseTuple(args, "d", &x))
        return NULL;

    // Call C++ function
    double xSquared = square(x);

    // Convert C++ type to Python type
    return PyFloat_FromDouble(xSquared);
}

// Define list of Python methods
static PyMethodDef MyModuleMethods[] = 
{
    {"square",                                  // method name
     wrapSquare,                                // method wrapper
     METH_VARARGS,                              // method calling convention
     "Computes the square of a given number."}, // method documentation

    {NULL, NULL, 0, NULL} // sentinel
};

// Define new Python module made of above methods
static struct PyModuleDef MyModule = 
{
    PyModuleDef_HEAD_INIT,
    "MyModule",              // module name
    "Provides cool methods", // module documentation
    -1,                      // size of per-interpreter state of the module,
                             // or -1 if the module keeps state in global variables.
    MyModuleMethods          // module methods
};

// Define module's initialization function.
// The name of this function must be PyInit_<modulename>.
PyMODINIT_FUNC
PyInit_MyModule(void)
{
    return PyModule_Create(&MyModule);
}

int main(int argc, char *argv[])
{
    // Add built-in module
    PyImport_AppendInittab("MyModule", PyInit_MyModule);

    Py_Initialize();
    PyRun_SimpleString("from MyModule import square");
    PyRun_SimpleString("x = square(12)");
    PyRun_SimpleString("print(x)");
    Py_Finalize();

    return 0;
}
