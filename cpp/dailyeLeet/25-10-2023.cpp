#include <l.hpp>

int kthGrammarWithPrint(int n, int k)
{
  u_long l = (n > 1) ? u_long(2 << (n - 2)) : n + 2;
  bool v[l];
  bool v2[l];
  v2[0] = 0;
  v2[1] = 1;
  v[0] = 0;
  v[1] = 1;
  bool isV1 = 0;
  for (int i = 0; i < n; i++)
  {
    u_long f = (i > 1) ? u_long(2 << (i - 2)) : i;
    int cn = 0;
    isV1 = !isV1;
    cout << "\nRow " << i << ": ";
    for (int j = 0; j < f; j++)
    {
      if (isV1)
      {
        v2[cn++] = (v[j] == 0) ? 0 : 1;
        cout << v2[cn - 1] << " ";
        v2[cn++] = (v[j] == 0) ? 1 : 0;
        cout << v2[cn - 1] << " ";
      }
      else
      {
        v[cn++] = (v2[j] == 0) ? 0 : 1;
        cout << v[cn - 1] << " ";
        v[cn++] = (v2[j] == 0) ? 1 : 0;
        cout << v[cn - 1] << " ";
      }
      // if (cn > k)
      // {
      //   cout << "\nisV1: " << isV1;
      //   cout << "\nValorProcurado: " << k;
      //   cout << "\nResultado: " << (isV1 ? v2[k - 1] : v[k - 1]);
      //   cout << "\nResultado v1: " << v[k - 1];
      //   cout << "\nResultado v2: " << v2[k - 1];
      //   return isV1 ? v2[k - 1] : v[k - 1];
      // }
    }
  }
  cout << "\nisV1: " << isV1;
  cout << "\nValorProcurado: " << k;
  cout << "\nResultado: " << (isV1 ? v2[k - 1] : v[k - 1]);
  cout << "\nResultado v1: " << v[k - 1];
  cout << "\nResultado v2: " << v2[k - 1];
  return isV1 ? v2[k - 1] : v[k - 1];
}

int kthGrammar(int n, int k)
{
  int l = (n > 1) ? 2 << (n - 2) : n + 2;
  int v[l];
  int v2[l];
  v2[0] = 0;
  v2[1] = 1;
  v[0] = 0;
  v[1] = 1;
  bool isV1 = 0;
  for (int i = 0; i < n; i++)
  {
    int f = (i > 1) ? 2 << (i - 2) : i;
    int cn = 0;
    isV1 = !isV1;
    for (int j = 0; j < f; j++)
    {
      if (isV1)
      {
        v2[cn++] = (v[j] == 0) ? 0 : 1;
        v2[cn++] = (v[j] == 0) ? 1 : 0;
      }
      else
      {
        v[cn++] = (v2[j] == 0) ? 0 : 1;
        v[cn++] = (v2[j] == 0) ? 1 : 0;
      }
      if (cn > k)
      {
        return isV1 ? v2[k - 1] : v[k - 1];
      }
    }
  }
  return isV1 ? v2[k - 1] : v[k - 1];
}
int kthGrammar2(int n, int k)
{
  vector<bool> v;
  u_int cv = 0;
  for (u_int i = 0; i < k; i++)
  {
    if (i == 0 || v[i] == 0)
    {
      v.push_back(0);
      v.push_back(1);
    }
    else
    {
      v.push_back(1);
      v.push_back(0);
    }
    cv++;
    cv++;
    if (cv > k)
    {
      return v[k - 1];
    }
  }
  return 0;
}