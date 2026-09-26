#include <vector>
#include <algorithm>
using namespace std;
class ExamTracker {
    private:
    vector <int> times;
    vector <long long> prefixSums;
public:
    ExamTracker(): prefixSums({0}) {
        
    }
    
    void record(int time, int score) {
        times.push_back(time);
        prefixSums.push_back(prefixSums.back() + score);

    }
    
    long long totalScore(int startTime, int endTime) {
        auto it1 = lower_bound(times.begin(), times.end(), startTime);
        int L = distance(times.begin(), it1);
        auto it2 = upper_bound(times.begin(), times.end(), endTime);
        int R = distance(times.begin(), it2);
        return prefixSums[R] - prefixSums[L];
    }
};