class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int num1Size = nums1.length;
        int num2Size = nums2.length;
        int result = 0;
        // TLE (38/42)
        // for(int i = 0;i<num1Size;i++){
        //     for(int j = 0;j<num2Size;j++){
        //         result ^= (nums1[i] ^ nums2[j]);
        //     }
        // }

        if(num1Size % 2 == 0 && num2Size % 2 == 0) return 0;
        
        int nums1Xor = 0;
        int nums2Xor = 0;
        for(int i = 0;i<num1Size;i++){
            nums1Xor ^= nums1[i];
        }

        for(int i = 0;i<num2Size;i++){
            nums2Xor ^= nums2[i];
        }

        if(num1Size % 2 == 1 && num2Size % 2 == 1) return nums1Xor ^ nums2Xor;
        else if(num1Size % 2 == 1) return nums2Xor;
        else return nums1Xor;
        
    }
}