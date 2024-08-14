#include<iostream>
#include<string>
using namespace std;
class stack
{
public:
  char arr[1000];
  int top=-1;
  int size;
  stack(int size1)
  {
       size=size1;
  }
  void push(char str)
  {
      if(top>=size-1)
      {
          cout<<"stack is full"<<endl;
      }
      else
      {
          top++;
          arr[top]=str;
      }
  }
  void removestar(string str)
  {
      for(int i=0;i<str.size();i++)
      {
          if(str[i]=='*')
          {
              if(top>=0)
              {
                  top--;
              }
          }
          else
          {
              push(str[i]);
          }
      }
      for(int i=0;i<=top;i++)
      {
         cout<<arr[i];
      }
  }
};
int main()
{
    stack s(20);
    string str;
    cout<<"Enter a string:";
    cin>>str;
    s.removestar(str);
}
