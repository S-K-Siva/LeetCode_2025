class Solution {
public:

    void construct(string current,vector<char> chars,int n,vector<string>& res){
        if(current.size() == n){
            res.push_back(current);
            return;
        }
        for(int i = 0;i<chars.size();i++){
            if(current.empty() || current.back() != chars[i]){
                construct(current+chars[i], chars,n,res);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<char> chars = {'a','b','c'};
       
        vector<string> result;
        construct("",chars,n,result);
        sort(result.begin(),result.end());
        return (k <= result.size()) ? result[k-1] : "";
        
    }
};