#include "base.hpp"
#include <iostream>
using namespace std;

int main(){
  int SeleccionDeTest;
  std::cout << "Elija 0 para un ejemplo preparado, 1 para introducir una base datos nueva o introducir cualquier otro numero para cerrar el programa." << '\n';
  std::cin >> SeleccionDeTest;

  if (SeleccionDeTest == 0) {
    bst baseDatos;

    std::cout << " " << '\n';

    std::cout << "Vamos a demostrar la insercion y visualizacion de datos..." << '\n';

    Datos Alexa;
    Alexa.SetDatos("Alexa Gabriela Esparza Moreno", 548672415, "Si");
    baseDatos.insert(Alexa);

    Datos Henry;
    Henry.SetDatos("Henry Alberto Velandia Quintero", 750924408, "No");
    baseDatos.insert(Henry);

    Datos Miguel;
    Miguel.SetDatos("Miguel Angel Gautier", 983793881, "Si");
    baseDatos.insert(Miguel);

    Datos Victor;
    Victor.SetDatos("Victor Manuel Marquez Cifuentes", 357277763, "Si");
    baseDatos.insert(Victor);

    Datos Mario;
    Mario.SetDatos("Mario Andres Lozano", 744067945, "Si");
    baseDatos.insert(Mario);

    Datos Zara;
    Zara.SetDatos("Zara Milena Londono", 892206681, "Si");
    baseDatos.insert(Zara);

    std::cout << " " << '\n';

    std::cout << "Vamos a visualizar el arbol con los datos introducidos" << '\n';
    baseDatos.display();

    std::cout << " " << '\n';

    std::cout << "Vamos a demostrar la busqueda y eliminacion de datos..." << '\n';

    std::cout << " " << '\n';

    cout << "Vamosa buscar a Henry por su nombre completo en la base de datos: " << "Buscamos Henry Alberto Velandia Quintero... " << baseDatos.findNombre("Henry Alberto Velandia Quintero") << endl;

    std::cout << " " << '\n';

    std::cout << "Vamosa Buscar a Zara por su cedula: " << "Buscamos 892206681... "<< baseDatos.findCedula(892206681) << endl;

    std::cout << " " << '\n';

    std::cout << "Vamos a Buscar a Miguel por el nombre de su Dato: " << "Buscamos Miguel... "; baseDatos.findDatos(Miguel);

    std::cout << " " << '\n';

    std::cout << "Vamos a eliminar a Victor"<<'\n'; baseDatos.remove(Victor);

    std::cout << "Visualizamos la base de datos con cambios: " << '\n'; baseDatos.display();

    std::cout << " " << '\n';

    std::cout << "Vamos a limpiar el arbol" << '\n'; baseDatos.Clear();

    std::cout << " " << '\n';

    std::cout << "Se vizualiza la base de datos a sido eliminada " << '\n'; baseDatos.display();

    std::cout << " " << '\n';

  }
  if (SeleccionDeTest == 1) {
    bst baseDatos;
    baseDatos.inser_cont();
    baseDatos.display();
    string elec;
    std::cout << "Desea guardar los datos introducidos? Y/N" << '\n';
    std::cin >> elec;

    if (elec == "Y") {
      string nombre;
      std::cout << "Inserte el nombre de la base de datos que desea guardar: " <<std::endl;
      std::cin >> nombre;
      baseDatos.Save(nombre + ".txt");
      std::cout << " " << '\n';
      std::cout << "Gracias por probar el programa" << '\n';
    }
    if (elec == "N") {
      std::cout << "No se guardaron los datos introducidos" << '\n';
      std::cout << " " << '\n';
      std::cout << "Gracias por probar el programa" << '\n';
    }
  }
  return 0;
 }
