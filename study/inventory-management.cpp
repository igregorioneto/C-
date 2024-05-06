#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Product
    {
        string name;
        int quantity;
        float price;
    };

vector<Product> products;

void addProduct(string name, int quantity, float price, vector<Product>& products)
{
    Product p = Product();
    if (name == "" || quantity < 0 || price < 0)
    {
        cout << "Um dos valores esta faltando. (Nome, Quantidade, Preço)" << endl;
        return;
    } 
    p.name = name;
    p.quantity = quantity;
    p.price = price;
    products.push_back(p);
    cout << "\nProduto " << p.name << " adicionado com sucesso!" << endl;   
}

void getProducts()
{    
    for (Product p: products)
    {
        cout << "- " << p.name << " " << p.quantity << " unidades a R$ " << p.price << " cada." << endl;
    }    
}

void removeProductByName(string& name, vector<Product>& products)
{
    products.erase(
      remove_if(
        products.begin(),
        products.end(),
        [&name](const Product& p) { return p.name == name; }
      ),
      products.end()
    );
}

void updateQuantityProduct(int& quantity, string& name, vector<Product>& products)
{
  for(Product& p: products)
  {
    if (p.name == name)
    {
      p.quantity = quantity;
    }
  }
}

string calculateTotalStockValue(vector<Product>& products)
{
  float calc = 0;
  for (Product p: products)
  {
    calc += p.price * p.quantity;
  }
  return "Valor total: " + to_string(calc);
}

int main()
{
    /*
        Gerenciamento de Estoque:
        1. Adicionar Produto
        2. Remover Produto
        3. Atualizar Quantidade
        4. Calcular Valor Total do Estoque
        5. Exibir Todos os Produtos
        6. Sair
    */

   cout << "Gerenciamento de Estoque:" << endl;
   cout << "1. Adicionar Produto" << endl;
   cout << "2. Remover Produto" << endl;
   cout << "3. Atualizar Quantidade" << endl;
   cout << "4. Calcular Valor Total do Estoque" << endl;
   cout << "5. Exibir Todos os Produtos" << endl;
   cout << "6. Sair" << endl;

   int option;
   string name;
   int quantity;
   float price;

   while(true)
   {
      cout << "\nEscolha uma opção: ";
      cin >> option;

      if (option == 1)
      {
        cout << "Nome do Produto: ";
        cin >> name;
        cout << "Quantidade: ";
        cin >> quantity;
        cout << "Preço: ";
        cin >> price;
        addProduct(name, quantity, price, products);
        cout << "\n" << endl;
      }
      else if (option == 2)
      {
        cout << "Nome do Produto a ser removido: ";
        cin >> name;
        removeProductByName(name, products);
      }
      else if (option == 3)
      {
        cout << "Nome do Produto a ser atualizado: ";
        cin >> name;
        cout << "Quantidade a ser atualizada: ";
        cin >> quantity;
        updateQuantityProduct(quantity, name, products);
      }
      else if (option == 4)
      {
        cout << calculateTotalStockValue(products);
      }
      else if (option == 5)
      {
        cout << "Produtos no Estoque:" << endl;
        getProducts();
      }
      else if (option == 6)
      {
        cout << "Até mais!" << endl;
        break;
      }
      else
      {
        continue;
      }
        
   }

    return 0;
}
