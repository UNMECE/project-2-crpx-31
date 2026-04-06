#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Student {
protected:
    std::string first;
    std::string last;
    double gpa;
    int gradYear;
    std::string gradSem;
    int enrollYear;
    std::string enrollSem;
    std::string level; 

public:
    Student() : first("Unknown"), last("Unknown"), gpa(0.0), 
                gradYear(0), gradSem("Unknown"), 
                enrollYear(0), enrollSem("Unknown"), level("undergrad") {}

    virtual ~Student() {}

    void setName(std::string f, std::string l) {
        first = f;
        last = l;
    }
    void setGPA(std::string g) { gpa = std::stod(g); } 
    void setGPA(double g) { gpa = g; }
    
    //setters
    void setGrad(int year, std::string sem) {
        gradYear = year;
        gradSem = sem;
    }
    void setEnroll(int year, std::string sem) {
        enrollYear = year;
        enrollSem = sem;
    }
    void setLevel(std::string l) { level = l; }

    //getters
    std::string getFirst() const { return first; }
    std::string getLast() const { return last; }
    double getGPA() const { return gpa; }

    virtual void write(std::ofstream& out) {
        out << "Name: " << first << " " << last << "\n"
            << "GPA: " << gpa << "\n"
            << "Enrolled: " << enrollSem << " " << enrollYear << "\n"
            << "Graduating: " << gradSem << " " << gradYear << "\n"
            << "Level: " << level << "\n";
    }
};