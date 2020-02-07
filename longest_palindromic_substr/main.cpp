//
//  main.cpp
//  longest_palindromic_substr
//
//  Created by pzambad on 7/9/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    bool isPalindrome (string s) {
        int n = s.size();
        
        for(int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    
public:
    string longestPalindrome(string s) {
        int i, j, max = 0;
        string res;
        
        for (i = 0; i < s.size(); i++) {
            for (j = 0; j < s.size() - i; j++) {
                if (isPalindrome(s.substr(i,j+1)) && max < s.substr(i,j+1).size()) {
                    max = s.substr(i,j+1).size();
                    res = s.substr(i,j+1);
                }
            }
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string s = "flsuqzhtcahnyickkgtfnlyzwjuiwqiexthpzvcweqzeqpmqwkydhsfipcdrsjkefehhesubkirhalgnevjugfohwnlhbjfewiunlgmomxkafuuokesvfmcnvseixkkzekuinmcbmttzgsqeqbrtlwyqgiquyylaswlgfflrezaxtjobltcnpjsaslyviviosxorjsfncqirsjpkgajkfpoxxmvsyynbbovieoothpjgncfwcvpkvjcmrcuoronrfjcppbisqbzkgpnycqljpjlgeciaqrnqyxzedzkqpqsszovkgtcgxqgkflpmrikksaupukdvkzbltvefitdegnlmzeirotrfeaueqpzppnsjpspgomyezrlxsqlfcjrkglyvzvqakhtvfmeootbtbwfhqucbnuwznigoyatvkocqmbtqghybwrhmyvvuchjpvjckiryvjfxabezchynfxnpqaeampvaapgmvoylyutymdhvhqfmrlmzkhuhupizqiujpwzarnszrexpvgdmtoxvjygjpmiadzdcxtggwamkbwrkeplesupagievwsaaletcuxtpsxmbmeztcylsjxvhzrqizdmgjfyftpzpgxateopwvynljzffszkzzqgofdlwyknqfruhdkvmvrrjpijcjomnrjjubfccaypkpfokohvkqndptciqqiscvmpozlyyrwobeuazsawtimnawquogrohcrnmexiwvjxgwhmtpykqlcfacuadyhaotmmxevqwarppknoxthsmrrknu";
    class Solution A;
    
    cout << A.longestPalindrome(s) << endl;
    return 0;
}
