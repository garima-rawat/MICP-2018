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
                return -1; // string with spaces is considered invalid
            
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
    bool testing(){
        //tesing empty string
        if(lengthOfLongestSubstring("")!=0)
            return false;
        //testing for case sensitivity
        if(lengthOfLongestSubstring("abAB")!=4)
            return false;
        //testing for space considering it invalid
        if(lengthOfLongestSubstring("hello spaces")!=-1)
            return false;
        //testing for all set of characters (numbers and special characters)
        if(lengthOfLongestSubstring("123@asA")!=7)
            return false;
        //testing for no string with unique characters
        if(lengthOfLongestSubstring("abcd")!=4)
            return false;
        //testing for same character
        if(lengthOfLongestSubstring("gggggg")!=1)
            return false;
        //random example
        if(lengthOfLongestSubstring("abcdbca")!=4
           return false;
    }
};

