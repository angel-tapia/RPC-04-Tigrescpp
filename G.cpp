#include <bits/stdc++.h>

using namespace std;

void map_name(string& name){
   for(int j = 0; j < name.size(); j++){
        name[j] = 'z' - name[j];
    }
    return;
}

int main()
{
    priority_queue<pair<long long, string>> employees;
    unordered_map<string, long long> salaries;
    unordered_set<string> layoffs;

    long long n, a;

    cin>> n >> a;

    long long salary;
    string name;

    for(int i = 0; i < n; i++){
        cin>>name>>salary;
        map_name(name);
        employees.push({salary, name});
        salaries[name] = salary;
    }

    int action;
    long long raise;

    while(a > 0){
        cin>>action;
        if(action == 1){
            cin>>name>>raise;
            map_name(name);
            salaries[name] += raise;
            employees.push({salaries[name], name});
        } else if(action==2){
            pair<long long, string> employee = employees.top();
            while(layoffs.find(employee.second) != layoffs.end()){
                employees.pop();
                employee = employees.top();
            }
            employees.pop();
            layoffs.insert(employee.second);
            map_name(employee.second);
            cout<<employee.second<<" "<<employee.first<<"\n";
        }
        a--;
    }

    return 0;
}
