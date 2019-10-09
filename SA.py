import re
import tweepy
from tweepy import OAuthHandler
from textblob import TextBlob
 
class TwitterClient(object):

    #initialise key and secret
    def __init__(self):
        
        consumer_key = 'GtCigrm4kHfC8lNqOuj47tffb'
        consumer_secret = 'JRspJcm4Ze0Op6qp1ujJG532EWn6FPenO8ofVdFrXitWBO6Wsj'
        access_token = '4901813779-ydB71luBsuxRI8YjUXsxVjR8rtykZFQjtSMm19r'
        access_token_secret = '4eJmk3gVMItjTKrKrio0QjiGprYqOq5bzgST1GUwbII9Y'
 
        # authentication
        try:
            # OAuthHandler object
            self.auth = OAuthHandler(consumer_key, consumer_secret)
            # set access token and secret
            self.auth.set_access_token(access_token, access_token_secret)
            # create tweepy API object to fetch tweets
            self.api = tweepy.API(self.auth)
            
        except:
            print("Error: Authentication Failed")




 
    def Tweet_Cleaning(self, tweet):
        
        return ' '.join(re.sub("(@[A-Za-z0-9]+)|([^0-9A-Za-z \t])|(\w+:\/\/\S+)", " ", tweet).split())



                               
 
    def get_tweet_sentiment(self, tweet):
        
        # create TextBlob object of passed tweet text
        analysis = TextBlob(self.Tweet_Cleaning(tweet))
        # set sentiment
        # polarity between 1 to -1
        if analysis.sentiment.polarity > 0:
            return 'positive'
        elif analysis.sentiment.polarity == 0:
            return 'neutral'
        else:
            return 'negative'



                               
 
    def get_tweets(self, query, count = 1000):

        # empty list to store all tweets
        tweets = []
 
        try:
            # calling twitter api to fetch tweets
            fetched_tweets = self.api.search(q = query, count = count)
 
            
            for tweet in fetched_tweets:
                # empty dictionary to store text and sentiment of a tweet
                collected_tweets = {}
 
                # appending text of tweet
                collected_tweets['text'] = tweet.text
                # appending sentiment of tweet
                collected_tweets['sentiment'] = self.get_tweet_sentiment(tweet.text)
 
                # appending parsed tweet to tweets list
                if tweet.retweet_count > 0:
                    # if tweet has retweets, ensure that it is appended only once
                    if collected_tweets not in tweets:
                        tweets.append(collected_tweets)
                else:
                    tweets.append(collected_tweets)

            print "-------The Tweets with Text And Sentiment--------"
            print ""
            print ""
            print tweets
            print ""
            print ""
            # return parsed tweets
            return tweets

            
        
            
 
        except tweepy.TweepError as e:
            # print error (if any)
            print("Error : " + str(e))



# --------------------------------------------------------------------------------------------------------------------
                               
 
def main():
    # creating object of TwitterClient Class
    api = TwitterClient()
    
    # calling function to get tweets; query is used to search people
    tweets = api.get_tweets(query = 'Virat Kohli', count = 1000)

 
    # picking positive tweets from tweets
    PosTweets = [tweet for tweet in tweets if tweet['sentiment'] == 'positive']
    # percentage of positive tweets
    print("Number of Positive Tweets : {}".format(len(PosTweets)))
    print("Positive tweets percentage: {} %".format(100*len(PosTweets)/len(tweets)))

          
    # picking negative tweets from tweets
    NegTweets = [tweet for tweet in tweets if tweet['sentiment'] == 'negative']
    # percentage of negative tweets
    print("Number of Negative Tweets : {}".format(len(NegTweets)))
    print("Negative tweets percentage: {} %".format(100*len(NegTweets)/len(tweets)))

          
    # percentage of neutral tweets
    # print("Number of Neutral Tweets : {}".format(len(tweets - NegTweets - PosTweets)))      
    # print("Neutral tweets percentage: {} %".format(100*len(tweets-NegTweets-PosTweets)/len(tweets)))
 
    # printing first 5 positive tweets
    print("\n\nPositive tweets:")
    for tweet in PosTweets[:10]:
        print(tweet['text'])
 
    # printing first 5 negative tweets
    print("\n\nNegative tweets:")
    for tweet in NegTweets[:10]:
        print(tweet['text'])




 
if __name__ == "__main__":
    # calling main function
    main()
