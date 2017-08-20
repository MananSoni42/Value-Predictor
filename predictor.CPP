#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{ clrscr();
int i,j,k,s=1,l=42,t,n=0;
double z,A[10][10],B[10][10],C[10],D[10],temp1,temp2;
double a[10],c[10],p;

z123:
cout<<endl<<"Enter Number of Inputs: ";cin>>n;
if (n>10)
{ cout<<"Too many inputs!"; goto z123; }
cout<<endl<<endl;

for (i=0;i<n;i++)
{ C[i]=0; D[i]=0;
  for (j=0;j<20;j++)
  { A[i][j]=0;
    if (i==j)
    { B[i][j]=1; }
    else
    { B[i][j]=0; }
  }
}
for (i=0;i<n;i++)
{ cout<<"Enter Input "<<i+1<<": ";cin>>a[i];
  cout<<"Enter Output "<<i+1<<": ";cin>>c[i];
  cout<<endl;
}

cout<<endl<<"Enter Input to be estimated: ";cin>>p;

clrscr();

for (i=0;i<n;i++)
{ for (j=0;j<n;j++)
  { A[i][j]=pow(a[i],j); }
}
cout<<endl<<endl;
for (i=0;i<n;i++)
{ C[i]=c[i]; }

for (i=0;i<n;i++)
{ t=A[i][i];
  if (t==0 && i!=n-1)
  { l=42;
    for (j=i+1;j<n;j++)
    { if (A[i][j]!=0)
      { l=j; break; }
    }
    if (l==42)
    { s=0; break; }
    if (l!=42)
    { for (j=0;j<n;j++)
      { temp1=A[j][i];
	temp2=B[j][i];

	A[j][i]=A[j][l];
	B[j][i]=B[j][l];

	A[j][l]=temp1;
	B[j][l]=temp2;
      }
    }
  }
  if (t==0 && i==n-1)
  { s=0; break; }

  t=A[i][i];

  for (j=0;j<n;j++)
  { A[i][j]=A[i][j]/t;
    B[i][j]=B[i][j]/t;
  }

  for (j=0;j<n;j++)
  { if (j!=i)
    { z=A[j][i];
      for (k=0;k<n;k++)
      { B[j][k]=B[j][k]-(z*B[i][k]);
	A[j][k]=A[j][k]-(z*A[i][k]);
      }
    }
  }
}

clrscr();

if (s==0)
{ cout<<"No Output found for given data "; }
if (s==1)
{ for (i=0;i<n;i++)
  { for (j=0;j<n;j++)
    { D[i]=D[i]+(B[i][j]*C[j]); }
  }
  cout<<"Taylor Expansion: "<<endl<<endl;
  for (i=0;i<n;i++)
  { if (i!=n-1)
    { cout<<"("<<D[i]<<")"<<"x^"<<i<<" + "; }
    if (i==n-1)
    { cout<<"("<<D[i]<<")"<<"x^"<<i; }
  }
  cout<<endl<<endl;
  double ans=0.0;
  for (i=0;i<n;i++)
  { ans=ans+(D[i]*pow(p,i)); }
  cout<<endl<<endl<<"Output is: "<<ans;
}
getch();
}