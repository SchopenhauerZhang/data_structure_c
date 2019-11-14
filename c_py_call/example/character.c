#include <pybind11/pybind11.h>
#include <time.h>
char * get(){
    time_t ltime;
    time(&ltime);
    return ctime(&ltime);

}

PYBIND11_MODULE(character,m){
    m.doc() = "pybind11 get time plugin";
    m.def("get",&get,"a function which return get time");
}

