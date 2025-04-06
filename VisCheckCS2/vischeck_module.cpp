#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "VisCheck.h"

namespace py = pybind11;

PYBIND11_MODULE(vischeck, m) {
    py::class_<Vector3>(m, "Vector3")
        .def(py::init<float, float, float>())
        .def_readwrite("x", &Vector3::x)
        .def_readwrite("y", &Vector3::y)
        .def_readwrite("z", &Vector3::z);

    py::class_<VisCheck>(m, "VisCheck")
        .def(py::init<const std::string&>())
        .def("is_visible", [](VisCheck& self,
            const std::tuple<float, float, float>& p1,
            const std::tuple<float, float, float>& p2) {
                Vector3 point1{ std::get<0>(p1), std::get<1>(p1), std::get<2>(p1) };
                Vector3 point2{ std::get<0>(p2), std::get<1>(p2), std::get<2>(p2) };
                return self.IsPointVisible(point1, point2);
            }, py::arg("point1"), py::arg("point2"));
}