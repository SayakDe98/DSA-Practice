 set<char> Set;//we are using set ds for storing the values

        int max = 0;//stores maximum length of set
        int start = 0;//stores starting index of set
        int end = 0;//stores ending index of set
      
        while(start < s.size()) {
            auto it = Set.find(s[start]);//this is used to find if the start element is present in set

            if(it == Set.end()) { //if it reaches end means starting element isn't present in set
                if(start - end + 1 > max) {
                    max = start - end + 1;
                }
                Set.insert(s[start]);
                start++;
            } else {//if element is present in the set
                Set.erase(s[end]);
                end++;
            }
        }
        return max;