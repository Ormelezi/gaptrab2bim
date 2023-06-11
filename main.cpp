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

void cadastrarCliente() {
    if (numClientes < MAX_CLIENTES) {
        Cliente novoCliente;
        cout << "Código do cliente: ";
        cin >> novoCliente.codigo;
        cout << "Nome do cliente: ";
        cin.ignore();
        getline(cin, novoCliente.nome);
        cout << "Endereço do cliente: ";
        getline(cin, novoCliente.endereco);

        clientes[numClientes] = novoCliente;
        numClientes++;

        cout << "Cliente cadastrado com sucesso." << endl;
    } else {
        cout << "Não é possível cadastrar mais clientes." << endl;
    }
}

void cadastrarProduto() {
    if (numProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        cout << "Código do produto: ";
        cin >> novoProduto.codigo;
        cout << "Nome do produto: ";
        cin.ignore();
        getline(cin, novoProduto.nome);
        cout << "Preço do produto: ";
        cin >> novoProduto.preco;

        produtos[numProdutos] = novoProduto;
        numProdutos++;

        cout << "Produto adicionado ao estoque com sucesso." << endl;
    } else {
        cout << "Não é possível adicionador mais produtos ao estoque." << endl;
    }
}

void realizarMovimento() {
    if (numClientes == 0 || numProdutos == 0) {
        cout << "Não há clientes ou produtos cadastrados." << endl;
        return;
    }

    if (numMovimentos < MAX_MOVIMENTOS) {
        Movimento novoMovimento;
        cout << "Código do cliente: ";
        cin >> novoMovimento.codigoCliente;
        cout << "Código do produto: ";
        cin >> novoMovimento.codigoProduto;
        cout << "Quantidade: ";
        cin >> novoMovimento.quantidade;

        // Verificar se o cliente e o produto existem
        bool clienteEncontrado = false;
        bool produtoEncontrado = false;
        for (int i = 0; i < numClientes; i++) {
            if (clientes[i].codigo == novoMovimento.codigoCliente) {
                clienteEncontrado = true;
                break;
            }
        }
        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == novoMovimento.codigoProduto) {
                produtoEncontrado = true;
                break;
            }
        }

        if (!clienteEncontrado) {
            cout << "Cliente não encontrado." << endl;
            return;
        }
        if (!produtoEncontrado) {
            cout << "Produto não encontrado." << endl;
            return;
        }

        movimentos[numMovimentos] = novoMovimento;
        numMovimentos++;

        cout << "Venda realizada com sucesso." << endl;

        // Excluir o produto vendido do estoque
        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == novoMovimento.codigoProduto) {
                produtos[i] = produtos[numProdutos - 1];
                numProdutos--;
                break;
            }
        }
    } else {
        cout << "Não é possível realizar mais vendas." << endl;
    }
}

void mostrarClientes() {
    if (numClientes == 0) {
        cout << endl << ".........Nenhuma cliente cadastrado........." << endl;
    } else {
        cout << endl << "Clientes cadastrados:" << endl;
        for (int i = 0; i < numClientes; i++) {
            cout << "Código: " << clientes[i].codigo << endl;
            cout << "Nome: " << clientes[i].nome << endl;
            cout << "Endereço: " << clientes[i].endereco << endl;
            cout << endl;
        }
    }
}

void mostrarProdutos() {
    if (numProdutos == 0) {
        cout << endl << ".........Nenhuma produto cadastrado........." << endl;
    } else {
        cout << endl << "Produtos no estoque:" << endl;
        for (int i = 0; i < numProdutos; i++) {
            cout << "Código: " << produtos[i].codigo << endl;
            cout << "Nome: " << produtos[i].nome << endl;
            cout << "Preço: " << produtos[i].preco << endl;
            cout << endl;
        }
    }
}

void mostrarMovimentos() {
    if (numMovimentos == 0) {
        cout << endl << ".........Nenhuma venda realizada........." << endl;
    } else {
        cout << endl << "vendas realizados:" << endl;
        for (int i = 0; i < numMovimentos; i++) {
            cout << "Código do cliente: " << movimentos[i].codigoCliente << endl;
            cout << "Código do produto: " << movimentos[i].codigoProduto << endl;
            cout << "Quantidade: " << movimentos[i].quantidade << endl;
            cout << endl;
        }
    }
}

int main() {

    return 0;
}
