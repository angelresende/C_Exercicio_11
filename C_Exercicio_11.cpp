#include <iostream>
#include <locale.h>
#include <stdlib.h> // system
#include <string> // Textos em geral

using namespace std;

// Dados sobre o Medicamento
struct Medicamento {
	int CodMedicamento;
	string NomeMedicamento;
	string NomeLaboratorio;
	string PrincipioAtivo;
	double PrecoCompra;
	double PrecoVenda;
	int MesValidade;
	int AnoValidade;
};

// Estrutura do Nó
struct No {
	Medicamento medicamento; // estrutura guardada dentro da lista
	No* proxNo; // aponta para o próximo Nó da lista
};

// Nó início da lista
struct ListaMed {
	No* inicio;
};

ListaMed* CriarListaMed();

void LiberarListaMed(ListaMed* ptrListaMed);

bool InserirListaMedInicio(ListaMed* ptrListaMed, int CodMedicamento, string NomeMedicamento, string NomeLaboratorio, string PrincipioAtivo, double PrecoCompra, double PrecoVenda, int MesValidade, int AnoValidade);

void BuscarPrincipioAtivo(ListaMed* ptrListaMed, string PrincipioAtivo);
void BuscarMaiorMenor(ListaMed* ptrListaMed);
void VerificarVencimento(ListaMed* ptrListaMed);

//--------------------------------------------------------
// MAIN
//--------------------------------------------------------
int main() {
	setlocale(LC_ALL, "Portuguese");
	ListaMed* pListaMed;
	pListaMed = CriarListaMed();

	InserirListaMedInicio(pListaMed, 90018036, "ATENOL", "AUROBINDO PHARMA", "ATENOLOL", 25.36, 39.75, 9, 2020);
	InserirListaMedInicio(pListaMed, 90295919, "AMOXIL", "CIFARMA CIENTIFICA", "AMOXICILINA", 12.33, 23.99, 12, 2020);
	InserirListaMedInicio(pListaMed, 97078, "VELAMOX", "EMS", "AMOXICILINA", 12.33, 35.69, 10, 2020);
	InserirListaMedInicio(pListaMed, 90295698, "ARADOIS", "BIOLAB", "LOSARTANA POTASSICA", 15.99, 54.99, 8, 2020);
	InserirListaMedInicio(pListaMed, 90296168, "LANZACOR", "NEO QUIMICA", "LOSARTANA POTASSICA", 10.52, 19.98, 7, 2020);
	InserirListaMedInicio(pListaMed, 90296150, "LOSARTANA", "EUROFARMA", "LOSARTANA POTASSICA", 3.99, 7.68, 12, 2020);
	InserirListaMedInicio(pListaMed, 95196, "ADVIL", "PFIZER", "IBUPROFENO", 13.49, 34.07, 11, 2020);
	InserirListaMedInicio(pListaMed, 90282400, "ALIVIUM", "MANTECORP FARMASA", "IBUPROFENO", 8.55, 27.15, 6, 2020);
	InserirListaMedInicio(pListaMed, 90405668, "VIAGRA", "PFIZER", "SILDENAFILA", 163.62, 223.30, 5, 2020);
	InserirListaMedInicio(pListaMed, 90332334, "ASSERT", "EUROFARMA", "SERTRALINA", 11.58, 53.41, 12, 2020);

	BuscarPrincipioAtivo(pListaMed, "LOSARTANA POTASSICA");
	BuscarMaiorMenor(pListaMed);
	VerificarVencimento(pListaMed);
	LiberarListaMed(pListaMed);


	system("pause");
	return 0;
}

//--------------------------------------------------------
// CRIAR LISTA
//--------------------------------------------------------
ListaMed* CriarListaMed() {
	ListaMed* ptrListaMed;

	ptrListaMed = new ListaMed;

	// Se a lista NÃO pode ser criada
	if (ptrListaMed == NULL) {
		cout << "Não foi possível criar a lista!" << endl;
		return NULL;
	}

	// Como a lista está vazia o INÍCIO aponta para NULL
	ptrListaMed->inicio = NULL;

	return ptrListaMed;
}

