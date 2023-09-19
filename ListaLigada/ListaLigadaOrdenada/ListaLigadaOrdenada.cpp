#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;
// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// Aloca memória dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		cout << "Erro ao alocar memória para o novo elemento.\n";
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		// Caso a lista esteja vazia, o novo nó se torna o primeiro e o último elemento
		primeiro = novo;
		ultimo = primeiro;
		cout << "Elemento inserido com sucesso.\n";
	}
	else if (novo->valor < primeiro->valor)
	{
		// Caso o novo nó seja menor que o primeiro elemento, insere no início
		novo->prox = primeiro;
		primeiro = novo;
		cout << "Elemento inserido com sucesso.\n";
	}
	else
	{
		NO* anterior = NULL;
		NO* atual = primeiro;

		// Encontra a posição correta para inserção mantendo a ordem
		while (atual != NULL && novo->valor > atual->valor)
		{
			anterior = atual;
			atual = atual->prox;
		}

		// Verifica se o elemento já existe na lista
		if (atual != NULL && novo->valor == atual->valor)
		{
			cout << "Elemento ja existe na lista. Nao foi inserido.\n";
			free(novo); // Libera a memória alocada para o novo nó
			return;
		}

		// Insere o novo nó na posição correta
		anterior->prox = novo;
		novo->prox = atual;
		if (atual == NULL)
			ultimo = novo;

		cout << "Elemento inserido com sucesso.\n";
	}
}


void excluirElemento()
{
	NO* excluir = NULL;
	int elemento;
	cout << "Qual elemento deseja excluir? " << endl;
	cin >> elemento;

	NO* aux = primeiro;
	// Verificando se o elemento a excluir é o primeiro da lista
	if (aux == primeiro && aux->valor == elemento) {
		excluir = aux;
		primeiro = aux->prox;
	}
	// Senão percorremos a lista para acha-lo, o anterior e o proximo
	else {
		NO* ant = primeiro;
		while (aux != NULL) {
			if (aux->valor == elemento) {
				excluir = aux;
				ant->prox = excluir->prox;
			}
			ant = aux;
			aux = aux->prox;
		}
	}

	if (excluir) {
		free(excluir);
		cout << "Elemento excluido com sucesso! \n";
	}
	else {
		cout << "Elemento nao encontrado!\n";
	}



}

void buscarElemento()
{
	int elemento, busca = 0;
	cout << "Digite o valor que deseja buscar: " << endl;
	cin >> elemento;

	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == elemento) {
			//cout << "Elemento encontrado!" << endl;
			busca = 1;
			break;
		}
		aux = aux->prox;
	}
	if (busca == 1) {
		cout << "Elemento encontrado!" << endl;
	}
	else {
		cout << "Elemento nao encontrado na lista!" << endl;
	}

}