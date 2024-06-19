#include <iostream>
/*13)Se tiene un vector de notas (cada elemento tiene nombre del alumnos y nota obtenida)
correspondientes al primer parcial y otro vector del mismo tipo del anterior con las notas
correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.
 Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la
 materia, según lo siguiente:
 - Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
 - Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
 - Primer o segundo parcial con nota menor a 6: RECURSA


- 2 vectores: vectorPrimerParcial,vectorSegundoParcial;
- Ambos vectores ordenados abfabeticamente por nombre
- Condiciones del alumno:
    . Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
    . Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
    . Primer o segundo parcial con nota menor a 6: RECURSA
*/

using namespace std;

struct Student
{
    string name;
    int note;
};

int enterDataIntoArrays(Student[], Student[], const int);
void showArrays(Student[], Student[], const int);
void sortName(Student[], Student[], const int);

int main()
{
    const int dim = 100;
    Student arrayFirstPartial[dim];
    Student arraySecondparcial[dim];
    const int arraysDim = enterDataIntoArrays(arrayFirstPartial, arraySecondparcial, dim);

    cout << "-------------------------------------------" << endl;
    cout << "Mostrando alumnos con sus notas de parcial: " << endl;
    showArrays(arrayFirstPartial, arraySecondparcial, arraysDim);

    cout << "Ordenamiento por nombre: " << endl;
    sortName(arrayFirstPartial, arraySecondparcial, arraysDim);
    showArrays(arrayFirstPartial, arraySecondparcial, arraysDim);

    cout << "Condiciones del alumno: " << endl;
    string condition;
    for (int i = 0; i < arraysDim; i++)
    {
        if (arrayFirstPartial[i].note >= 8 && arraySecondparcial[i].note >= 8)
        {
            condition = "PROMOCION";
        }
        else if (arrayFirstPartial[i].note >= 6 && arraySecondparcial[i].note >= 6)
        {
            condition = "RINDE FINAL";
        }
        else if (arrayFirstPartial[i].note < 6 || arraySecondparcial[i].note < 6)
        {
            condition = "RECURSA";
        }
        cout << "Nombre -> " << arrayFirstPartial[i].name << " -> " << condition << endl;
    }

    return 0;
}

void sortName(Student array1[], Student array2[], const int dim)
{
    Student aux;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (array1[j].name < array1[i].name)
            {
                aux = array1[j];
                array1[j] = array1[i];
                array1[i] = aux;

                aux = array2[j];
                array2[j] = array2[i];
                array2[i] = aux;
            }
        }
    }
}

void showArrays(Student array1[], Student array2[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Nombre -> " << array1[i].name << " | Primer parcial -> " << array1[i].note << " | Segundo parcial -> " << array2[i].note << endl;
    }
}

int enterDataIntoArrays(Student array1[], Student array2[], const int dim)
{
    string auxName;
    int quality = 0;
    for (int i = 0; i < dim; i++)
    {
        cout << "Nombre del alumno: ";
        cin >> auxName;
        if (auxName == "0")
        {
            break;
        }
        array1[i].name = auxName;
        array2[i].name = auxName;

        cout << "Nota del primer Parcial: ";
        cin >> array1[i].note;

        cout << "Nota del segundo Parcial: ";
        cin >> array2[i].note;
        quality++;
    }
    return quality;
}