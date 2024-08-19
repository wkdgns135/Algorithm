class WordFilter {
unordered_map<string, vector<int>> suffMap;
vector<string> words;
public:
    WordFilter(vector<string>& words) {
        this->words = words;
        for(int i = words.size()-1; i >= 0; i--){
            string word = words[i];
            for(int j = 1; j <= word.size(); j++){
                string suffWord = word.substr(word.size()-j);
                this->suffMap[suffWord].push_back(i);
            }
        }
    }
    
    int f(string pref, string suff) {
        for(const int i : this->suffMap[suff]){
            if(this->words[i].substr(0, pref.size()) == pref)return i;
        }
        return -1;
    }
};