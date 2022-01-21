// 국영수
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct student { 
	string name;
	int language;
	int English;
	int math;
};

bool cmp(student s1, student s2) { //정렬 조건 
	if(s1.language == s2.language) {
		if(s1.English == s2.English) {
			if(s1.math == s2.math)
				return s1.name < s2.name;
			else
				return s1.math > s2.math;
			}
		else
			return s1.English < s2.English;
		}
	else
		return s1.language > s2.language;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	student s[100001];
	
	for(int i = 0; i < N; i++) {
		cin >> s[i].name >> s[i].language >> s[i].English >> s[i].math;
	}
	
	sort(s, s+N, cmp); //정렬 
	
	for(int i = 0; i < N; i++)
		cout<<s[i].name<<'\n';
	
	return 0;
}