
 #include <bits/stdc++.h>
 using namespace std;
 
 int nextVal(int x)
 {
     int a, n, i, j;
     char str[20], t;
    sprintf(str, "%d", x);  
     n = strlen(str);
     for (i = 0; i < n; i++)   
     {
         for (j = i+1; j < n; j++)
       {
           if (str[i] >str[j])
             {
                t = str[i];
                str[i] = str[j];
                 str[j] = t;
             }
        }
     }
    sscanf(str, "%d", &a);   
     return (a % 10);        
 }
 int main()
 {
    int n, count, flag;
    while (cin >> n)
     {
         flag = count = 0;
         while (n >= 10)
         {
             n -= nextVal(n);
           count++;
             flag = 1;
         }
         if (flag)
             cout << count + 1 << endl;  
        else if (n == 0)    
             cout << "0" << endl;
         else                                                  
             cout << "1" << endl; 
     }
     return 0;
 }