#include <Python.h>

int main(int argc, char *argv[])
{
    using wchar_p = wchar_t*;
    wchar_p wargv[argc];
    for (int i = 0; i < argc; ++i)
        wargv[i] = Py_DecodeLocale(argv[i], NULL);

    int res = Py_Main(argc, wargv);

    for (int i = 0; i < argc; ++i)
        PyMem_RawFree(wargv[i]);

    return res;
}
