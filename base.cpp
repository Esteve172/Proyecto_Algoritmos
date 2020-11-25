#ifdef _base_hpp_

Datos::Datos(){
}

void Datos::SetDatos(std::string a, int b,std::string c){
  NombreC = a;
  identificacion = b;
  covid = c;
}

std::string Datos::Getnombre()const{
  return NombreC;
}

std::string Datos::Getcovid()const{
  return covid;
}

int Datos::Getidentificacion()const{
  return identificacion;
}

bst::bst(){
  tree = nullptr;
  count = 0;
}

bst::~bst(){
}

 bool operator<(Datos &r1,  Datos &r2){
    return r1.Getidentificacion() < r2.Getidentificacion();
 }

 bool operator>( Datos &r1,Datos &r2){
   return r1.Getidentificacion() > r2.Getidentificacion();
 }

 bool operator==( Datos &r1, Datos &r2){
   return r1.Getidentificacion() == r2.Getidentificacion();
 }

 std::ostream & operator<<(std::ostream &o,const Datos& p){
     o << "(IDENTIFICACION: " << p.Getidentificacion() << ", NOMBRE: " << p.Getnombre() << ", TUVO COVID: " << p.Getcovid() << ")";
     return o;
 }

void Datos::help(){
  std::cout << "Estos son las siguientes funciones que tienes disponibles en la clase DATOS:"<< std::endl;
  std::cout <<"SetDatos: Crear un objeto tipo datos, ingresando sus 3 valores (Nombre, identificacion, covid)."<< std::endl;
  std::cout <<"Getnombre: Acceder al nombre de un objeto tipo datos."<< std::endl;
  std::cout <<"Getidentificacion: Acceder a la identificacion de un objeto tipo datos."<< std::endl;
  std::cout <<"Getcovid: Acceder a la Informacion que si tuvo COVID-19 o no."<< std::endl;
}

void bst::insertNode(bstNode * & t, Datos llave){
  if (t == nullptr){
    t = new bstNode;
    t->key = llave;
    t->left = t-> right = nullptr;
    count++;
  }
  else{
    if (llave < t->key){
      insertNode(t->left, llave);
    }
    else{
      insertNode(t->right, llave);
    }
  }
}

void bst::insert(Datos llave){
  insertNode(tree, llave);
}


bst::bstNode* bst::findNode(bstNode *t, Datos llave) const{
  if (t == nullptr) return nullptr;
  if (llave == t->key) return t;
  if (llave < t->key){
    return findNode(t->left, llave);
  } else{
    return findNode(t->right, llave);
  }
}

bool bst::find(Datos llave) const{
  return findNode(tree, llave)!= nullptr;
}

void bst::findDatos(Datos llave)const{
  bool a = find(llave);
  if (a == 0){
    std::cout << "No se encuentra en el BST" << std::endl;
  }
  else{
    std::cout << "Se encuentra en el BST" << std::endl;
  }
}


bst::bstNode* bst::findNodeCedula(bstNode *t, int id) const{
  if (t == nullptr) return nullptr;
  if (id == t->key.Getidentificacion()) return t;
  if (id < t->key.Getidentificacion()){
    return findNodeCedula(t->left, id);
  } else{
    return findNodeCedula(t->right, id);
  }
}


Datos bst::findCedula(int id) const{
  bstNode* a =findNodeCedula(tree, id);
  if (a == nullptr){
    Datos b;
    return b;
  }else{
    return a->key;
  }
}

bst::bstNode* bst::findNodeNombre(bstNode *t, std::string a) const{
  if (t == nullptr) return nullptr;
  if (a == t->key.Getnombre()) return t;
  if (a < t->key.Getnombre()){
    return findNodeNombre(t->left, a);
  } else{
    return findNodeNombre(t->right, a);
  }
}


Datos bst::findNombre(std::string a) const{
  bstNode* c =findNodeNombre(tree, a);
  if (c == nullptr){
    Datos b;
    return b;
  }else{
    return c->key;
  }
}

void bst::displayTree(bstNode *root, std::ostream &out) const{
  if (root == nullptr){
    // throw std::runtime_error("No hay nada que imrpimir");
}else{
    std::cout << root->key << "\n";
    displayTree(root->left,out);
    displayTree(root->right,out);
  }
}

void bst::display(std::ostream &out) const{
  displayTree(tree, out);
}


bst::bstNode* bst::min(bstNode *root) const{
  if (root == nullptr) return nullptr;
  if (root->left == nullptr){
    return root;
  } else{
    return min(root->left);
  }
}


bst::bstNode* bst::max(bstNode *root) const{
  if (root == nullptr) return nullptr;
  if (root->right == nullptr){
    return root;
  } else{
    return max(root->right);
  }
}

