#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct Cilindro{
    int p; // p é um ponto informado que junto com o centro forma o raio
    int centro = 0; // ponto central da esfera
    float pi = 3.14;

};

float raio(Cilindro *usa, float p){
    float r = usa->centro + p;
    return r;
}

float altura(Cilindro *usa, float raio){ //usa o conceito de cilindro equilatero e sua formula, usando o raio dado
    float h = raio * 2;
    return h;
}

float area_base(Cilindro *usa, float raio){ //usa a fórmula da área da base usando o campo pi da Struct Cilindro + parâmetros
    float ab = (usa->pi *(pow(raio,2)));
    return ab;
}

float area_total(Cilindro *usa, float raio, float altura){  // usa a fórmula da área total usando o campo pi da struct Cilindro + parâmetros
    float a = 2*(usa->pi)*(pow(raio,2)) + 2*(usa->pi*raio*altura);
    return a;
}

float area_lateral(Cilindro *usa, float raio, float altura){ // usa a fórmula da área lateral usando o campo pi da Struct Cilindro + parâmetros
    float al = 2*(usa->pi)*raio*altura;
    return al;
}

float volume(Cilindro *usa, float raio, float altura){ // usa a fórmula do volume usando o campo pi da struct Cilindro + parâmetros
    float v = (usa->pi*(pow(raio, 2)*altura));
    return v;
}


int main(){

    Cilindro usa;
    float op;
    // usa vai ser usando com o & para usar como referência os valores definidos na struct Esfera.

    op = raio(&usa, 6);
    cout << "raio: " << op << '\n';
    op = altura(&usa, 3);
    cout << "altura: " << op << '\n';
    op = area_base(&usa, 4);
    cout << "Área da base: " << op << '\n';
    op = area_total(&usa, 6, 9);
    cout << "Área total: " << op << '\n';
    op = area_lateral(&usa, 2, 5);
    cout << "Área lateral: " << op << '\n';
    op = volume(&usa, 4.2, 3);
    cout << "volume: " << op << '\n';

}
