#pragma once
#include "student.h"

class Art_Student : public Student {
private:
    std::string emphasis; //art studio, art history, or art education

public:
    Art_Student() : Student(), emphasis("Art Studio") {}
    
    ~Art_Student() {}

    void setEmphasis(std::string emp) { emphasis = emp; }
    std::string getEmphasis() const { return emphasis; }

    void write(std::ofstream& out) override {
        out << "Art Students\n";
        Student::write(out);
        out << "Emphasis: " << emphasis << "\n\n";
    }
};