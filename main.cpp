#include <iostream>
#include <string>

using namespace std;

struct Cliente {
    int codigo;
    string nome;
    string endereco;
};

struct Produto {
    int codigo;
    string nome;
    float preco;
};

struct Movimento {
    int codigoCliente;
    int codigoProduto;
    int quantidade;
};

const int MAX_CLIENTES = 100;
const int MAX_PRODUTOS = 100;
const int MAX_MOVIMENTOS = 100;

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Movimento movimentos[MAX_MOVIMENTOS];

int numClientes = 0;
int numProdutos = 0;
int numMovimentos = 0;

int main() {

    return 0;
}
