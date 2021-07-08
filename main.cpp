#include <iostream>
#include <vector>
#include <string>
struct Product{
std::string name;
double price;
int date;
};
template<typename T>
int hash_func(T x, int s){ //может быть подставлена любая функция хеширования
  int a=x%s;
  return a;
}
template<>
int hash_func<Product>(Product x, int s){
  int a=x.date%s;
  return a;
}
template <typename T>
struct Node{
  T data;
  Node* el=nullptr;
};
template<typename T>
class Hash{
public: int size;
         std::vector<Node<T>*> nodes;
public: Hash(int s):size(s){ nodes.resize(size);}
  void AddElement(T val){
    int f=hash_func(val,size);
    Node<T>* n1=new Node<T>;
    n1->data=val;
    if(!nodes.at(f)){nodes[f]=n1;}
    else{
        n1->el=nodes[f];
        nodes[f]=n1;
      }
}
  T* FindEl(int zn,int s){}
  void vishash(){
    for(int i=0;i<size;++i){
          Node<T>* n1=nullptr;
          std::cout<<i+1<<"  ";
        if(nodes.at(i)){
      n1=nodes.at(i);
        std::cout<<n1->data;
       while(n1->el!=nullptr){
            n1=n1->el;
            std::cout<<" -> "<<n1->data;}
       std::cout<<'\n';
          }
else
          std::cout<<"0"<<'\n';
      }
  }
};
template<>
void Hash<Product>::vishash(){
    for(int i=0;i<size;++i){
          Node<Product>* n1=nullptr;
          std::cout<<i+1<<"  ";
        if(nodes.at(i)){
      n1=nodes.at(i);
        std::cout<<"  Date:"<<n1->data.date<<"   Name:"<<n1->data.name<<"  Price:"<<n1->data.price;
       while(n1->el!=nullptr){
            n1=n1->el;
            std::cout<<" -> Date:"<<n1->data.date<<"  Name:"<<n1->data.name<<" Price:"<<n1->data.price;}
       std::cout<<'\n';
          }
else
          std::cout<<"0"<<'\n';
      }
}
template<>
Product* Hash<Product>::FindEl (int dat,int s){
  int ind=hash_func(dat,s);
  if(nodes.at(ind)->data.date==dat)
    return &(nodes.at(ind)->data);
        else{
    Product n1;
    while(nodes.at(ind)->el!=nullptr){
      n1=nodes.at(ind)->el->data;
      if(n1.date==dat)
        return &n1;
      }
}
  std::cout<<"Значения не существует";
}
void vizz(Product* pp1){
  std::cout<<'\n'<<"Название: "<<pp1->name<<'\n';
  std::cout<<"Данные : "<<pp1->date<<'\n';
  std::cout<<"Цена: "<<pp1->price<<'\n';
}
int main(){
    std::cout<<"Введите кол-во элементов"<<'\n';
  int n;
  std::cin>>n;
  Hash<Product> h1(n);
  char ch;
  int k=0;
  do{
      Product p1;
      std::cout<<"Введите название продукта"<<'\n';
      std::cin>>p1.name;
      std::cout<<"Введите цену продукта"<<'\n';
      std::cin>>p1.price;
      std::cout<<"Введите дату выпуска"<<'\n';
      std::cin>>p1.date;
      h1.AddElement(p1);
      k++;
      std::cout<<"Продолжить? Y/N\n";
      std::cin>>ch;
      if(k>n){
          std::cout<<"Хеш перегружен\n ";
          break;
        }
    }
  while(ch=='Y');
  h1.vishash();
  char dd;
 std::cout<<"Продолжить? \n";
 std::cin>>dd;
 while(dd=='Y'){
 std::cout<<"\n Какой  элемент найти?\n";
 int dat;
 std::cin>>dat;
   Product* pp1=h1.FindEl(dat,n);
    vizz(pp1);
 std::cout<<"\n Далее?\n";
 std::cin>>dd;}
}
