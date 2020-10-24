#ifdef _base_hpp_

Datos::Datos(){
}

void Datos::SetDatos(const char* a, int b,const char* c){
  NombreC = a;
  identificacion = b;
  covid = c;
}

const char* Datos:: Getnombre(){
  return NombreC;
}

int Datos::Getidentificacion(){
  return identificacion;
}

const char* Datos:: Getcovid(){
  return covid;
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
