#ifndef _base_hpp_
#define _base_hpp_
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


class Datos{
private:
   std::string NombreC;
   int identificacion;
   std::string covid;

public:
  Datos();
  void SetDatos(std::string,int,std::string);
  int Getidentificacion()const;
  std::string Getnombre()const;
  std::string Getcovid()const;
  static void help();


};

bool operator<( Datos & r1,  Datos & r2);
bool operator>(Datos & r1, Datos & r2);
bool operator==(Datos & r1, Datos & r2);
std::ostream & operator<<(std::ostream &o,const Datos& p);

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
  void displayTree(bstNode *root, std::ostream &out) const;
  void SaveTree(bstNode *root, std::ofstream &ofs) const;
  void insertNode(bstNode * &root, Datos llave);
  bstNode * findNode(bstNode *root, Datos llave) const;
  bool find(Datos llave) const;
  bstNode * findNodeCedula(bstNode *root, int id) const;
  bstNode * findNodeNombre(bstNode *root, std::string a)const;

public:
  bst();
  ~bst();

  void remove(Datos llave);
  void Clear();
  void findDatos(Datos llave)const;
  Datos findCedula(int id)const;
  Datos findNombre(std::string a)const;
  void insert(Datos llave);
  int Informacion(Datos llave) const;
  void inser_cont();
  void Save(std::string nombre) const;
  void display(std::ostream &out = std::cout) const;
  static void help();
};

#include "base.cpp"
#endif
