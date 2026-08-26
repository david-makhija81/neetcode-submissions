// So, we have to design a simplified version of twitter and the main objective of this app would be to give you the news feed which contains the 10 most recent items posted by the people he/she follows?
// What happens if I followed a user earlier and after that he posted something I haven'et yet seen my feed and then I unfollowed that person and then saw my news feed, what would happen then - will I see that person's post on my feed or not?
// Does, it matter if the guy has already seen that post or not?
// Can the user delete a tweet
// So, we must maintain a follower list for every user ID and every time we are prompted to fetch the news feed we return the 10 most recent tweets from the users that he follows.
// But, there's a challenge here that we must address and that is to figure out how do we compare the most recent tweets among all the other tweets?
// We'll store each user's tweets in a queue which returns the most recent tweet posted by a user.

struct comp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return (b[0] > a[0]);
    }
};

class Twitter {
    int tweetCount;
    unordered_map<int, vector<vector<int>>> tweets;
    unordered_map<int, set<int>> following;

public:
    Twitter() {
        tweetCount = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId) == tweets.end()) {
            vector<vector<int>> tweetBank;

            tweets.insert({userId, tweetBank});
        }

        tweets[userId].push_back({tweetCount, tweetId});

        tweetCount++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        if(following.find(userId) == following.end()) {
            set<int> follows;
            following.insert({userId, follows});
        }

        following[userId].insert(userId);

        priority_queue<vector<int>, vector<vector<int>>, comp> mostRecentTweets;

        for(int followeeId: following[userId]) {
            if(tweets.find(followeeId) != tweets.end()) {
                int index = tweets[followeeId].size() - 1;

                mostRecentTweets.push({tweets[followeeId][index][0], tweets[followeeId][index][1], followeeId, index});
            }
        }

        while((feed.size() < 10) && (!mostRecentTweets.empty())) {
            vector<int> recentTweetMeta = mostRecentTweets.top();
            mostRecentTweets.pop();

            feed.push_back(recentTweetMeta[1]);

            if(recentTweetMeta[3] > 0) {
                int index = recentTweetMeta[3] - 1;
                int followeeId = recentTweetMeta[2];

                mostRecentTweets.push({tweets[followeeId][index][0], tweets[followeeId][index][1], followeeId, index});
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(following.find(followerId) == following.end()) {
            set<int> follows;
            following.insert({followerId, follows});
        }

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */