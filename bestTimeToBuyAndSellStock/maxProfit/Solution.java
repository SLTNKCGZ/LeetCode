package maxProfit;

public class Solution {

	public static void main(String[] args) {
		int[] prices= {7,1,5,3,6,4};
		System.out.println(maxProfit(prices));

	}
	public static int maxProfit(int[] prices) {
        int maxDiff=0;
        for(int i=0;i<prices.length;i++){
            for(int j=i+1;j<prices.length;j++){
                if(prices[j]-prices[i]>maxDiff){
                    maxDiff=prices[j]-prices[i];
                }
            }
        }
        return maxDiff;
    }

}
