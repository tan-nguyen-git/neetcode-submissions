/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        //sort by the frist paramether
        //start i from index 1 check index i -1 if end of i -1 > start of i then return false; 
        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int sz = intervals.size();
        for(int i = 1; i <sz ; i++ ){
            Interval first = intervals[i-1];
            Interval next = intervals[i];

            if(first.end > next.start){
                return false;
            } 
            
        }
        return true;
    }
};
