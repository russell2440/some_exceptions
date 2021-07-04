#include <iostream>
using namespace std;

void mightGoWrong(){

  bool error1 = false;
  bool error2 = false;
  bool error3 = true;

  if (error1){
    throw 8;
  }
  if(error2)
  {
    throw "c-string";
  }
  if(error3)
  {
    throw string("cpp string");
  }
}
void uses_might_go_wrong()
{
  mightGoWrong();
}
int main1() {
  cout << "Hello World!\n";
  try{
    uses_might_go_wrong();
  }
  catch(int e){
    cout << "caught error1: "<<e<< endl;
  }
  catch(char const* e){
    cout << "caught error2: "<<e<<endl;
  }
  catch(string& e){
   cout << "caught error3: "<<e<<endl;
  }
  cout<<"still running\n"<<endl;
  return 0;
}

class canGoWrong
{
  public:
  canGoWrong(unsigned long n){
    char *p = new char[n];
    delete [] p;
  }
};

int main() {
   cout << "Hello World!\n";
 try {
    canGoWrong wrong(99999999999);
  }
  catch (bad_alloc &e)
  {
    cout<<"caught exception: "<<e.what()<<endl;
  }
  cout<<"still running\n"<<endl;
  return 0;
}