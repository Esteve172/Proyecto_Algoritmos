#include "base.hpp"
#include <iostream>
using namespace std;

int main(){
  bst baseDatos;
  string nombre;
  baseDatos.inser_cont();
  baseDatos.display();
  std::cout << "Inserte el nombre de la base de datos que desea guardar: " <<std::endl;
  std::cin >> nombre;
  baseDatos.Save(nombre + ".txt");
  // Datos Alexa;
  // Alexa.SetDatos("Alexa Gabriela Esparza Moreno", 0, "Si");
  // baseDatos.insert(Alexa);
  // Datos Henry;
  // Henry.SetDatos("Henry Alberto Velandia Quintero", 1, "No");
  // baseDatos.insert(Henry);
  // Datos Miguel;
  // Miguel.SetDatos("Miguel A", 3, "si");
  // baseDatos.findDatos(Miguel);
  // cout << Alexa << endl;
  // cout << baseDatos.findCedula(0) << endl;
  // cout << baseDatos.findNombre("Henry Alberto Velandia Quintero") << endl;
  return 0;
}
