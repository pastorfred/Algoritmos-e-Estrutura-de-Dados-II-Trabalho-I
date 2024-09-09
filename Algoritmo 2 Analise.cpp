#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

int loop = 0;
int pot = 0;
int r = 0;

int solution(string dna)
{
  long long int numOps = 0;
  unordered_map<string, char> dict = {{"AN", 'D'}, {"NA", 'D'}, {"DA", 'N'}, {"AD", 'N'}, {"DN", 'A'}, {"ND", 'A'}};
  numOps += 1 + 6; // uma atribuição, construção de unordered_map é no caso médio O(n)
  for (int i = 0; i < dna.size() - 1; i++)
  {
    string str = dna.substr(i, 2);
    numOps += 1 + 2; // atribuição, substr pior caso = tamanho da substr
    auto chara_to_add = dict.find(str);
    numOps += 1 + 1; // atribuição e busca, caso médio constante (1)
    numOps += 1 + 1; // comparação e acesso ao pointer do fim de um unordered_map, constante (1)
    if (chara_to_add != dict.end())
    {
      dna.erase(i, 2);
      numOps += dna.size(); // erase pior caso = tam da string nova
      dna += chara_to_add->second;
      numOps += dna.size(); // append/sobrecarga += pior caso = tam da string nova
      numOps += 1;          // comparação
      i = i - 2;
      numOps += 2; //atribuição e soma
      if (i <= 0)
      {
        i = -1;
        numOps += 1; // atribuição
      }
    }
    numOps += 2; // i = i + 1;
    loop++; //incrementa o valor de loop
  }
  cout << "Palavra final: " << dna << endl;
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
  return numOps;
}

int main()
{
  cout << "Algoritmo de Teste 2" << endl
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