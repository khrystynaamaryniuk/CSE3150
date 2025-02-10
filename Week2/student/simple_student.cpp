#include "simple_student.h"
#include <vector>
#include <iostream> 

student get_student_struct_data() {
    student s; // allocating on stack
    cout << "Enter the student's name: ";
    cin >> s.name;

    cout << "Enter the student's midterm: ";
    cin >> s.midterm;

    cout << "Enter the student's final: ";
    cin >> s.final;
    cout << "Enter a homework score (^D to exit): ";
    int score;
    while(cin >> score) {
    cout << "Enter a homework score (^D to exit): ";
    s.hw_grades.push_back(score);
    }
    return s; //deallocating 
}
void output_student_data(student st){
    cout <<"Summary "<<endl;
    cout <<"Student's name: "<< st.name
        << ", student's midterm: "
        << st.midterm
        << ", student's final: "
        << st.final
        << endl;
    cout << "homeworks: "<< endl;
    for (auto grade: st.hw_grades) {
        cout << grade << endl;
        }

}