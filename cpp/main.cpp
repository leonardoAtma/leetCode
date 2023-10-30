#include "./l.hpp"
namespace ffff
{
  struct fsss
  {
    /* data */
  };

  struct fsss12 : fsss
  {
    /* data */
  };

  template <typename T, typename T2 = fsss>
  T farinha(T t, T2 t2)
  {
    cout << t;
    return t;
  }

} // namespace ffff

int main()
{
  int n = 3;
  int k = 2;
  using ffff ::fsss12;
  string s = farinha("\n\nValor não validado: ", fsss12());
  int s2 = farinha(2, fsss12());
  cout << s << s2 << "\n";
  return 0;
}
