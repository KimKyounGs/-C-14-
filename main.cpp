//// 이 문제의 키워드는 내림차순 오름차순 정렬을 할 수 있는가?인거 같은데, 나아가 생각한 것은 이 문제을 어떻게 더 보기 좋고 간편하게 코드를 짤 수 있을까?를 생각했다.
//// 내가 한 것과 정답을 보면 정답에서는 class를 사용하여 이 문제를 접근하였고 나는 주구장창 vector에 모든 변수를 pair을 이용하여 때려 박았다. 내가 한 것은 보기가 불편하다. 이참에 class를 공부해보자! 그리고 다시 이 문제를 풀어보겠다.
// 내가 한 것
#include <bits/stdc++.h>

using namespace std;

int N;
vector <pair<pair<string, int>,pair <int, int>>> student;

bool compare(pair<pair<string,int>, pair<int, int>>a, pair<pair<string,int>, pair<int,int>>b) {
        if(a.first.second == b.first.second) {
                if (a.second.first == b.second.first) {
                        if (a.second.second == b.second.second) {
                                return a.first.first < b.first.first;
                        }
                        else {
                                return a.second.second > b.second.second;
                        }
                }
                else {
                        return a.second.first < b.second.first;
                }
        }
        else {
                return a.first.second > b.first.second;
        }
} 

int main() {
        ios::sync_with_stdio(false);
 	cin.tie(NULL);

        cin >> N;
        for (int i = 0; i < N; i ++) {
                string s;
                int k,e,m;
                cin >> s >> k >> e >> m;
                student.push_back({{s,k},{e,m}});
        }

        sort(student.begin(), student.end(), compare);
        for (int i = 0; i < N; i ++) {
                cout << student[i].first.first << '\n';
        }
}



// 정답 
#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    string name;
    int kor;
    int eng;
    int m;
    Student(string name, int kor, int eng, int m) {
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->m = m;
    }
    /*
    [ 정렬 기준 ]
    1) 두 번째 원소를 기준으로 내림차순 정렬
    2) 두 번째 원소가 같은 경우, 세 번째 원소를 기준으로 오름차순 정렬
    3) 세 번째 원소가 같은 경우, 네 번째 원소를 기준으로 내림차순 정렬
    4) 네 번째 원소가 같은 경우, 첫 번째 원소를 기준으로 오름차순 정렬
    */
    bool operator <(Student &other) {
        if (this->kor == other.kor && this->eng == other.eng && this->m == other.m) {
            return this->name < other.name;
        }
        if (this->kor == other.kor && this->eng == other.eng) {
            return this->m > other.m;
        }
        if (this->kor == other.kor) {
            return this->eng < other.eng;
        }
        return this->kor > other.kor;
    }
};

int n;
vector<Student> v;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor;
        int eng;
        int m;
        cin >> name >> kor >> eng >> m;
        v.push_back(Student(name, kor, eng, m));
    }

    sort(v.begin(), v.end());

    // 정렬된 학생 정보에서 이름만 출력
    for (int i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
}