class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer>mp= new HashMap<>();
        if (s.length() != t.length()) {
            return false;
        }
        for(char c:s.toCharArray()){
            if(mp.containsKey(c))
                mp.put(c,mp.get(c)+1);
            else
                mp.put(c,1);
        }
        for(char c:t.toCharArray()){
            if(!mp.containsKey(c)){
                return false;
            }
            mp.put(c,mp.get(c)-1);
            if(mp.get(c) == 0){
                mp.remove(c);
            }
        }
        return mp.isEmpty();
    }
}//or do by frequeny of alphabets