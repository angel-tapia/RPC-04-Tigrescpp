#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c){
    if(c =='a' || c== 'e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

int main()
{
    string s1, s2, res;
    cin >> s1 >> s2;
    char v1, v2;

    int s1_len = s1.length();

    string sub1;
    for(int i = 1; i < s1_len; i++){
        if(is_vowel(s1[i])) {
            v1 = s1[i];
            sub1 = s1.substr(0, i);
            break;
        } else if(i == s1_len-1){
            v1 = 'c';
            sub1 = s1.substr(0, i+1);
        }
    }

    string sub2;
    int s2_len = s2.length();
    for(int i = s2_len-2; i >= 0; i--){
        if(is_vowel(s2[i])) {
            v2 = s2[i];
            sub2 = s2.substr(i+1, s2_len-1-i);
            break;
        } else if(i == 0){
            v2 = 'c';
            sub2 = s2.substr(i, s2_len-i);
        }
    }

    if(is_vowel(v2)) res = sub1 + v2 + sub2;
    else if(is_vowel(v1)) res = sub1 + v1 + sub2;
    else res = sub1 + 'o'  + sub2;

    cout<<res;

    return 0;
}
