class ExamTracker {
public:
    vector <long long int> psum;
    vector <long long int> t;
    ExamTracker() {
        psum.push_back(0);
        t.push_back(0);
    }
    
    void record(int time, int score) {
        psum.push_back(psum.back() + score);
        t.push_back(time);
    }
    
    long long totalScore(int startTime, int endTime) {
        int L = lower_bound(t.begin(),t.end(),startTime) - t.begin();
        int R = upper_bound(t.begin(),t.end(),endTime) - t.begin();
        R-=1;
        if(L > R) return 0;
        long long res = psum[R] - psum[L-1];
        return res;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
