#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int a=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        a=a^arr[i];
    }

    int k;
    scanf("%d",&k);
    int brr[k];
    int b=0;

    for(int i=0;i<k;i++)
    {
        scanf("%d",&brr[i]);
        b=b^brr[i];
    }

    int ans=0;

    if(n%2==0)
    {
        b=0;
    }

    if(k%2==0)
    {
        a=0;
    }

    ans = a^b;
    printf("%d",ans);
}

// #include <iostream>
// using namespace std;
// void
// solve ()
// {
//   int a, b;
//   cin >> a >> b;
//   if(a==0 && b==0)
//   {
//       cout<<"Chefina"<<endl;
//       return;
//   }
//   while (a || b)
//     {
//       if (a > 0)
// 	{
// 	  a--;
// 	}
//       else if (a == 0 && b > 1)
// 	{
// 	  b -= 2;
// 	}
//       if (b > 0)
// 	{
// 	  b--;
// 	}
//       else if (b == 0 && a > 1)
// 	{
// 	  a -= 2;
// 	}
//       if (a == 0 && b <= 1)
// 	{
// 	  cout << "Chefina" << endl;
// 	  break;
// 	}
//       else if (b == 0 && a <= 1)
// 	{
// 	  cout << "Chef" << endl;
// 	  break;
// 	}
//     }
// }

// int
// main ()
// {
//   // your code goes here
//   int t;
//   cin >> t;
//   while (t--)
//     {
//       solve ();
//     }
//   return 0;
// }
