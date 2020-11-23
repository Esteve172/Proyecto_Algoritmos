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

 // std::istream & operator>> (std::istream &i, Datos& p)
 // {
 //     cout << "Introducir nombre, número de identificacion y si tuvo COVID-19 o no : ";
 //     i >> p.NombreC >> p.identificacion >> p.covid;
 //     i.ignore();
 //     return i;
 // }

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


// void bst::displayTree(bstNode *root, std::ostream &out) const{
//   if (root != nullptr){
//     displayTree(root->left);
//     std::cout << root->key << std::endl;
//     displayTree(root->right);
//   }
// }
//
//
// void bst::display(std::ostream &out) const{
//   displayTree(tree);
// }


typename bst::bstNode* bst::min(bstNode *root) const{
  if (root == nullptr) return nullptr;
  if (root->left == nullptr){
    return root;
  } else{
    return min(root->left);
  }
}


typename bst::bstNode* bst::max(bstNode *root) const{
  if (root == nullptr) return nullptr;
  if (root->right == nullptr){
    return root;
  } else{
    return max(root->right);
  }
}

// void bst::remove(bstNode * &root, Datos llave){
//   if (root == nullptr) return;
//   if (llave.Getidentificacion() < root->key){
//     remove(root->left, llave);
//   }
//   else if (llave.Getidentificacion() > root->key){
//      remove(root->right, llave);
//   }
//   else if (root->left == nullptr){
//     bstNode *tmp = root;
//     root = root->right;
//     delete tmp;
//     count--;
//   }
//   else if (root->right == nullptr){
//     bstNode *tmp = root;
//     root = root->left;
//     delete tmp;
//     count--;
//   }
// }

// void bst::remove(Datos llave){
//   return remove(bstNode * &root, Datos llave);
// }


#endif
