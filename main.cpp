#include "base.hpp"
#include <iostream>
using namespace std;

int main(){
  bst baseDatos;
  Datos Alexa;
  Alexa.SetDatos("Alexa Gabriela Esparza Moreno", 0, "Si");
  baseDatos.insert(Alexa);
  Datos Henry;
  Henry.SetDatos("Henry Alberto Velandia Quintero", 1, "No");
  baseDatos.insert(Henry);
  Datos Miguel;
  Miguel.SetDatos("Miguel A", 3, "si");
  cout << baseDatos.find(Miguel) << endl;
  int a = 1;
  baseDatos.findCedula(a); 

  return 0;
}
