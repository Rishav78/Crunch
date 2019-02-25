#include <iostream>
#include<cstring>
#include<fstream>
using namespace std;

fstream obj("file.txt",ios::app);

void combination(char *str,char *p, int n, int j=0)
{
    if(j==n)
    {
        cout << p << endl;
        return;
    }
    for(int k=0;str[k]!='\0';k++)
    {
        p[j]=str[k];
        combination(str,p,n,j+1);
    }
}

bool NaN(char *str)
{
  for(int i=0;str[i]!='\0';i++)
  {
    if(str[i]<'0' || str[i]>'9')
    {
      return true;
    }
  }
  return false;
}

bool validArgument(int argc, char *argv[])
{
  if(argc==4)
  {
    if(!NaN(argv[2]) && !NaN(argv[3]))
    {
      return true;
    }
  }
  return false;
}

int toInteger(char *str)
{
  int n=0;
  for(int i=0;str[i]!='\0';i++)
  {
    n = n*10 + (str[i]-'0');
  }
  return n;
}

int main(int argc, char *argv[])
{
  if(!validArgument(argc,argv))
  {
    cout << "Invalid Input" << endl;
    return 0;
  }
    for(int i=toInteger(argv[2]);i<=toInteger(argv[3]);i++)
    {
        char p[i];
        p[i]='\0';
        combination(argv[1],p,i);
    }
    return 0;
}
