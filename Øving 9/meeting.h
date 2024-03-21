#pragma once
#include "ostream"
#include "iostream"

enum class Campus {
    Trondheim,
    Ålesund,
    Gjøvik
};
std::ostream& operator<<(std::ostream& os, Campus campus) {
    switch(campus) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case Campus::Ålesund:
            os << "Ålesund";
            break;
        case Campus::Gjøvik:
            os << "Gjøvik";
            break;
    }
    return os;
}