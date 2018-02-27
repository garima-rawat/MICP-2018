#include<bits/stdc++.h>
using namespace std;


bool wordFound(string word, vector<string>dictionary)
{
    //cout<<"\nIN BOOL "<<word;
    int size = dictionary.size();
    for (int i = 0; i < size; i++){
        if (dictionary[i].compare(word) == 0)
           {return true;}
    }       
    return false;
}

bool wordBreak(string str, vector<string> dictionary)
{
    int i,j,n = str.size();
    if (n == 0){
        return true;
    }
    
    
    if(dictionary.empty()){
        return false;
    }
 
    bool dp[n+1]={0};
 
    for (i=1; i<=n; i++)
    {

        if (dp[i] == false && wordFound( str.substr(0, i),dictionary ))
            dp[i] = true;

        if (dp[i] == true)
        {

            if (i == n)
                return true;
 
            for (j = i+1; j <= n; j++)
            {

                if (dp[j] == false && wordFound( str.substr(i, j-i),dictionary ))
                    dp[j] = true;
 
                if (j == n && dp[j] == true)
                    return true;
            }
        }
    }
 
/*
     for (i = 1; i <= size; i++)
        cout << " " << dp[i]; */
 
    return false;
}
bool t1()
{
    vector<string> dictionary = {"pear","right"};
    string s="";
    return wordBreak(s,dictionary);
}
bool t2()
{
    vector<string> dictionary = {};
    string s="hello";
    return !wordBreak(s,dictionary);    
}
bool t3()
{
    vector<string> dictionary = {};
    string s="";
    return wordBreak(s,dictionary);    
}
bool t4()
{
    vector<string> dictionary = {"pear","salmon"};
    string s="pear";
    return wordBreak(s,dictionary);    
}
bool t5()
{
    vector<string> dictionary = {"pear","salmon"};
    string s="pearpearpearpearpear";
    return wordBreak(s,dictionary);    
}
bool t6()
{
    vector<string> dictionary = {"foot","print","footprints"};
    string s="footprintsfootprint";
    return wordBreak(s,dictionary);    
}
bool t7()
{
    vector<string> dictionary = {"foot","print","footprints","leave","at","sat"};
    string s="footprintsat";
    return wordBreak(s,dictionary);    
}
bool t8()
{
    vector<string> dictionary = {"foot","print","footprints","sat"};
    string s="footprintat";
    return !wordBreak(s,dictionary);    
}
bool t9()
{
    vector<string> dictionary = {"footprints","sat"};
    string s="footprintsat";
    return !wordBreak(s,dictionary);    
}

bool test()
{
    if(t1() && t2() && t3() && t4() && t5() && t6() && t7() && t8() && t9()){
    return true;
    }

    return false;

}

int main()
{
    vector<string> dictionary = {"pear","salmon","foot","print","footprints","leave","you","sun","at","sat","right"};
    
    string s;
    cin>>s;
    bool ans = wordBreak(s,dictionary);
    cout<<ans<<"\n";
    //cout<<test();


    return 0;
}
