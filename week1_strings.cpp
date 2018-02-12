//As per solution submitted on leetcode

class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int n,i,j,loc_max,global_max;
        n= s.length();
        loc_max=0;
        global_max=0;
        j=0; //index after which characters are distinct at any point
       
        map <char,int> m;
        
        
        for(i=0;i<n;i++){
            if(s[i]==' ')
                continue;
            
            if(m.find(s[i])==m.end() || m[s[i]]<j){
                m[s[i]]=i;
                loc_max++;
            }
            else{
                loc_max=i-m[s[i]];
                j=m[s[i]];
                m[s[i]]=i;
            }
            
            if(loc_max>global_max){
                global_max=loc_max;
            }
            
        }
        
        return global_max;
        
    }
};

