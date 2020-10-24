#ifndef _base_hpp_
#define _base_hpp_
#include <iostream>
#include <string>

// struct Datos {
//   int identificacion;
//   int resultado;
// };

class Datos{
private:
   const char* NombreC;
   int identificacion;
   const char* covid;

public:
  Datos();
  void SetDatos(const char*,int,const char*);
  const char*Getnombre();
  int Getidentificacion();
  const char* Getcovid();
};

 bool operator<( Datos & r1,  Datos & r2);
 bool operator>(Datos & r1, Datos & r2);
 bool operator==( Datos & r1, Datos & r2);
 // bool operator<<()

class bst{
  struct bstNode{
    Datos key;
    bstNode *left;
    bstNode *right;
    bstNode *parent;
  };

  size_t count;
  bstNode *tree;


  bstNode * min(bstNode *root) const;
  bstNode * max(bstNode *root) const;
  void remove(bstNode * &root, Datos llave);
  // void displayTree(bstNode *root, std::ostream &out) const;
  void insertNode(bstNode * &root, Datos llave);
  bstNode * findNode(bstNode *root, Datos llave) const;
  bstNode * findNodeCedula(bstNode *root, int id) const;

public:
  bst();
  // bst(const bst &rhs);
  ~bst();

  void remove(Datos llave);
  // bool empty(void) const;
  // void clear(void);
  bool find(Datos llave) const;
  Datos findCedula(int id)const;
  void insert(Datos llave);
  int Informacion(Datos llave) const;

  // void display(std::ostream &out = std::cout) const;
};

#include "base.cpp"
#endif
