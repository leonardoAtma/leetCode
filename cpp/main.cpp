#include <l.hpp>
#include <includ.h>

int main()
{
  int n = 3;
  int k = 2;

  int i = kthGrammar2(n, k);
  int i2 = kthGrammarWithPrint(n, k);
  cout << "\n\nValor não validado: " << i << "\n";
  cout << "Valor validado: " << i << "\n";
  return 0;
}