void bst::remove(bstNode * &root, Datos llave){
   if (root == nullptr) throw std::runtime_error("No hay nada que borrar");
   if (llave.Getidentificacion() < root->key.Getidentificacion()){
     remove(root->left, llave);
   }
   else if (llave.Getidentificacion() > root->key.Getidentificacion()){
      remove(root->right, llave);
   }
   else if (root->left == nullptr){
     bstNode *tmp = root;
     root = root->right;
     delete tmp;
     count--;
   }
   else if (root->right == nullptr){
     bstNode *tmp = root;
     root = root->left;
     delete tmp;
     count--;
   }
 }

void bst::remove(Datos llave){
   remove(tree, llave);
}

void bst::clear(){
  count = 0;
}

void bst::help(){
  std::cout << "Estos son las siguientes funciones que tienes disponibles en la clase BST:"<< std::endl;
  std::cout << "Insert: Insertar un nodo en el BST"<< std::endl;
  std::cout << "findDatos: Buscar un objeto de tipo Datos en el BST"<< std::endl;
  std::cout << "findCedula: Buscar un objeto de tipo Datos con el valor de la identificacion en el BST"<< std::endl;
  std::cout << "findNombre: Buscar un objeto de tipo Datos con el valor del nombre en el BST"<< std::endl;
  std::cout << "display: Imprimir el BST"<< std::endl;
  std::cout << "min: Retorna el objeto de tipo Datos minimo"<< std::endl;
  std::cout << "max: Retorna el objeto de tipo Datos maximo"<< std::endl;
  std::cout << "remove: Remover un objeto de tipo Datos del BST"<< std::endl;
  std::cout << "clear: Limpiar el BST"<< std::endl;
}

// void bst::inser_cont(){
//   std::string a;
//   int b;
//   std::string c;
//   std::cout << "Inserte el nombre clave de la tupla, Si desea terminar ponga: Cerrar " << '\n';
//   std::cout << "Inserte Nombre: " << '\n';
//   std::cin >> a;
//   std::cout << "Inserte N_Identificacion (Precaucion no ponga numeros mayores de 9 digitos): " << '\n';
//   std::cin >> b;
//   std::cout << "Inserte Resultado Covid: " << '\n';
//   std::cin >> c;
//
//   while (a != "Cerrar") {
//     Datos nuevo;
//     nuevo.SetDatos(a, b, c);
//     insert(nuevo);
//     std::cout << "Inserte Nombre: " << '\n';
//     std::cin >> a;
//     if (a != "Cerrar") {
//       std::cout << "Inserte N_Identificacion: " << '\n';
//       std::cin >> b;
//       std::cout << "Inserte Resultado Covid: " << '\n';
//       std::cin >> c;
//     } else {
//       std::cout << "Se ha detenido el proceso de insercion" << '\n';
//     }
//   }
//  }

void bst::SaveTree(bstNode *root, std::ofstream &ofs) const{
  if (root == nullptr){
    //throw std::runtime_error("No hay nada que guardar");
}else{
    ofs << root->key << "\n";
    SaveTree(root->left,ofs);
    SaveTree(root->right,ofs);
  }
}

void bst::Save(std::string nombre) const{
  std::ofstream ofs(nombre, std::ios::out);
  if (ofs.good()) {
    std::cout << "Guardando Base de Datos al archivo: " << nombre << std::endl;
  }
  SaveTree(tree, ofs);
  ofs.close();
}

void ReadTree(bstNode * &root, std::istream &txt) const{
  std::cout << "Ingrese el nombre que desea darle al arbol: " << '\n';
  std::cin >> namebst;
  bst namebst;
  ifs.open("txt");
  if (ifs.good()) {
    while (!ifs.eof()) {
      getline(ifs, line);
      //Datos dtxt = std::cin >> line; es uno de esos dos // dtxt >> line;
      namebst.insert(dtxt);
    }
  }
}

void Read(std::string txt) const{

}


