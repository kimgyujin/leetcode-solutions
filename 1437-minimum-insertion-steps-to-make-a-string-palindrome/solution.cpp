// The class has methods for read write algorithms B and algorithm C and profiling timespec.
class Hirschberg
{
  public:
    void B(int, int, string, string, int[]);
    string C(int, int, string, string, string);
    void read_write();
    timespec diff(timespec, timespec);
};

/* Algorithm B that delivers only the last row in the matrix. 
   Since matrix passed by reference no need to pass the matrix back .*/
void Hirschberg ::B(int m, int n, string str1, string str2, int LL[])
{
  int k[2][n + 1];
  int i, j;
  for (j = 0; j < (n + 1); j++) k[1][j] = 0;

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < (n + 1); j++) k[0][j] = k[1][j];

    for (j = 1; j < (n + 1); j++)
    {
      if (str1[i] == str2[j - 1]) k[1][j] = k[0][j - 1] + 1;
      else                        k[1][j] = max(k[1][j - 1], k[0][j]);
    }
  }
  for (j = 0; j < (n + 1); j++) LL[j] = k[1][j];
}

// The program that writes the LCS string has to return since it is used in recursive fashion.
string Hirschberg ::C(int m, int n, string str1, string str2, string lcs)
{
  // If problem is trivial then solve it.
  if (n == 0)
  {
    lcs = "";
    return lcs;
  }
  else
  {
    if (m == 1)
    {
      int found = str2.find_first_of(str1[0]);
      if (found != string::npos) lcs = str1[0];
      else                       lcs = "";
      return lcs;
    }
  }

  int l1[n + 1], l2[n + 1];
  int i = (int)(m / 2);
  B(i, n, str1.substr(0, i), str2, l1);

  // The statements that reverse the string with the helper functions
  // like rbegin, rend and riterator in string class.
  string str1_rev, str2_rev;
  string::reverse_iterator rev_iter;

  for (rev_iter = str1.rbegin(); rev_iter < str1.rend(); rev_iter++)
    str1_rev.push_back(*rev_iter);

  for (rev_iter = str2.rbegin(); rev_iter < str2.rend(); rev_iter++)
    str2_rev.push_back(*rev_iter);

  B(i + 1, n, str1_rev.substr(0, m - i), str2_rev, l2);

  // Finding the max value of j.
  int max = 0, k = 0;
  for (int j = 0; j < (n + 1); j++)
  {
    if ((l1[j] + l2[n - j]) > max)
    {
      max = l1[j] + l2[n - j];
      k = j;
    }
  }
  string lcs1, lcs2;

  // Have to increase the value of i in case it becomes zero since then
  // the C++ substring function will send back a empty string and not
  // the first character.
  if (i == 0) i++;

  return C(i, k, str1.substr(0, i), str2.substr(0, k), lcs1)
      .append(C(m - i, n - k, str1.substr(i, m), str2.substr(k, n), lcs2));
}

class Solution {
public:
    int minInsertions(string s) {
        Hirschberg h;
        string a,b,c,lcs;
        int n,m;

        a = s;
        b = a;
        reverse(b.begin(),b.end());
        n = a.length();
        m = b.length();
        c = "";
        lcs = h.C(n,m,a,b,c);

        return s.length() - lcs.length();
    }
};
