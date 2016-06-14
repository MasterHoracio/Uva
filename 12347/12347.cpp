#include <cstdio>

using namespace std;

struct Arbol{
    int valor;
    Arbol *Izq = NULL;
    Arbol *Der = NULL;
};


Arbol *Insert(Arbol *A, int nodo){
    Arbol *aux = new Arbol;
    aux->valor = nodo;

    if(A == NULL)//en caso de ser el primero
        return aux;

    Arbol *ar = A, *nxt = A;//dos estructuras iguales para insertar

    while(nxt != NULL){//mientra tenga hijos
        ar = nxt;
        if(nodo > nxt->valor)//si es mayor
            nxt = nxt->Der;//nos desplazamos a la derecha
        else//si no
            nxt = nxt->Izq;//nos desplazamos a la izquierda
    }

    if(nodo > ar->valor)
        ar->Der = aux;
    else
        ar->Izq = aux;

    return A;
}

void postOrder(Arbol *root){
    if(root == NULL)
        return;
    postOrder(root->Izq);
    postOrder(root->Der);
    printf("%d\n",root->valor);
}

int main()
{
    int n;
    Arbol *a = NULL;
    while(scanf("%d",&n) && n != 0)
        a = Insert(a,n);
    postOrder(a);

    return 0;
}
