#include <iostream>
#include <stdlib.h>

using namespace std;

struct Lista {
    int dados;
    Lista *prox = nullptr;
};

Lista* cria_lista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->prox = nullptr;
    return lista;
}

void insere_lista_dinamica(int num, int posi, Lista *lista){
    Lista *newlista = (Lista*) malloc(sizeof(Lista));
    newlista->dados = num;
    newlista->prox = nullptr;
    Lista *aux = lista;
    while(posi--){ //nao insere em 0
        aux = aux->prox;
    }
    if(aux->prox==nullptr){
        aux->prox = newlista;
    }else{
        newlista->prox = aux->prox;
        aux->prox = newlista;
    }

    return;
}

void imprime_lista(Lista *lista){
    int cont;
    Lista *newlista = lista; //newlist recebe a estrutura lista
    if(lista->prox == nullptr){
    	cout << "Lista vazia" << '\n';
    }
    while(newlista->prox != nullptr){ //vai apontando para o pr�ximo, como "decrementa��o"
        cout << newlista->prox->dados << ' '; //( ' ' )imprime lado a lado
    	newlista = newlista->prox;
    }
}

Lista* cria_matriz(int m, int n, Lista *lista){
    //Se tirar os contadores "c" da função por algum motivo o código deixa de funcionar
    int c = 0;
    int c2 = 0;

    Lista *newlista = cria_lista();

    for(int i = 0; i<m; i++){
        c = c + 1;
        cout << "Valor "<< c << ": " << '\n';
        int valor;
        cin >> valor;
        insere_lista_dinamica(valor, i, lista);
    }
    imprime_lista(lista);
    
    for(int j = 0; j<n; j++){
        c2 = c2 + 1;
        cout << "Valor "<< c2 << ": " << '\n';
        int valor2;
        cin >> valor2;
        insere_lista_dinamica(valor2, j, newlista);
    }
    imprime_lista(newlista);
    
    return lista;

}

//Lista* libera_matriz(Lista *lista){
//
//}

int main(){
    int m = 2;
    int n = 2;
    
    Lista *lista = cria_lista();
    cria_matriz(m, n, lista);

    //imprime_lista(lista);

}