class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string> binaries = {"0"};
        for(int i = 1;i<=n;i++){
            string last = binaries.back();
            string newBinary = last;
            newBinary += '1';
            string invertion = "";
            for(int j = 0;j<last.size();j++){
                if(last[j] == '1') invertion += '0';
                else invertion += '1';
            }
            reverse(invertion.begin(),invertion.end());
            newBinary += invertion;
            binaries.push_back(newBinary);
        }
        string binary = binaries[n-1];
        return binary[k-1];
    }
};