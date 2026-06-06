#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

struct Course {
    string id;
    string name;
    int credit;
    int semester;
    vector<string> prereq;
};

int main () {
    ifstream fin("courses.txt");
    
    /*
    File format:
    N S
    course_id course_name credit designated_semester prereq_count prereq1 prereq2 ...
    ...
    */

    int N, S;
    fin >> N >> S;

    vector<Course> courses(N);
    unordered_map<string, int> index;
    vector<vector<int>> adj(N);
    vector<int> indegree(N, 0);

    for (int i = 0; i < N; i++) {
        int prereq_num;
        fin >> courses[i].id >> courses[i].name
            >> courses[i].credit >> courses[i].semester
            >> prereq_num;

        index[courses[i].id] = i;

        for (int j = 0; j < prereq_num; j++) {
            string p;
            fin >> p;
            courses[i].prereq.push_back(p);
        }
    }
    fin.close();

    for (int i = 0; i < N; i++) {
        for (string p : courses[i].prereq) {
            adj[index[p]].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> topo;

    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }


    vector<int> sem(N, 0);
    for (int u : topo) {
        if (courses[u].semester != 0) {
            sem[u] = courses[u].semester;
        } else {
            int max_pre = 0;
            for (string p : courses[u].prereq)
                max_pre = max(max_pre, sem[index[p]]);
            sem[u] = max_pre + 1;
        }
    }

    // Output:
    ofstream fout("schedule.txt");
    for (int s = 1; s <= S; s++) {
        fout << "Semester " << s << ":\n";
        for (int i = 0; i < N; i++) {
            if (sem[i] == s)
                fout << "  " << courses[i].id
                     << " " << courses[i].name << "\n";
        }
        fout << "\n";
    }
    fout.close();

    cout << "Course scheduling completed successfully.\n";
    return 0;
}