void bst::inser_cont(){
  int a;
  std::cout << "Hola! ¿Desea crear una nueva BST o ya tiene una guarada? Responda 0 si quiere crear una o 1 si ya tiene una creada"<< std::endl;
  std::cin>> a;
  if (a == 0){
    int b;
    bst BaseDatos;
    std::cout << "Su bst ha sido creado, ¿desea guardar un elemento? Responda 0 si si o 1 si no" << std::endl;
    std::cin>> b;
    if (b == 0){
        std::string c;
        int d;
        std::string e;
        std::cout << "Inserte el nombre clave de la tupla, Si desea terminar ponga: Cerrar " << '\n';
        std::cout << "Inserte Nombre: " << '\n';
        std::cin >> c;
        std::cout << "Inserte N_Identificacion (Precaucion no ponga numeros mayores de 9 digitos): " << '\n';
        std::cin >> d;
        std::cout << "Inserte Resultado Covid: " << '\n';
        std::cin >> e;

        while (c || e != "Cerrar") {
          Datos nuevo;
          nuevo.SetDatos(c, d, e);
          BaseDatos.insert(nuevo);
          std::cout << "Inserte Nombre: " << '\n';
          std::cin >> c;
          if (c != "Cerrar") {
            std::cout << "Inserte N_Identificacion: " << '\n';
            std::cin >> d;
            std::cout << "Inserte Resultado Covid: " << '\n';
            std::cin >> e;
          } else {
            int g;
            int h;
            std::cout << "Se ha detenido el proceso de insercion" << '\n';
            std::cout << "¿Desea ver los datos que almaceno? Responda 0 si si o 1 si no" << '\n';
            std::cin>>h;
            if (h == 0){
              BaseDatos.display();
            }
            std::cout << "¿Desea guardar el bst en un txt? Responda 0 si si o 1 si no" << '\n';
            std::cin>>g;
            if(g == 0){
              std::string x;
              std::cout << "¿Como quiere que se llame su .txt?" << '\n';
              std::cin >> x;
              BaseDatos.Save(x + ".txt");
            }else {
              return;
            }
          }
        }
    }else{
      int f;
      std::cout <<"¿Desea guardar el bst en un txt? Responda 0 si si o 1 si no" << std::endl;
      std::cin>> f;
      if (f == 0){
        std::string x;
        std::cout << "¿Como quiere que se llame su .txt?" << '\n';
        std::cin >> x;
        BaseDatos.Save(x + ".txt");
      }else {
        return;
      }
    }

  }else{
    //abrir un txt
    int h;
    std::cout <<"¿Qué desea hacer? Responda con un numero" << std::endl;
    std::cout <<"1. Insertar objetos" << std::endl;
    std::cout <<"2. Buscar un objeto" << std::endl;
    std::cout <<"3. Borrar un objeto" << std::endl;
    std::cout <<"4. Limpiar el arbol" << std::endl;
    std::cin>> h;
    if (h == 1){
        std::string c;
        int d;
        std::string e;
        std::cout << "Inserte el nombre clave de la tupla, Si desea terminar ponga: Cerrar " << '\n';
        std::cout << "Inserte Nombre: " << '\n';
        std::cin >> c;
        std::cout << "Inserte N_Identificacion (Precaucion no ponga numeros mayores de 9 digitos): " << '\n';
        std::cin >> d;
        std::cout << "Inserte Resultado Covid: " << '\n';
        std::cin >> e;

        while (c || e != "Cerrar") {
          Datos nuevo;
          //(nombre del bst).SetDatos(c, d, e);
          BaseDatos.insert(nuevo);
          std::cout << "Inserte Nombre: " << '\n';
          std::cin >> c;
          if (c != "Cerrar") {
            std::cout << "Inserte N_Identificacion: " << '\n';
            std::cin >> d;
            std::cout << "Inserte Resultado Covid: " << '\n';
            std::cin >> e;
          } else {
            int g;
            int h;
            std::cout << "Se ha detenido el proceso de insercion" << '\n';
            std::cout << "¿Desea ver los datos que almaceno? Responda 0 si si o 1 si no" << '\n';
            std::cin>>h;
            if (h == 0){
              //(nombre del bst).display();
            }
            std::cout << "¿Desea guardar el bst en un txt? Responda 0 si si o 1 si no" << '\n';
            std::cin>>g;
            if(g == 0){
              //(nombre del bst).display();
            }else {
              return;
            }
          }
        }
    }
    if else (h == 2){
        int j;
        std::cout << "¿Desea buscar el objeto por nombre (1) o identificacion(0)?" << '\n';
        std::cin>> j;
        if (j=1){
          std::string k;
          std::std::cout << "Ingrese el nombre" << '\n';
          std::cin >> k;
          // (nombre del bst).findNombre(k);
        } else{
          int l;
          std::cout << "Ingrese el numero de identificacion" << '\n';
          std::cin>> l;
          // (nombre del bst).findCedula(l);
        }
      }
      if else (h==3){
        Datos a;
        std::string c;
        int d;
        std::string e;
        std::cout << "Ingrese los valores del objeto tipo DATOS que quire remover" << '\n';
        std::cout << "Inserte Nombre: " << '\n';
        std::cin >> c;
        std::cout << "Inserte N_Identificacion (Precaucion no ponga numeros mayores de 9 digitos): " << '\n';
        std::cin >> d;
        std::cout << "Inserte Resultado Covid: " << '\n';
        std::cin >> e;
        a.SetDatos(c,d,e);
        // (nombre del bst).remove(a);
      }
      if else (h==4){
        int v;
        std::cout << "¿Esta seguro de limpiar el BST? Responda 0 si si o 1 si no" << '\n';
        std::cin >> v;
        if (v == 0){
          // (nombre del bst).clear;
        } return;
      }
      int p;
      std::cout << "¿Desea guardar los cambios en un nuevo txt? Responda 0 si si, 1 si no" << '\n';
      std::cin >> p;
      if (p == 0){
        std::string x;
        std::cout << "¿Como quiere que se llame su .txt?" << '\n';
        std::cin >> x;
        //(nombre del bst).Save(x + ".txt");
      }else{
        std::cout << "Hasta luego" << '\n';
        return;
      }
    }

  }

#endif
