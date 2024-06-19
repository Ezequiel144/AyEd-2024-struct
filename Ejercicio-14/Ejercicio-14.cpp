#include <iostream>
/*14) Se tiene un vector de productos (cada elemento tiene código, descripción y stock) y otro vector con
los productos recibidos de los proveedores (código, cantidad recibida), ambos ordenados por código
de producto. Se pide actualizar el stock del vector de productos.

- Vectores:
    . Productos
    . Productos recibidos de los proveedores
- struct:
    . productos{codigo, descripcion, stock}
    . productos recibidos de los proveedores{codigo, cantidad recibida}

- Se pide:
    . ordenar ambos por codigo de producto
    . actualizar el stock del vector productos
*/

using namespace std;

struct Product
{
    int code;
    string description;
    unsigned int stock;
};

struct ProductsReceived
{
    int code;
    unsigned int amount;
};

void showProductsReceived(ProductsReceived[], const int);
void showProduct(Product[], const int);
void sortProduct(Product[], const int);
void currentStockProducts(Product [], ProductsReceived [], const int);

int main()
{
    const int dim = 5;
    Product products[dim] = {{2222, "Xiaomi-redmiNote8Pro", 1}, {1111, "TvLed-Samsung42''", 4}, {3140, "Lg-phoneOne", 0}, {6777, "Ventilador", 9}, {3333, "Lavaropa", 4}};
    ProductsReceived productsSuppliers[dim] = {{1111, 5}, {1221, 10}, {3140, 2}, {5510, 3}, {6777, 1}};

    cout << "Productos actuales: " << endl;
    showProduct(products, dim);
    cout << "---------------------------------------" << endl;
    cout << "Productos recibidos por el proveedor: " << endl;
    showProductsReceived(productsSuppliers, dim);

    cout << "---------------------------------------" << endl;
    cout << "Ordenamiento de productos por su codigo: " << endl;
    sortProduct(products, dim);
    showProduct(products, dim);

    cout << "---------------------------------------" << endl;
    cout << "Actualizacion de stock: " << endl;
    currentStockProducts(products, productsSuppliers, dim);
    showProduct(products, dim);
    return 0;
}

void currentStockProducts(Product array1[], ProductsReceived array2[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (array1[i].code == array2[j].code)
            {
                array1[i].stock += array2[j].amount;
            }
        }
    }
}

void sortProduct(Product array[], const int dim)
{
    Product aux;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (array[j].code > array[i].code)
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void showProduct(Product array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Codigo -> " << array[i].code << " | Descripcion -> " << array[i].description << " | Stock -> " << array[i].stock << endl;
    }
}

void showProductsReceived(ProductsReceived array[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Codigo -> " << array[i].code << " | Cantidad -> " << array[i].amount << endl;
    }
}