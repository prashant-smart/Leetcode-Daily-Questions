class Twitter {
    int timer = INT_MAX;
    map<int, map<int, bool>> friends;
    // map user id with user friends map
    map<int, pair<int, int>> tweets;
    // time {userId, tweetId}
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[timer--] = {userId, tweetId};
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(auto it: tweets){
            if(it.second.first == userId || friends[userId].find(it.second.first)!=friends[userId].end())
                ans.push_back(it.second.second);
            if(ans.size() == 10) break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};