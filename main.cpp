// Linha de comando do projeto com: /source-charset:utf-8 /execution-charset:.850

#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

// Registros:
struct complexo {
	float real;
	float imaginario;
};

struct Chocolate {
	char nome[20];
	float peso;
	int calorias;
};

struct Data {
	int dia;
	int mes;
	int ano;
	int diaCount;
};

struct Horario {
	int hora;
	int minuto;
	int segundo;
};

struct Evento {
	char local[80];
	Data data;
	Horario horario;
};

struct Conta_bancaria {
	char titular[80];
	int identificador;
	int saldo = {};
};

struct Palavra {
	char portugues[80];
	char ingles[80];
	char espanhol[80];
};

struct Livro {
	int emprestimo;
};

struct Jogo {
	int emprestimo;
};

// Protótipos:

complexo operator+(const complexo&, const complexo&);
complexo operator*(const complexo&, const complexo&);
ostream& operator<<(ostream&, const complexo&);
istream& operator>>(istream&, complexo&);
ostream& operator<<(ostream&, const Chocolate&);
int operator-(const Data&, const Data&);
ostream& operator<<(ostream&, const Data&);
istream& operator>>(istream&, Data&);
Data dataAtual();


void definirChocolates(Chocolate[]);
void contaBancaria();


ostream& operator<<(ostream&, const Conta_bancaria&);
istream& operator>>(istream&, Conta_bancaria&);

void linguagens();
ostream& operator<<(ostream&, const Palavra&);
istream& operator>>(istream&, Palavra&);

void emprestarLivros_ouJogos();
void eventos();
Evento criarEvento();

void duracao();
ostream& operator<<(ostream&, const Evento&);
istream& operator>>(istream&, Evento&);
int operator-(const Evento&, const Evento&);

//funções:

int main() {
	// Atividade de Revisão
	// Atividade 1 e 2:

	cout << "Digite o primeiro número complexo: ";
	complexo x;
	cin >> x;
	cout << "\nDigite o segundo número complexo: ";
	complexo y;
	cin >> y;

	complexo resposta = x + y;

	cout << "A soma dos números: " << x + y << endl;
	cout << "A multiplicação dos números: " << x * y << endl;

	// Exercícios de Fixação:
	// Exercício 01:

	Chocolate lanche = { "Charge", 2.3f, 350 };
	cout << lanche << endl;

	// Exercício 02:
	Chocolate barras[3] = { {"Nestle", 8.3f, 542},{"CacauShow", 2.4f, 205},{"Ferrero Rocher", 1.7f, 165} };
	definirChocolates(barras);

	// Exercício 03 e 04:

	cout << "Digite a data de nascimento DD/MM/AAAA: ";
	Data nascimento;
	Data hoje = dataAtual();
	cin >> nascimento;

	cout << "\nData de nascimento: " << nascimento
		<< "\nData de hoje: " << hoje
		<< "\nVocê tem " << hoje - nascimento << " de dias de vida.\n";

	// Atividade de Aprendizagem:
	// Atividade 01, 02 e 03:

	contaBancaria();
	linguagens();

	// Atividade 04:

	emprestarLivros_ouJogos();

	// Atividade 05:

	eventos();

	// Atividade 06:

	duracao();

}

// Achei muito legal isso definir funções com operadores.
complexo operator+(const complexo& a, const complexo& b) {
	complexo temp;
	temp.real = a.real + b.real;
	temp.imaginario = a.imaginario + b.imaginario;
	return temp;
}
complexo operator*(const complexo& a,const complexo& b) {
	complexo temp;
	temp.real = (a.real * b.real) - (a.imaginario * b.imaginario);
	temp.imaginario = (a.imaginario * b.real) + (b.imaginario * a.real);
	return temp;
}

ostream& operator<<(ostream& os,const complexo& entrada) {
	os << entrada.real 
		<< showpos 
		<< entrada.imaginario 
		<< noshowpos 
		<< "i";
	return os;
}
istream& operator>>(istream& is, complexo& entrada) {
	cin >> entrada.real;
	cin >> entrada.imaginario;
	cin.ignore();
	return is;
}

