#pragma once
#include "student.h"

class Physics_Student : public Student {
private:
    std::string conc; //biophysics or earth and plnetary sciences

public:
    Physics_Student() : Student(), conc("Biophysics") {}
    
    ~Physics_Student() {}

    void setConc(std::string c) { conc = c; }
    std::string getConc() const { return conc; }


    void write(std::ofstream& out) override {
        out << "Physic Students\n";
        Student::write(out);
        out << "Concentration: " << conc << "\n\n";
    }
};