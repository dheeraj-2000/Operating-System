#include<bits/stdc++.h>
using namespace std;

int main(){
  fstream file3;
  fstream file2;
  fstream file4;
  char p,a,b;


    file2.open("/home/dheeraj/Documents/image.png",  ios::in | ios::out | ios::binary);
      file3.open("/home/dheeraj/Documents/parity3",  ios::in | ios::out | ios::binary);
      file4.open("/home/dheeraj/Documents/recovered.mp4", ios::out);

      while(!file2.eof() && !file3.eof()){

        file2.read((char *) &a, sizeof(a));
        file3.read((char *) &b, sizeof(b));
        p=a^b;
        file4.write((char *) &p, sizeof(p));
      }
    //  file1.close();
      file2.close();
      file3.close();
      file4.close();

      return 0;
}
