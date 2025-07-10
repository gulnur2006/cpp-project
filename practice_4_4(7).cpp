#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_MARKS = 20; 

struct Student {
    char surname_initials[50];
    int course;
    char group[20];
    int marks_session1[MAX_MARKS];
    int marks_session2[MAX_MARKS];
    int count_marks1;
    int count_marks2;
};

double calculate_average(const int marks[], int count) {
    if (count == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return static_cast<double>(sum) / count;
}

void read_students(const char* filename, Student students[], int& student_count) {
    ifstream in(filename);
    student_count = 0;

    if (!in.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return;
    }

    while (student_count < 100 && !in.eof()) { 
        Student student;
        in >> student.surname_initials >> student.course >> student.group;

        if (strlen(student.surname_initials) == 0) break; 
        student.count_marks1 = 0;
        int mark;
        while (student.count_marks1 < MAX_MARKS && in >> mark && mark != -1) {
            student.marks_session1[student.count_marks1++] = mark;
        }
                
        student.count_marks2 = 0;
        while (student.count_marks2 < MAX_MARKS && in >> mark && mark != -1) {
            student.marks_session2[student.count_marks2++] = mark;
        }

        students[student_count++] = student;
    }

    in.close();
}

void write_improved_students(const char* filename, const Student students[], int student_count) {
    ofstream out(filename);

    if (!out.is_open()) {
        cerr << "Не удалось создать файл " << filename << endl;
        return;
    }

    for (int i = 0; i < student_count; i++) {
        const Student& student = students[i];
        double avg1 = calculate_average(student.marks_session1, student.count_marks1);
        double avg2 = calculate_average(student.marks_session2, student.count_marks2);

        if (avg2 > avg1) {
            out << student.surname_initials << " " << student.course << " " << student.group << " ";
                       
            for (int j = 0; j < student.count_marks1; j++) {
                out << student.marks_session1[j] << " ";
            }
            out << "-1 ";
                        
            for (int j = 0; j < student.count_marks2; j++) {
                out << student.marks_session2[j] << " ";
            }
            out << "-1\n";
        }
    }

    out.close();
}

int main() {

    setlocale(LC_ALL, "ru");
    Student students[100]; 
    int student_count = 0;
        
    read_students("F.txt", students, student_count);
        
    write_improved_students("H.txt", students, student_count);

    cout << "Обработка завершена. Результат записан в файл H.txt" << endl;

    return 0;
}