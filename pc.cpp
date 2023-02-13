   #include<bits/stdc++.h>
   using namespace std;

   int numberOfSubsequences(string S, string W){
        // code here
        int count = 0;
        int Windex = 0;
        cout << "W length" << W.length() << endl;
        for(size_t i = 0; i < S.length(); i++) {
                if(S[i] == W[Windex]) {
                    if(Windex < W.length()){
                        cout << "W:"<<W[Windex] << endl;
                        Windex++;
                        cout << "Windex" << Windex << endl;
                        if(Windex == W.length()){
                            Windex = 0;
                            count++;
                        }
                    } 
                }
            }
        return count;
        }
        int main() {
            string S = "keptbugeylznkshjclmjrqmgnuenwjqgpibqckxcvwrhobstoecfwoljjszhdrptzrlediiagchxdcqrisyfilordpajhqegjpmmyvogxxdczttkntpwefpkvqtcgxkrmzfmwtvvqyxqusahlrdrwvbrluvttikihrwdkraasxsmputclztkuxdhrbcnjovsftxpnxrfukrlempsliehfhqzisotglllekarhswdepqkcfepqizvqpwaimuoxhcesevzyufclvpnbtfrceouvnudzquxyydqcyrbuwfguuvvoaosgcmcrghrxbqxbtpetghqfmybjtyxwmpeqdgijobirtftouzhdgzkuxldtjcpxttnwcxgqaqjtwehsdrxlqhgquljfoycht";
            string W = "kept";
         cout << numberOfSubsequences(S, W) << endl;

            return 0;
        }