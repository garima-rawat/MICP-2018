#include<bits/stdc++.h>
using namespace std;

typedef vector <vector <int> > vect;

vect func(int a[],int n)
{
    int i,j,k;
    vect v;
    set <string> s; // for unique triplet
    sort(a,a+n);
    
    for(i=0;i<n-2;i++)
    {
        j=i+1;
        k=n-1;
        while(j<k)
        {
            if(a[i]+a[j]+a[k]>0)
            k--;
            
            else if(a[i]+a[j]+a[k]<0)
            j++;
            
            else
            {
                string temp=""; //to store triplet value as string 
                temp+=a[i];
                temp+='_';
                temp+=a[j];
                temp+='_';
                temp+=a[k];
                temp+='_';
                //cout<<temp;
                if(s.find(temp)==s.end())
                {
                    vector<int> ve;
                    ve.push_back(a[i]);
                    ve.push_back(a[j]);
                    ve.push_back(a[k]);
                    
                    v.push_back(ve);
                }
                j++;
                k++;
                
            }
            
        }
    }
    
    return v;
    
}

int main()
{
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>a[i]; // taking input array
    }
    if(n<3) // if array length in less than 3
    cout<<"Triplet not found\n";
    else
    {
        vect v;
        
        v=func(a,n);
        
        if(v.size()==0)
        cout<<"Triplet not found\n";
        
        else
        {
            
            for(i=0;i<v.size();i++)
            {
                for(int j=0;j<3;j++)
                cout<<v[i][j]<<" ";
                cout<<"\n";
            }
        }
    }
}