//--------------------------------------------------------
// LIBERAR LISTA
//--------------------------------------------------------
void LiberarListaMed(ListaMed* ptrListaMed) {
	No* ptrNoAtual;

	//Se a lista NÃO foi criada
	if (ptrListaMed == NULL) {
		cout << "A lista não está criada!" << endl;
		return;
	}

	// Exclui cada Nó da lista
	while (ptrListaMed->inicio != NULL)
	{
		ptrNoAtual = ptrListaMed->inicio;
		ptrListaMed->inicio = ptrNoAtual->proxNo;

		delete ptrNoAtual;
	}

	delete ptrListaMed;
}


//--------------------------------------------------------
// INSERIR NO INÍCIO DA LISTA
//--------------------------------------------------------
bool InserirListaMedInicio(ListaMed* ptrListaMed, int CodMedicamento, string NomeMedicamento, string NomeLaboratorio, string PrincipioAtivo, double PrecoCompra, double PrecoVenda, int MesValidade, int AnoValidade) {
	No* ptrNoNovo;

	//Se a lista NÃO foi criada
	if (ptrListaMed == NULL) {
		cout << "A lista de medicamento não está criada!" << endl;
		return false;
	}

	//---------------------------------------------------------------
	// Cria o novo nó
	//---------------------------------------------------------------
	ptrNoNovo = new No;

	if (ptrNoNovo == NULL) {
		cout << "Memória insulficiente!" << endl;
		return false;
	}

	ptrNoNovo->medicamento.CodMedicamento = CodMedicamento;
	ptrNoNovo->medicamento.NomeMedicamento = NomeMedicamento;
	ptrNoNovo->medicamento.NomeLaboratorio = NomeLaboratorio;
	ptrNoNovo->medicamento.PrincipioAtivo = PrincipioAtivo;
	ptrNoNovo->medicamento.PrecoCompra = PrecoCompra;
	ptrNoNovo->medicamento.PrecoVenda = PrecoVenda;
	ptrNoNovo->medicamento.MesValidade = MesValidade;
	ptrNoNovo->medicamento.AnoValidade = AnoValidade;

	ptrNoNovo->proxNo = ptrListaMed->inicio;

	ptrListaMed->inicio = ptrNoNovo;

	return true;
}

