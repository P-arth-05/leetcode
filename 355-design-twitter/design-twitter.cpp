class Twitter {
public:

    // {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // follower -> set of followees
    unordered_map<int, unordered_set<int>> following;

    int time = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // {time, userId, index}
        priority_queue<
            tuple<int, int, int>
        > pq;

        // User's own tweets
        if (tweets.count(userId) && !tweets[userId].empty()) {
            int i = tweets[userId].size() - 1;

            pq.push({
                tweets[userId][i].first,
                userId,
                i
            });
        }

        // Followed users
        for (int followee : following[userId]) {

            if (!tweets.count(followee) ||
                tweets[followee].empty())
                continue;

            int i = tweets[followee].size() - 1;

            pq.push({
                tweets[followee][i].first,
                followee,
                i
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto [t, user, idx] = pq.top();
            pq.pop();

            ans.push_back(tweets[user][idx].second);

            // Add the next older tweet from this user
            if (idx > 0) {
                pq.push({
                    tweets[user][idx - 1].first,
                    user,
                    idx - 1
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};