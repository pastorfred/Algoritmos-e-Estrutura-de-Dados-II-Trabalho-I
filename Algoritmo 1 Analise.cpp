#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int loop = 0; // variável global que conta a quantidade de vezes que o for é chamado
int pot = 0;
int r = 0;

int solution(string dna)
{
  long long int numOps = 0;
  for (int i = 0; i < dna.size() - 1; i++)
  {
    numOps += 7; // numero de comparações no if
    if ((dna[i] == 'D' && dna[i + 1] == 'N') || (dna[i] == 'N' && dna[i + 1] == 'D'))
    {
      dna.erase(i, 2);
      numOps += dna.size(); // complexidade de erase = tam string nova no pior caso
      dna += 'A';
      numOps += dna.size(); // complexidade de append/+= sobrecarregado = tam string nova no pior caso
      i = i - 2;
      numOps += 2; // uma atribuição e uma soma
      numOps += 1; // comparação do if
      if (i <= 0)
      {
        i = -1;
        numOps++; // atribuição
      }
    }
    numOps += 7; // numero de comparações no if
    if ((dna[i] == 'D' && dna[i + 1] == 'A') || (dna[i] == 'A' && dna[i + 1] == 'D'))
    {
      dna.erase(i, 2);
      numOps += dna.size(); // complexidade de erase = tam string nova no pior caso
      dna += 'N';
      numOps += dna.size(); // complexidade de append/+= sobrecarregado = tam string nova no pior caso
      i = i - 2;
      numOps += 2; // uma atribuição e uma soma
      numOps += 1; // comparação do if
      if (i <= 0)
      {
        i = -1;
        numOps++; // atribuição
      }
    }
    numOps += 7; // numero de comparações no if
    if ((dna[i] == 'A' && dna[i + 1] == 'N') || (dna[i] == 'N' && dna[i + 1] == 'A'))
    {
      dna.erase(i, 2);
      numOps += dna.size(); // complexidade de erase = tam string nova no pior caso
      dna += 'D';
      numOps += dna.size(); // complexidade de append/+= sobrecarregado = tam string nova no pior caso
      i = i - 2;
      numOps += 2; // uma atribuição e uma soma
      numOps += 1; // comparação do if
      if (i <= 0)
      {
        i = -1;
        numOps++; // atribuição
      }
    }
    numOps += 2; // i = i + 1, duas operações
    loop++;      // incrementa a quantidade de loops
  }
  int temp = numOps;
  while (numOps >= 10)
  {
    numOps /= 10;
    pot++;
  }
  int soma = 1;
  int temppot = pot;
  while (temppot > 0) {
    soma = soma * 10;
    temppot--;
  }
  r = temp % soma;
  cout << "Palavra final: " << dna << endl;
  return numOps;
}

int main()
{
  cout << "Algoritmo de Teste 1" << endl
       << endl;

  stringstream testes;
  string line = "";
  ifstream arq;
  arq.open("test01"); // abre o arquivo de teste
  while (arq.good())
  {                     // enquanto o arquivo não terminar
    getline(arq, line); // pega a linha e coloca o valor na string line
    testes << line;     // insere o valor de line dentro da stringstream testes
  }
  arq.close(); // fecha o arquivo

  string test = testes.str();                        // string test recebe a string do arquivo
  cout << "Tamanho string: " << test.size() << endl; // imprime o tamanho da string
  int operations = solution(test);                   // chama a função e coloca o valor de operações no inteiro
  cout << "Quantidade de operacoes: " << operations << "*(10" << "^" << pot << ")" << " R: " << r << endl;                      // imprime a quantidade de operações
  cout << "Quantidade de loops: " << loop << endl; // imprime a quantidade de loops
}