#include <iostream>
#include <string>
#include <vector>
#include <limits>
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
        continue;
      }
      else if (option == 3)
      {
        continue;
      }
      else if (option == 4)
      {
        continue;
      }
      else if (option == 5)
      {
        cout << "Produtos no Estoque:" << endl;
        getProducts();
      }
      else if (option == 6)
      {
        continue;
      }
      else
      {
        continue;
      }
        
   }

    return 0;
}
