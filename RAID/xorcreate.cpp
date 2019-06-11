
#include<iostream>
#include <fstream>
using namespace std;
int main(){
  fstream file1;
  fstream file2;
  fstream file3;
  char p,a,b;
   string s, s1;
   cin>>s>>s1;

  file1.open(s,  ios::in | ios::out | ios::binary);
    file2.open(s1,  ios::in | ios::out | ios::binary);
  //  file1.open("/home/dheeraj/Documents/video.mp4",  ios::in | ios::out | ios::binary);
  //    file2.open("/home/dheeraj/Documents/image.png",  ios::in | ios::out | ios::binary);
      file3.open("parity3",ios::out | ios::binary);

      while(!file1.eof() && !file2.eof()){

        file1.read((char *) &a, sizeof(a));
        file2.read((char *) &b, sizeof(b));
        p=a^b;
        file3.write((char *) &p, sizeof(p));
        //cout<<(int)p;
      }
      file1.close();
      file2.close();
      file3.close();

      return 0;
}