ostream& operator<<(ostream& os, const Chocolate& barra) {
	os << "Nome: " << barra.nome << "\nPeso: " << barra.peso << "\nCalorias: " << barra.calorias;
	return os;
}

int operator-(const Data& hoje, const Data& nascimento) {
	// O professor falou para considerar todos os meses como tendo 31 dias e desconsiderar os anos bissextos,
	// dessa forma, o calculo real para fazer isso é:

	int diaMes_nascimento = nascimento.dia + ((nascimento.mes - 1) * 31);
	int diasMeses = (hoje.dia + ((hoje.mes - 1) * 31)) - diaMes_nascimento;
	int diasAnos = (hoje.ano - nascimento.ano) * 12 * 31;
	int quantidade_deDias = diasMeses + diasAnos;
	
	return quantidade_deDias;
}

ostream& operator<<(ostream& os, const Data& data) {
	os << setfill('0') << setw(2) << data.dia << "\\" << setfill('0') << setw(2) << data.mes << "\\" << data.ano;
	return os;
}
istream& operator>>(istream& is, Data& entrada) {
	cin >> entrada.dia;
	cin.ignore();
	cin >> entrada.mes;
	cin.ignore();
	cin >> entrada.ano;
	cin.ignore();
	return is;
}

void definirChocolates(Chocolate entrada[]) {
	Chocolate barra1 = entrada[0];
	Chocolate barra2 = entrada[1];
	Chocolate barra3 = entrada[2];
	cout << "\nBarra de chocolate 1:\n" << barra1 << "\n"
		<< "\nBarra de chocolate 2:\n" << barra2 << "\n"
		<< "\nBarra de chocolate 3\n" << barra3 << "\n";
}
Data dataAtual() {
	Data temp;
	auto agora = chrono::floor<chrono::days>(chrono::system_clock::now());
	chrono::year_month_day data{ agora };
	unsigned int dia = unsigned int(data.day()); temp.dia = dia;
	unsigned int mes = unsigned int(data.month()); temp.mes = mes;
	int ano = int(data.year()); temp.ano = ano;
	return temp;
}

void contaBancaria() {

	Conta_bancaria pessoa_00 = { "", 00, 0 };
	cout << "Digite o nome titular da conta, e o identificador: ";
	cin >> pessoa_00;
	cout << "O saldo presente na conta do titular " << pessoa_00.titular << " é de " << pessoa_00.saldo << ".";
	cout << "\nQuanto de saldo você deseja colocar na conta? "; cin >> pessoa_00.saldo;
	cout << pessoa_00 << "\n";
}

ostream& operator<<(ostream& os, const Conta_bancaria& entrada) {
	os << "\nIdentificador: " 
		<< entrada.identificador 
		<< "\nTitular: " << entrada.titular 
		<< "\nSaldo: " << entrada.saldo;
	return os;
}
istream& operator>>(istream& is, Conta_bancaria& entrada) {
	cin.getline(entrada.titular, 80);
	cin >> entrada.identificador;
	cin.get();
	return is;
}
void linguagens() {
	Palavra dicionario[10] = {{"Palavra", "Word", "Palabra"},{"Amor", "Love", "Amar"}};
	cout << "Palavras pressentes no dicionário: " << dicionario[0] << dicionario[1] << "\n";
	cout << "Digite as proximas 8 palavras do portugues com tradução para ingles e espanhol: ";
	for (int i = 2; i < 10; ++i) {
		cout << "\n" << "palavra: " << i;
		cin >> dicionario[i];
	}
	for (int i = 0; i < 10; ++i) {
		cout << dicionario[i];
	}
}

