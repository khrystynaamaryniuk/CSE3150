
#include <iostream>
#include "simple_student.h"
#include <vector>

int main() {
    using namespace std;
    student one_student = get_student_struct_data();
    output_student_data(one_student);
    student other_student = one_student;
    other_student.name="Other name";
    other_student.hw_grades[0]=10;
    output_student_data(other_student);
    output_student_data(one_student);
    return 0;
}