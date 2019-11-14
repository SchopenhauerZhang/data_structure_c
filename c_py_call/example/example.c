#include <pybind11/pybind11.h>

int add(int x,int y){
    return x+y;

}

PYBIND11_MODULE(example, m) {
    m.doc() = " example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
}
