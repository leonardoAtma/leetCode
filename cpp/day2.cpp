#include <iostream>
#include <vector>
using namespace std;

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