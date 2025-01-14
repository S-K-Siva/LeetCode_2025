class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int[] freq = new int[51];

        int n = A.length;
        int[] res = new int[n];
        if(A[0] == B[0]) res[0] = 1;
        freq[A[0]]++;
        freq[B[0]]++;

        for(int i = 1;i<n;i++){
            res[i] = res[i-1];
            boolean first,second;
            first = second = false;
            if(freq[A[i]] != 0){
                first = true;
                res[i]+=1;
                ++freq[A[i]];
            }
            if(freq[B[i]] != 0){
                second = true;
                res[i] += 1;
                ++freq[B[i]];
            }
            if(!first && !second && A[i] == B[i]){
                res[i] += 1;
                ++freq[A[i]];
                first = second = true;
            }
            if(!first) ++freq[A[i]];
            if(!second) ++ freq[B[i]];
        }
        return res;
    }
}