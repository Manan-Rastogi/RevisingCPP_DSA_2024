#include<bits/stdc++.h>
using namespace std;

map<char, int> createMap(string s){
    map<char, int> countChars;

    int l = s.size();
    for(int i = 0; i < l; i++){
        countChars[s[i]] += 1;
    }

    return countChars; 
}

template <typename K, typename V>
void printMap(const std::map<K, V>& myMap) {
    for (const auto& pair : myMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}


int main(){
    int t;
    cin >> t; 

    while(t--){
        string pattern, text;

        cin >> pattern >> text;

        map<char, int> patternCount = createMap(pattern);

        
       
        
        string ans="NO";
        int l=text.size();
        int p=pattern.size();

        if (l<p){
        	cout<<ans<<endl;
        	continue;
        }

        map<char, int>::iterator it = patternCount.begin();
        map<char, int> subMap= createMap(text.substr(0,p));


        for(int i=p;i<l;i++){
        	

        	if (patternCount == subMap){
        		ans="YES";
        		break;
        	}
        	

        	subMap[text[i-p]]--;
        	if (subMap[text[i-p]] == 0){
        		subMap.erase(text[i-p]);
        	}
        	subMap[text[i]]++;
        }

		if (patternCount == subMap){
        	ans="YES";
        }

        cout<<ans<<endl;
    }

    return 0;  
}
