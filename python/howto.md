# Learning Python Cheat sheet

## Extending Python with C

```c
#include <python3.10/Python.h>
#include <stdio.h>

PyObject *add(PyObject *self, PyObject *args)
{
    double x;
    double y;
    PyArg_ParseTuple(args, "dd", &x, &y);
    return PyFloat_FromDouble(x + y);
}

static PyMethodDef methods[] = {
    {"add", add, METH_VARARGS, "Adds two numbers"},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef abc123 = {
    PyModuleDef_HEAD_INIT,
    "abc123",
    "This is a module named abc123",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_abc123() {
    printf("Hello World\n");
    return PyModule_Create(&abc123);
}
```

compile with `gcc file.c -shared -fPIC -o abc123.so`.

## Scope of the variable in python

```python
#!/usr/bin/pyrhon3

def test_1():
    def test_1_1():
        i = 4

    def test_1_2():
        nonlocal i
        i = 10

    def test_1_3():
        global i
        i = 20

    i = 14
    print("i currently : ", str(i))
    test_1_1()
    print("after calling test_1_1() ", str(i))
    test_1_2()
    print("after calling test_1_2() ", str(i))
    test_1_3()
    print("after calling test_1_3() ", str(i))

test_1()
print("global val ", str(i))
```

### Python input

```python
#!/usr/bin/python

if __name__ == "__main__":
    input_str = input("enter something")
    print(input_str)

```

When run as a script, the starting point can be put within the conditional `if __name__ == "__main__"`. Lets us test the code module wise.

Allows modularization of the code.


### Annotations

```python
#!/usr/bin/python

def get_hash(r:'input value') -> 'hash':
    return r * r * 2;

print(get_hash.__annotations__)

```

The arrow notation mentions return type.

anything followed by the `:` for the variable mean it is an annotation.

