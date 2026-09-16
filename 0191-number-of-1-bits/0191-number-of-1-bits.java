class Solution {
    public int hammingWeight(int n) {
        int count=0;
        String bin=Integer.toBinaryString(n);
        for(char a:bin.toCharArray()){
            if(a=='1')
            count++;
        }
        return count;
    }
}