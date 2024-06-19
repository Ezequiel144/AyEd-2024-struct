#include <iostream>

/*11-8)Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
  a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
  b) Dado un código de producto informar su precio. */

using namespace std;

struct Productos
{
    int codeProduct;
    int price;
};

void showArray(Productos[], const int);
int uploadProducts(Productos[], const int);
void orderDecendents(Productos[], const int);
/* int binarySearch(Productos[], const int, int); */
int secuencial(Productos [], const int , int);

int main()
{
    const int dim = 100;
    int valueSearch;
    Productos vectProducts[dim];
    int dimArray = uploadProducts(vectProducts, dim);
    cout << "Mostrando el vector" << endl;
    showArray(vectProducts, dimArray);

    orderDecendents(vectProducts, dimArray);
    cout << "Vector ordenado por mayor a menos precio: " << endl;
    showArray(vectProducts, dimArray);

    cout << "digitar codigo de producto para buscar: ";
    /*Busqueda binaria*/
    while (cin >> valueSearch && valueSearch != 0)
    {
        int posSearchedArray = secuencial(vectProducts, dimArray, valueSearch);
        
        if (posSearchedArray != -1)
        {
            cout << "Datos" << endl;
            cout << vectProducts[posSearchedArray].codeProduct << "->" << vectProducts[posSearchedArray].price << endl;
        }
        else
        {
            cout << "El codigo que buscas no existe" << endl;
        }
        cout << "digitar codigo de producto para buscar: ";
    }

    return 0;
}

void showArray(Productos array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "codigo" << "->" << array[i].codeProduct << " precio->" << array[i].price << endl;
    }
}

int uploadProducts(Productos array[], const int dim)
{
    int cont = 0;
    int valueCode;
    for (int i = 0; i < dim; i++)
    {
        cout << "Codigo de productos: ";
        cin >> valueCode;
        if (valueCode == 0)
        {
            break;
        }
        array[i].codeProduct = valueCode;
        cout << "Precio de prodcutos: ";
        cin >> array[i].price;
        cont++;
    }
    return cont;
}

void orderDecendents(Productos array[], const int dim)
{
    Productos aux;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (array[j].price > array[i].price)
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

int secuencial(Productos array[], const int dim, int codeToSearch){
    int pos = -1;
    for (int i = 0; i < dim; i++)
    {
        if(array[i].codeProduct == codeToSearch){
            pos = i;
        }
    }
    return pos;
    
}
/* int binarySearch(Productos array[], const int dim, int codeToSearch)
{
    int pos = -1, desde = 0, hasta = dim - 1;
    int medio;
    while (desde <= hasta && pos == -1)
    {
        medio = (desde + hasta) / 2;
        cout<<"posicion media: "<<medio<<endl;
        if (array[medio].codeProduct == codeToSearch)
            pos = medio;
        else
        {
            if (codeToSearch < array[medio].codeProduct)
                hasta = medio - 1;
            else
                desde = medio + 1;
        }
    }
    return pos;
} */

/* int binarySearch(Productos array[], const int dim, int codeToSearch)
{
    int pos = -1, desde = 0, hasta = dim - 1;
    int medio;
    while (desde <= hasta && pos == -1)
    {
        medio = (desde + hasta) / 2;
        if (array[medio].codeProduct < codeToSearch)
        {
            desde = medio + 1;
        }
        else if (array[medio].codeProduct == codeToSearch)
        {
            pos = medio;
        }
        else
        {
            hasta = medio - 1;
        }
    }
    return pos;
} */