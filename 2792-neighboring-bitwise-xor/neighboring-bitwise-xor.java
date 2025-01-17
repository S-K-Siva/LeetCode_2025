class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int n=derived.length;
        int[] base=new int[n];

        for(int i=1; i<n; i++){
            base[i]=derived[i-1]^base[i-1];
        }

        for(int i=0; i<n; i++){
            int idx=(i+1)%n;
            if(derived[i]!=(base[i]^base[idx])) return false;
        }

        return true;
    }
}