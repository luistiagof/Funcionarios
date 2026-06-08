#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
    Funcionario* proximo;
};

Funcionario* buscar(Funcionario* inicio, int prontuario) {
    Funcionario* atual = inicio;
    while (atual != nullptr) {
        if (atual->prontuario == prontuario) {
            return atual;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void inserir(Funcionario*& inicio) {
    int prontuario;
    cout << "\n--- INCLUIR FUNCIONARIO ---" << endl;
    cout << "Prontuario: ";
    cin >> prontuario;

    if (buscar(inicio, prontuario) != nullptr) {
        cout << "Erro: Prontuario ja cadastrado!" << endl;
        return;
    }

    Funcionario* novo = new Funcionario();
    novo->prontuario = prontuario;
    
    cin.ignore();
    cout << "Nome: ";
    getline(cin, novo->nome);
    
    cout << "Salario: ";
    cin >> novo->salario;

    novo->proximo = inicio;
    inicio = novo;
    cout << "Sucesso!" << endl;
}

void remover(Funcionario*& inicio) {
    cout << "\n--- EXCLUIR FUNCIONARIO ---" << endl;
    if (inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    int prontuario;
    cout << "Prontuario para excluir: ";
    cin >> prontuario;

    Funcionario* atual = inicio;
    Funcionario* anterior = nullptr;

    while (atual != nullptr && atual->prontuario != prontuario) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "Nao encontrado." << endl;
        return;
    }

    if (anterior == nullptr) {
        inicio = inicio->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    delete atual;
    cout << "Sucesso!" << endl;
}

void filtrar(Funcionario* inicio) {
    cout << "\n--- PESQUISAR FUNCIONARIO ---" << endl;
    if (inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    int prontuario;
    cout << "Prontuario: ";
    cin >> prontuario;

    Funcionario* f = buscar(inicio, prontuario);
    if (f != nullptr) {
        cout << "\nResultado:" << endl;
        cout << "Prontuario: " << f->prontuario << endl;
        cout << "Nome: " << f->nome << endl;
        cout << "Salario: R$ " << fixed << setprecision(2) << f->salario << endl;
    } else {
        cout << "Nao encontrado." << endl;
    }
}

void exibir(Funcionario* inicio) {
    cout << "\n--- LISTA ---" << endl;
    if (inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    Funcionario* atual = inicio;
    double soma = 0;

    while (atual != nullptr) {
        cout << "ID: " << atual->prontuario 
             << " | Nome: " << atual->nome 
             << " | Salario: R$ " << fixed << setprecision(2) << atual->salario << endl;
        
        soma += atual->salario;
        atual = atual->proximo;
    }

    cout << "---------------------------------------" << endl;
    cout << "Total dos Salarios: R$ " << fixed << setprecision(2) << soma << endl;
}

void limpar(Funcionario*& inicio) {
    while (inicio != nullptr) {
        Funcionario* aux = inicio;
        inicio = inicio->proximo;
        delete aux;
    }
}

int main() {
    Funcionario* lista = nullptr;
    int op;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case 1:
                inserir(lista);
                break;
            case 2:
                remover(lista);
                break;
            case 3:
                filtrar(lista);
                break;
            case 4:
                exhibir(lista);
                break;
            case 0:
                limpar(lista);
                break;
            default:
                cout << "Invalido!" << endl;
        }
    } while (op != 0);

    return 0;
}
