//Nuria
//arbol binario
#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
     int num;
     struct Nodo *izq, *der;
};

typedef struct Nodo *_nodo;


_nodo crearNodo(int x)
{
     _nodo nuevoNodo = new(struct Nodo);
     nuevoNodo->num = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(_nodo &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->num)
          insertar(arbol->izq, x);
     else if(x > arbol->num)
          insertar(arbol->der, x);
}

void preOrden(_nodo arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->num <<".";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(_nodo arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->num << ".";
          enOrden(arbol->der);
     }
}

void postOrden(_nodo arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->num << ".";
     }
}

void verArbol(_nodo arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"-";

     cout<< arbol->num <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    _nodo arbol = NULL;   

    int n;  
    int x; 

    cout << "\n\t\t  ARBOL BINARIO  \n\n";

    cout << "Numero de nodos:";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando arbol \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del arbol";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    system("...");
    return 0;
}
