class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int num: nums) {
            if ((cnt1 == 0) || (num1 == num)) {
                num1 = num;
                cnt1++;
            } else if ((cnt2 == 0) || (num2 == num)) {
                num2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int num: nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            }
        }

        List<Integer> ans = new ArrayList<>();

        if (cnt1 > (nums.length / 3)) {
            ans.add(num1);
        }

        if (cnt2 > (nums.length / 3)) {
            ans.add(num2);
        }

        return ans;
    }
}