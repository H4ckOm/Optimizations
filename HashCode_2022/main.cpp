/*

Team - Alpha Interface

- Aditya Dimri
- Ankur Agarwal
- Raghav D Turki
- Kunal Verma

College - Indian Institute of Information Technology Kota
Branch - Computer Science & Engineering
Year - 2nd Year
Date - 24-02-2022
*/


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second

const long double PI = atan(1) * 4.0;

const int MAX_C = 1e5 + 5;
int C, P;

vector<pair<string, vector<string> > > ans;

struct project {
	string name;
	vector<pair<string, int> > roles;
	int needDays, deadline, score;
};

struct contributer {
	int id;
	string name;
	vector<pair<string, int> > skills;
	map<string, int> skillLevel;
};

bool compProject(project &a, project &b) {
	int s1 = 0;
	int sum = 7;
	s1 += (a.score > b.score) * 1;
	s1 += (a.deadline < b.deadline) * 3;
	s1 += (a.needDays < b.needDays) * 3;
	return s1 * 2 >= sum;
}

vector<project> allProjects;
vector<contributer> allContributers;
vector<string> allSkills;
set<string> foundSkill;
map<string, vector<contributer> > skillCons;
int finished[MAX_C];
string neededSkill;
bool compSkills(contributer &a, contributer &b) {
	return a.skillLevel[neededSkill] < b.skillLevel[neededSkill];
}

void solve() {
	cin >> C >> P;
	for (int i = 0; i < C; i++) {
		contributer con;
		con.id = i;
		string name;
		cin >> name;
		con.name = name;
		int numOfSkills; cin >> numOfSkills;
		for (int j = 0; j < numOfSkills; j++) {
			string skillName;
			int level;
			cin >> skillName >> level;
			con.skills.push_back({skillName, level});
			if (foundSkill.find(skillName) != foundSkill.end()) {
				allSkills.push_back(skillName);
			}
			foundSkill.insert(skillName);
			con.skillLevel[skillName] = level;
			skillCons[skillName].push_back(con);
		}
		allContributers.push_back(con);
	}
	for (int i = 0; i < P; i++) {
		project proj;
		string name; cin >> name;
		int days, score, deadline, numberOfSkills;
		cin >> days >> score >> deadline >> numberOfSkills;
		for (int j = 0; j < numberOfSkills; j++) {
			string skillName;
			int levelNeeded;
			cin >> skillName >> levelNeeded;
			proj.roles.push_back({skillName, levelNeeded});
			if (foundSkill.find(skillName) != foundSkill.end()) {
				allSkills.push_back(skillName);
			}
			foundSkill.insert(skillName);
		}
		proj.needDays = days;
		proj.deadline = deadline;
		proj.score = score;
		proj.name = name;
		allProjects.push_back(proj);
	}
	sort(allProjects.begin(), allProjects.end(), compProject);
	for (auto &skill : allSkills) {
		neededSkill = skill;
		sort(skillCons[skill].begin(), skillCons[skill].end(), compSkills);
	}
	for (auto &currProject : allProjects) {
		int maxSecond = 0;
		bool can = true;
		bool done[C];
		mm(done);
		vector<int> taken;
		vector<string> names;
		for (auto &role : currProject.roles) {
			string skillName = role.first;
			int level = role.second;
			int minSecond = 1e8;
			int last = -1;
			for (auto &con : skillCons[skillName]) {
				if (level <= con.skillLevel[skillName]) {
					if (done[con.id]) {
						continue;
					}
					if (minSecond > finished[con.id]) {
						minSecond = finished[con.id];
						last = con.id;
					}
				}
			}
			if (minSecond == 1e8) {
				can = false;
				break;
			}
			done[last] = true;
			taken.push_back(last);
			maxSecond = max(maxSecond, minSecond);
		}
		if (!can) {
			continue;
		}
		for (int i = 0; i < taken.size(); i++) {
			names.push_back(allContributers[taken[i]].name);
			finished[taken[i]] = maxSecond + currProject.needDays;
		}
		ans.push_back({currProject.name, names});
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << endl;
		for (int j = 0; j < ans[i].second.size(); j++) {
			cout << ans[i].second[j] << " ";
		}
		cout << endl;
	}
}

int main() {
	FAST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();

	return 0;
}