ostream& operator<<(ostream& os, const Palavra& entrada) {
	os << "\n{";
	os << "\nPortuguês: " << entrada.portugues
		<< "\nInglês: " << entrada.ingles
		<< "\nEspanhol: " << entrada.espanhol;
	os << "\n}";
	return os;
}
istream& operator>>(istream& is, Palavra& entrada) {
	cout << "\nPortuguês: ";
	cin.getline(entrada.portugues, 80);
	cout << "\nInglês: ";
	cin.getline(entrada.ingles, 80);
	cout << "\nEspanhol: ";
	cin.getline(entrada.espanhol, 80);
	return is;
}

void emprestarLivros_ouJogos() {
	int resposta = {};
	Livro livro;
	Jogo jogo;
	cout << "Bem vindo a loja de empréstimos Livros e Jogos.";
	cout << "\nDigite 1 para livro e 0 para jogo: ";
	cin >> resposta;
	cin.get();
	if (resposta == 1) {
		livro.emprestimo = 1;
		cout << "\nVocê pegou " << livro.emprestimo << " livro.";
	}
	else {
		jogo.emprestimo = 1;
		cout << "\nVocê pegou " << jogo.emprestimo << " jogo.";
	}
	cout << "\n";
}
void eventos() {
	Evento receber;
	cout << "Digite o local, a data e o horário do evento: ";
	receber = criarEvento();

	cout << "\nLocal: " << receber.local;

	// setfill('0') e setw(2) permite o cout preenche um espaço de 00 com o conteudo da mensagem, desse modo, ao invés de
	// imprimir, como por exemplo, numa data 19/2/2027, mas sim 19/02/2027

	cout << "\nData: " << setfill('0') << setw(2) << receber.data.dia << "\\" << setfill('0') << setw(2) << receber.data.mes << "\\" << setfill('0') << setw(2) << receber.data.ano;
	cout << "\nHorário: " << setfill('0') << setw(2) << receber.horario.hora << ":" << setfill('0') << setw(2) << receber.horario.minuto << ":" << setfill('0') << setw(2) << receber.horario.segundo << "\n";
}

Evento criarEvento() {
	Evento temp;
	cout << "\nLocal: ";
	cin.getline(temp.local, 80);
	cout << "\nData: ";
	cin >> temp.data.dia;
	cin.get();
	cin >> temp.data.mes;
	cin.get();
	cin >> temp.data.ano;
	cin.get();
	cout << "\nHorário: ";
	cin >> temp.horario.hora;
	cin.get();
	cin >> temp.horario.minuto;
	cin.get();
	cin >> temp.horario.segundo;
	cin.get();
	return temp;
}

void duracao() {
	Evento receber[2];
	cout << "Entre com o horário do inicio e do fim da aula: ";
	cout << "\nInicio: ";
	cin >> receber[0];
	cout << "\nFim: ";
	cin >> receber[1];

	int horario = receber[0] - receber[1];

	cout << "Entre " << receber[0] << " e " << receber[1] << " existem "
		<< horario << " minutos, isto é, " << horario / 60 << "h e " << horario % 60 << " minutos.\n";
}

ostream& operator<<(ostream& os, const Evento& receber) {
	os << setfill('0') << setw(2) << receber.horario.hora << ":" << setfill('0') << setw(2) << receber.horario.minuto;
	return os;
}
istream& operator>>(istream& is, Evento& receber) {
	cin >> receber.horario.hora;
	cin.get();
	cin >> receber.horario.minuto;
	cin.get();
	return is;
}

int operator-(const Evento& entrada_01, const Evento& entrada_02) {
	unsigned int temp, horaMinutos, minutos;
	if (entrada_01.horario.hora >= entrada_02.horario.hora) {
		horaMinutos = (entrada_01.horario.hora * 60) - (entrada_02.horario.hora * 60);
		
	}
	else {
		horaMinutos = (entrada_02.horario.hora * 60) - (entrada_01.horario.hora * 60);
	}
	temp = horaMinutos + (entrada_02.horario.minuto) - (entrada_01.horario.minuto);
	return temp;
}
