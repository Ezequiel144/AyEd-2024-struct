#include <iostream>

/*12.9) Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota. */

using namespace std;

struct Student
{
    int document;
    int note;
};

void showArray(Student[], const int);
int uploadStudents(Student[], const int);
void lessNote(Student [], const int);
void highestGrade(Student [], const int);

int main()
{
    const int dim = 100;
    Student arrayStudent[dim];

    int dimArray = uploadStudents(arrayStudent, dim);

    cout << "Mostrando alumnos y sus notas: " << endl;
    showArray(arrayStudent, dimArray);

    cout << "Alumnos con mayor nota: " << endl;
    highestGrade(arrayStudent, dimArray);

    cout<< "Alumnos con menor nota: "<<endl;
    lessNote(arrayStudent, dimArray);
    return 0;
}

void highestGrade(Student array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if (array[i].note >= 6)
        {
            cout << "Documento -> " << array[i].document << " Nota -> " << array[i].note << endl;
        }
    }
}

void lessNote(Student array[], const int dim){
    for (int i = 0; i < dim; i++)
    {
        if (array[i].note < 6)
        {
            cout << "Documento -> " << array[i].document << " Nota -> " << array[i].note << endl;
        }
    }
}

void showArray(Student array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Documento" << " -> " << array[i].document << " Nota -> " << array[i].note << endl;
    }
}

int uploadStudents(Student array[], const int dim)
{
    int auxDocum;
    int contDim = 0;
    for (int i = 0; i < dim; i++)
    {
        cout << "Documento de estudiante: ";
        cin >> auxDocum;
        if (auxDocum == 0)
        {
            break;
        }
        array[i].document = auxDocum;
        cout << "Nota: ";
        cin >> array[i].note;
        contDim++;
    }
    return contDim;
}