#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

string solution(string dna)
{
  unordered_map<string, char> dict = {{"AN", 'D'}, {"NA", 'D'}, {"DA", 'N'}, {"AD", 'N'}, {"DN", 'A'}, {"ND", 'A'}};
  for (int i = 0; i < dna.size() - 1; i++)
  {
    string str = dna.substr(i, 2);
    auto chara_to_add = dict.find(str);
    if (chara_to_add != dict.end())
    {
      dna.erase(i, 2);
      dna += chara_to_add->second;
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
  string palavrafinal = solution(test);                   // chama a função e coloca a palavra final na string palavrafinal
  cout << "Palavra final: " << palavrafinal << endl;  // imprime a palavra final
}