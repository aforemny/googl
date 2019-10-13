
#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define m 1000000007
#define fors(i,n) for(int i=0;i<n;i++)
#define fore(i,a,b) for(int i=a,i<=b;i++)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
lld gcd(lld a,lld b){ if(a<b) { a=a+b; b=a-b; a=a-b;}while(b!=0){lld r=a%b; a=b; b=r;} return a;}
lld bs(lld arr[], lld l, lld r, lld x) { if (r >= l) {  lld mid = l + (r - l) / 2;  if (arr[mid] == x)  return mid; if (arr[mid] > x)  return bs(arr, l, mid - 1, x);  return bs(arr, mid + 1, r, x);  }  return -1; }
lld mypower(lld x, lld n){	if (n == 0)	return 1;	if (n & 1) 	return (((x * mypower(x, n / 2))%m) * (mypower(x, n / 2)%m)%m);return (((mypower(x, n / 2))%m) * (mypower(x, n / 2)%m))%m;}
int main() 
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==0)
        {
            cout<<1<<" "<<0<<"\n";
            continue;
        }
        lld a[n];
        fors(i,n)
        cin>>a[i];
        
        lld x;
        cin>>x;
      /*  lld b[n];
        b[0]=a[0];
        for(int i=1;i<n;i++)
        {
            b[i]=a[i]+b[i-1];
        }
        lld z=2*b[n-1]/3;
        int i;
        for( i=0;i<n;i++)
        {
            if(b[i]>z)
            break;
        }
        
        cout<<i+1<<" "<<n-1-i;;*/
        int l=0,r=n-1;
        lld suml=a[0],sumr=a[n-1];
        while(l!=r-1)
        {
            if(suml<x*sumr)
            {
            l++;
            suml=suml+a[l];
            }
            else if(suml==x*sumr)
            {
                if(l>=n-r-1)
                {
                l++;
                suml+=a[l];
                }
                else
                {
                r--;
                sumr+=a[r];
                }
            }
            else
            {
                r--;
               sumr=sumr+a[r]; 
            }
           // cout<<suml<<" "<<sumr<<"\n";
        }
        cout<<l+1<<" "<<n-l-1<<"\n";
    }
    
    return 0;
}