//--------------------------------------------------------
// EXIBIR O MEDICAMENTO QUE POSSUI O PRINCIPIO ATIVO
//--------------------------------------------------------
void BuscarPrincipioAtivo(ListaMed* ptrListaMed, string PrincipioAtivo) {
	No* ptrNoAtual;

	ptrNoAtual = ptrListaMed->inicio;

	while (ptrNoAtual != NULL) {

		if (ptrNoAtual->medicamento.PrincipioAtivo == PrincipioAtivo) {
			cout << "Código do medicamento: " << ptrNoAtual->medicamento.CodMedicamento << endl;
			cout << "Nome do medicamento: " << ptrNoAtual->medicamento.NomeMedicamento << endl;
			cout << "Nome do laboratório: " << ptrNoAtual->medicamento.NomeLaboratorio << endl;
			cout << "Principio ativo: " << ptrNoAtual->medicamento.PrincipioAtivo << endl;
			cout << "Preço de compra: " << ptrNoAtual->medicamento.PrecoCompra << endl;
			cout << "Preço de venda: " << ptrNoAtual->medicamento.PrecoVenda << endl;
			cout << "Mês de validade: " << ptrNoAtual->medicamento.MesValidade << endl;
			cout << "Ano de validade: " << ptrNoAtual->medicamento.AnoValidade << endl;
			cout << endl << endl;

		}
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	cout << endl;
}

//--------------------------------------------------------
// VERIFICAR MAIOR E MENOR VALOR DE VENDA DE MEDICAMENTO DA LISTA
//--------------------------------------------------------
void BuscarMaiorMenor(ListaMed* ptrListaMed) {
	No* ptrNoAtual, * ptrMenor, * ptrMaior;
	double vlrPrecoVenda;

	ptrNoAtual = ptrListaMed->inicio;
	vlrPrecoVenda = ptrNoAtual->medicamento.PrecoVenda;

	while (ptrNoAtual != NULL) {

		if (ptrNoAtual->medicamento.PrecoVenda < vlrPrecoVenda) {
			vlrPrecoVenda = ptrNoAtual->medicamento.PrecoVenda;
			ptrMenor = ptrNoAtual;
		}
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	cout << "\nMedicamento com menor preço de venda da lista" << endl;
	cout << "Código do medicamento: " << ptrMenor->medicamento.CodMedicamento << endl;
	cout << "Nome do medicamento: " << ptrMenor->medicamento.NomeMedicamento << endl;
	cout << "Nome do laboratório: " << ptrMenor->medicamento.NomeLaboratorio << endl;
	cout << "Principio ativo: " << ptrMenor->medicamento.PrincipioAtivo << endl;
	cout << "Preço de compra: " << ptrMenor->medicamento.PrecoCompra << endl;
	cout << "Preço de venda: " << ptrMenor->medicamento.PrecoVenda << endl;
	cout << "Mês de validade: " << ptrMenor->medicamento.MesValidade << endl;
	cout << "Ano de validade: " << ptrMenor->medicamento.AnoValidade << endl;

	ptrNoAtual = ptrListaMed->inicio;

	cout << endl << endl;

	while (ptrNoAtual != NULL) {

		if (ptrNoAtual->medicamento.PrecoVenda > vlrPrecoVenda) {
			vlrPrecoVenda = ptrNoAtual->medicamento.PrecoVenda;
			ptrMaior = ptrNoAtual;
		}

		ptrNoAtual = ptrNoAtual->proxNo;
	}

	cout << "Medicamento com maior preço de venda da lista" << endl;
	cout << "Código do medicamento: " << ptrMaior->medicamento.CodMedicamento << endl;
	cout << "Nome do medicamento: " << ptrMaior->medicamento.NomeMedicamento << endl;
	cout << "Nome do laboratório: " << ptrMaior->medicamento.NomeLaboratorio << endl;
	cout << "Principio ativo: " << ptrMaior->medicamento.PrincipioAtivo << endl;
	cout << "Preço de compra: " << ptrMaior->medicamento.PrecoCompra << endl;
	cout << "Preço de venda: " << ptrMaior->medicamento.PrecoVenda << endl;
	cout << "Mês de validade: " << ptrMaior->medicamento.MesValidade << endl;
	cout << "Ano de validade: " << ptrMaior->medicamento.AnoValidade << endl;
}

//--------------------------------------------------------
// VERIFICAR VENCIMENTO DOS MEDICAMENTOS DA LISTA
//--------------------------------------------------------
void VerificarVencimento(ListaMed* ptrListaMed) {
	No* ptrNoAtual;
	int Mesval;


	ptrNoAtual = ptrListaMed->inicio;

	cout << "\n\nInforme o mês atual: ";
	cin >> Mesval;
	cout << "\nMedicamento com vencimento nos próximos 3 meses incluindo o mês atual: " << endl << endl;

	while (ptrNoAtual != NULL) {
		if (ptrNoAtual->medicamento.MesValidade == (Mesval) || ptrNoAtual->medicamento.MesValidade == (Mesval + 1) || ptrNoAtual->medicamento.MesValidade == (Mesval + 2) || ptrNoAtual->medicamento.MesValidade == (Mesval + 3)) {

			cout << "Código do medicamento: " << ptrNoAtual->medicamento.CodMedicamento << endl;
			cout << "Nome do medicamento: " << ptrNoAtual->medicamento.NomeMedicamento << endl;
			cout << "Nome do laboratório: " << ptrNoAtual->medicamento.NomeLaboratorio << endl;
			cout << "Principio ativo: " << ptrNoAtual->medicamento.PrincipioAtivo << endl;
			cout << "Preço de compra: " << ptrNoAtual->medicamento.PrecoCompra << endl;
			cout << "Preço de venda: " << ptrNoAtual->medicamento.PrecoVenda << endl;
			cout << "Mês de validade: " << ptrNoAtual->medicamento.MesValidade << endl;
			cout << "Ano de validade: " << ptrNoAtual->medicamento.AnoValidade << endl;
			cout << endl;
		}

		ptrNoAtual = ptrNoAtual->proxNo;

	}

}