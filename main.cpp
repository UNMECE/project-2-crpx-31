#include <iostream>
#include <vector>
#include <string>

#include "art_student.h"
#include "physics_student.h"

int main() {
    //vec ptrs for poly
    std::vector<Art_Student*> art_students;
    std::vector<Physics_Student*> physics_students;

    //Vietnamese names
    std::string art_first[] = {"Minh", "Lan", "Tuan", "Hoa", "Khoa"};
    std::string art_last[] = {"Nguyen", "Tran", "Le", "Pham", "Hoang"};
    
    std::string phys_first[] = {"Duc", "Thao", "Mai", "Son", "Linh"};
    std::string phys_last[] = {"Phan", "Vu", "Dang", "Bui", "Do"};

    //art students
    for (int i = 0; i < 5; i++) {
        art_students.push_back(new Art_Student);
        
        //set base members
        art_students[i]->setName(art_first[i], art_last[i]);
        art_students[i]->setGPA(3.5 + (i * 0.1));
        art_students[i]->setEnroll(2021, "Fall");
        art_students[i]->setGrad(2025, "Spring");
        
        //mix level
        if (i % 2 == 0) art_students[i]->setLevel("undergrad");
        else art_students[i]->setLevel("grad");
        
        //distribute emph % 3
        if (i % 3 == 0) art_students[i]->setEmphasis("Art Studio");
        else if (i % 3 == 1) art_students[i]->setEmphasis("Art History");
        else art_students[i]->setEmphasis("Art Education");
    }

    //physic students:
    for (int i = 0; i < 5; i++) {
        physics_students.push_back(new Physics_Student);
        
        physics_students[i]->setName(phys_first[i], phys_last[i]);
        physics_students[i]->setGPA(3.6 + (i * 0.05));
        physics_students[i]->setEnroll(2022, "Spring");
        physics_students[i]->setGrad(2026, "Spring");
        
        if (i % 2 == 0) physics_students[i]->setLevel("undergrad");
        else physics_students[i]->setLevel("grad");
        
        //toggle conc
        if (i % 2 == 0) physics_students[i]->setConc("Biophysics");
        else physics_students[i]->setConc("Earth and Planetary Sciences");
    }

    //dump to file
    std::ofstream outfile("student_info.dat");
    
    if (outfile.is_open()) {
        //stl iterator over vec
        for (std::vector<Art_Student*>::iterator it = art_students.begin(); it != art_students.end(); ++it) {
            (*it)->write(outfile);
        }
        
        for (std::vector<Physics_Student*>::iterator it = physics_students.begin(); it != physics_students.end(); ++it) {
            (*it)->write(outfile);
        }
        
        outfile.close();
        std::cout << "code run successfully" << std::endl;
    }

    //free mem
    for (size_t i = 0; i < art_students.size(); i++) {
        delete art_students[i];
    }
    for (size_t i = 0; i < physics_students.size(); i++) {
        delete physics_students[i];
    }

    return 0;
}