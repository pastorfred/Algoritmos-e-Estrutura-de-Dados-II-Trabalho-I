#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string solution(string dna)
{
  for (int i = 0; i < dna.size() - 1; i++)
  {
    if ((dna[i] == 'D' && dna[i + 1] == 'N') || (dna[i] == 'N' && dna[i + 1] == 'D'))
    {
      dna.erase(i, 2);
      dna += 'A';
      i = i - 2;
      if (i <= 0)
      {
        i = -1;
      }
    }
    if ((dna[i] == 'D' && dna[i + 1] == 'A') || (dna[i] == 'A' && dna[i + 1] == 'D'))
    {
      dna.erase(i, 2);
      dna += 'N';
      i = i - 2;
      if (i <= 0)
      {
        i = -1;
      }
    }
    if ((dna[i] == 'A' && dna[i + 1] == 'N') || (dna[i] == 'N' && dna[i + 1] == 'A'))
    {
      dna.erase(i, 2);
      dna += 'D';
      i = i - 2;
      if (i <= 0)
      {
        i = -1;
      }
    }
  }
  return dna;
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
  string palavrafinal = solution(test);              // chama a função e coloca a string final na string palavrafinal
  cout << "Palavra final: " << palavrafinal << endl; // imprime a palavra final
}