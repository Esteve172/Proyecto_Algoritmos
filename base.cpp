#ifdef _base_hpp_

Datos::Datos(){
}

void Datos::SetDatos(std::string a, int b,std::string c){
  NombreC = a;
  identificacion = b;
  covid = c;
}

void Datos::help(){
  std::cout << "Estos son las siguientes funciones que tienes disponibles en la clase DATOS:"<< std::endl;
  std::cout <<"SetDatos: Crear un objeto tipo datos, ingresando sus 3 valores (Nombre, identificacion, covid)."<< std::endl;
  std::cout <<"Getnombre: Acceder al nombre de un objeto tipo datos."<< std::endl;
  std::cout <<"Getidentificacion: Acceder a la identificacion de un objeto tipo datos."<< std::endl;
  std::cout <<"Getcovid: Acceder a la Informacion que si tuvo COVID-19 o no."<< std::endl;
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
     o << "(IDENTIFICACION:" << p.Getidentificacion() << ", NOMBRE:" << p.Getnombre() << ", TUVO COVID:" << p.Getcovid() << ")";
     return o;
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
    std::cout << llave << " No se encuentra en el BST" << std::endl;
  }
  else{
    std::cout << llave << " Se encuentra en el BST" << std::endl;
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

void bst::Clear() {
  tree = nullptr;
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

void bst::inser_cont(){
  std::string a;
  int b;
  std::string c;
  std::cout << "Inserte el nombre clave de la tupla, Si desea terminar ponga: Cerrar " << '\n';
  std::cout << "Inserte Nombre: " << '\n';
  std::cin >> a;
  if (a != "Cerrar") {
    std::cout << "Inserte N_Identificacion (Precaucion no ponga numeros mayores de 9 digitos): " << '\n';
    std::cin >> b;
    std::cout << "Inserte Resultado Covid: " << '\n';
    std::cin >> c;
  }

  while (a != "Cerrar") {
    Datos nuevo;
    nuevo.SetDatos(a, b, c);
    insert(nuevo);
    std::cout << "Inserte Nombre: " << '\n';
    std::cin >> a;
    if (a != "Cerrar") {
      std::cout << "Inserte N_Identificacion: " << '\n';
      std::cin >> b;
      std::cout << "Inserte Resultado Covid: " << '\n';
      std::cin >> c;
    } else {
      std::cout << "Se ha detenido el proceso de insercion" << '\n';
    }
  }
}

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

#endif
