#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    array<array<int, 6>, 6> startState;
    int flagCars[11] = {0}; // record whether the ith car is recorded
    vector<pair<int, int>> startCars(11);
    int carsCount = 0; // this will be used in searching
    int carLength[11] = {0}; // record the ith car length
    int num;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> num;
            startState[i][j] = num;
            if(num > 0){
                carLength[num]++;
                if(flagCars[num] == 0){
                    startCars[num].first = i;
                    startCars[num].second = j;
                    flagCars[num] = 1;
                    carsCount++;
                }
            }
        }
    }
    
    queue<pair<array<array<int, 6>, 6>, int>> bfs_queue; // puzzle state
    queue<vector<pair<int, int>>> cars_queue; // where the car is
    bfs_queue.push({startState, 0});
    cars_queue.push(startCars);
    while (bfs_queue.size())
    {
        array<array<int, 6>, 6> nowState = bfs_queue.front().first;
        int nowCost = bfs_queue.front().second;
        vector<pair<int, int>> nowCars = cars_queue.front();
        bfs_queue.pop();
        cars_queue.pop();
        // Pruning
        int hasAns = 1;
        for (int i = 0; i < 6; i++)
        {
            if(nowState[2][i] == 1){
                if(nowCost + (6 - i) > 10){
                    hasAns = 0;
                }
                break;
            }
        }
        if(!hasAns) continue;
        // searching
        for (int nowNum = 1; nowNum <= carsCount; nowNum++)
        {
            int i = nowCars[nowNum].first;
            int j = nowCars[nowNum].second;
            if(nowState[i + 1][j] == nowNum){ // The direction of this car is UpDown
                if(i - 1 >= 0 && nowState[i - 1][j] == 0){ // Move Up
                    array<array<int, 6>, 6> nextState = nowState;
                    nextState[i - 1][j] = nowNum;
                    nextState[i + carLength[nowNum] - 1][j] = 0;
                    bfs_queue.push({nextState, nowCost + 1});
                    vector<pair<int, int>> nextCars = nowCars;
                    nextCars[nowNum].first = i - 1;
                    cars_queue.push(nextCars);
                    if(nextState[2][4] == 1 && nextState[2][5] == 1){
                        cout << nowCost + 1 + 2 << endl;
                        return 0;
                    }
                }
                if(i + carLength[nowNum] < 6 && nowState[i + carLength[nowNum]][j] == 0){ // Move Down
                    array<array<int, 6>, 6> nextState = nowState;
                    nextState[i + (carLength[nowNum])][j] = nowNum;
                    nextState[i][j] = 0;
                    bfs_queue.push({nextState, nowCost + 1});
                    vector<pair<int, int>> nextCars = nowCars;
                    nextCars[nowNum].first = i + 1;
                    cars_queue.push(nextCars);
                    if(nextState[2][4] == 1 && nextState[2][5] == 1){
                        cout << nowCost + 1 + 2 << endl;
                        return 0;
                    }
                }
            }
            else if(nowState[i][j + 1] == nowNum){ // The direction of this car is LeftRight
                if(j - 1 >= 0 && nowState[i][j - 1] == 0){ // Move Left
                    array<array<int, 6>, 6> nextState = nowState;
                    nextState[i][j - 1] = nowNum;
                    nextState[i][j + carLength[nowNum] - 1] = 0;
                    bfs_queue.push({nextState, nowCost + 1});
                    vector<pair<int, int>> nextCars = nowCars;
                    nextCars[nowNum].second = j - 1;
                    cars_queue.push(nextCars);
                    if(nextState[2][4] == 1 && nextState[2][5] == 1){
                        cout << nowCost + 1 + 2 << endl;
                        return 0;
                    }
                }
                if(j + carLength[nowNum] < 6 && nowState[i][j + carLength[nowNum]] == 0){ // Move Right
                    array<array<int, 6>, 6> nextState = nowState;
                    nextState[i][j + carLength[nowNum]] = nowNum;
                    nextState[i][j] = 0;
                    bfs_queue.push({nextState, nowCost + 1});
                    vector<pair<int, int>> nextCars = nowCars;
                    nextCars[nowNum].second = j + 1;
                    cars_queue.push(nextCars);
                    if(nextState[2][4] == 1 && nextState[2][5] == 1){
                        cout << nowCost + 1 + 2 << endl;
                        return 0;
                    }
                }
            } 
        }
    }
    
    cout << -1 << endl;

    return 0;
}

