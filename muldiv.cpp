#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

struct multidiv_entry
{
   int mul;
   float div;
};

struct multidiv_entry **generate_tables(int n)
{
  struct multidiv_entry **ch = new struct multidiv_entry*[n];
  for (int i=0; i<n; i++)
  {
    ch[i] = new struct multidiv_entry[n];
  }
  for (int i=0; i<n; i++)
    {
      double a = i+1;
      for(int j=0; j<n; j++)
      {
        ch[i][j].mul = (j+1) * (a);
        ch[i][j].div = (a)/(j+1);
      }
    }
      return ch;
}
void print_tables(struct multidiv_entry **tables, int n)
{
  struct multidiv_entry **ch;
  cout << "Multiplication Table:" << endl;
      ch = tables;
      for (int i=0; i<n; i++)
      {
        for(int j = 0; j<n; j++)
        {
          cout << setw(3) << std::left << ch[i][j].mul;
        }
         cout << endl;
      }

      cout << "Division Table:" << endl;
      for (int i=0; i<n; i++)
      {
        for(int j = 0; j<n; j++)
        {
          cout << setw(4) << std::left << fixed << setprecision(2) << ch[i][j].div << " ";
        }
         cout << endl;
      }
}

void free_tables(struct multidiv_entry **tables, int n)
{
  struct multidiv_entry **ch;
  ch = tables;
  for (int i=0; i<n; i++)
  {
    delete(ch[i]);
  }
    delete(ch);
}

int main(int argc, char *argv[])
{
  struct multidiv_entry **ch;
  if (argc < 2 || atoi(argv[1]) == 0 || atoi(argv[1]) < 0)
  {
    cout << "Please input a valid number in the command line" << endl;
    return 0;
  }
     int n = atoi(argv[1]);
     ch = generate_tables(n);
     print_tables(ch,n);
     free_tables(ch,n);
}
