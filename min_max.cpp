#include<bits/stdc++.h>
#include<unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
  int l1,l2,l3,l4;
  int p1[2],p2[2],p3[2],p4[2];
  int N;
  pipe(p1);
  pipe(p2);
  pipe(p3);
  pipe(p4);
          cout<<"enter size of an array"<<endl;
          cin>>N;
          int div=N/4;
          vector<int> v(N);
          cout<<"enter the entries for array"<<endl;
                    for(int i=0;i<N;i++)
                    {
                                    cin>>v[i];
                    }



 int f1=fork();
              if(f1>0)//parent
              {
                              wait(NULL);
                              //int c1,c2,c3,c4;
                              close(p1[1]);
                              close(p2[1]);
                              close(p3[1]);
                              close(p4[1]);

                              read(p1[0],&l1,sizeof (l1));
                              close(p1[0]);

                              read(p2[0],&l2,sizeof(l2));
                              close(p2[0]);

                              read(p3[0],&l3,sizeof(l3));
                              close(p3[0]);

                              read(p4[0],&l4,sizeof(l4));
                              close(p4[0]);

                              //cout<<l1<<l2<<l3<<l4<<endl;
                              int ans1= min(l1,l2);
                              //cout<<ans1<<endl;
                              int ans2= min(l3,l4);
                              //cout<<ans2<<endl;
                              int ans= min(ans1,ans2);
                              cout<<"Minimum number is : "<<ans<<endl;
              }


              else
              {
                            int f2=fork();
                            int f3=fork();
                            if(f2>0&&f3==0)
                            {
                                          int l1;
                                          close(p1[0]);
                                          l1 = *min_element(begin(v)+3*div,end(v));
                                          write(p1[1], &l1, sizeof(l1));
                                          close(p1[1]);
                                           //cout<<"l1 is"<<l1<<endl;

                            }

                            else if(f3>0&&f2==0)

                            {
                                          int l2;
                                          close(p2[0]);
                                          l2 = *min_element(begin(v)+2*div,begin(v)+3*div);
                                          write(p2[1], &l2, sizeof(l2));
                                          close(p2[1]);
                                          //cout<<"l2 is"<<l2<<endl;

                            }

                            else if(f2==0&&f3==0)

                            {
                                          int l3;
                                          close(p3[0]);
                                          l3 = *min_element(begin(v)+div,begin(v)+2*div);
                                          write(p3[1], &l3, sizeof(l3));
                                          close(p3[1]);
                                            //cout<<"l3 is"<<l3<<endl;;

                            }

                            else

                            {
                                          int l4;
                                          close(p4[0]);
                                          l4 = *min_element(begin(v),begin(v)+div);
                                          write(p4[1], &l4, sizeof(l4));
                                          close(p4[1]);
                                          //cout<<"l4 is"<<l4<<endl;
                            }

            }

}
