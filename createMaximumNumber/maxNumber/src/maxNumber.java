public class maxNumber {
    public static void main(String[] args) {
        int[] nums1 = { 3, 4, 6, 5 };
        int[] nums2 = { 9, 1, 2, 5, 8, 3 };
        int[] maxNumber = maxNumber(nums1, nums2, 4);
        for (int i = 0; i < maxNumber.length; i++) {
            System.out.print(maxNumber[i]+" ");
        }
    }

    public static int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] finalNum = new int[k];
        
        int[] nums = new int[nums1.length + nums2.length];
        for (int i = 0; i < nums1.length + nums2.length; i++) {
            if (i < nums1.length) {
                nums[i] = nums1[i];
            } else {
                nums[i] = nums2[i - nums1.length];
            }
        }
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] < nums[j]) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        for(int i=0;i<k;i++){
            finalNum[i]=nums[i];
        }
        return finalNum;
    }
}
