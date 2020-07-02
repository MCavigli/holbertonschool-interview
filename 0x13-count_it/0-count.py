#!/usr/bin/python3
import requests


def count_words(subreddit, word_list):
    ''' Counts words in titles of subreddits '''

    URL = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    USERAGENT = {'User-Agent':
                 'Unix:com.holberton.apiadvanced:task1 (by /u/_marc_marc_)'}
    req = requests.get(URL, headers=USERAGENT)
    if req.status_code is not 200:
        print(None)
        return
    jreq = req.json()
    data_path = jreq['data']['children']
    for i in range(1):
        print(data_path[i]['data']['title'])
