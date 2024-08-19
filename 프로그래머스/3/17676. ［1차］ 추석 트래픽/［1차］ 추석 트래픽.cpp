#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	double hh, mm, ss;
	double *ts = new double[lines.size()];
	double *tt = new double[lines.size()];
	int *t = new int[lines.size()];
	int *s = new int[lines.size()];


	int size = lines.size();
	cout << fixed;
	cout.precision(15);

	for (int i = 0; i < size; i++) {
		hh = stod(lines[i].substr(11, 2));
		mm = stod(lines[i].substr(14, 2));
		ss = stod(lines[i].substr(17, 6));
		tt[i] = stod(lines[i].substr(24, lines[i].size() - 23));
		ts[i] = (((hh * 60.00) + mm) * 60.00) + ss;
	}
    double temp = s[0];
    
	for (int i = 0; i < size; i++) {
		ts[i] = ts[i] - temp - tt[i] + 0.001;
        tt[i] -= 0.001;
        s[i] = int(ts[i] * 1000);
        t[i] = int(tt[i] * 1000);
	}
    
    int count = 0;
    int max = 0;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(s[j] >= s[i] - 999 && s[j] <= s[i]){
                count++;
            }else if(s[j] + t[j] >= s[i] - 999 && s[j] + t[j] <= s[i]){
                count++;
            }else if(s[j] <= s[i] - 999 && s[j] + t[j] >= s[i]){
                count++;
            }
        }
        if(max < count){
            max = count;
        }
        count = 0;
        
        for(int j = 0; j < size; j++){

            if(s[j] >= s[i] + t[i] && s[j] <= s[i] + t[i] + 999){
                count++;  
            }else if(s[j] + t[j] >= s[i] + t[i] && s[j] + t[j] <= s[i] + t[i] + 999){
                count++;
            }else if(s[j]<= s[i] + t[i] && s[j] + t[j] >= s[i] + t[i] + 999){
                count++;
            }
        }

        if(max < count){
            max = count;
        }
        count = 0;
    }
    
	answer = max;
	return answer;
}