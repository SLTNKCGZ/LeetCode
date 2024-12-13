package twoSum;

public class demo {

	public static void main(String[] args) {
		int[] nums= {2,5,7,8};
		int target=9;
		int[] solutions=twoSum(nums,target);
		for(int i=0;i<solutions.length;i++){
			System.out.println(solutions[i]+" ");
		}
	}
	
	    public static int[] twoSum(int[] nums, int target) {
	        int[] solutions=new int[2];
	        for(int i=0;i<nums.length;i++){
	            for (int j=i;j<nums.length;j++){
	                if(nums[i]+nums[j]==target){
	                    solutions[0]=i;
	                    solutions[1]=j;
	                }
	            }
	        }
	        return solutions;
	    }
	

}
