#!/usr/bin/python3
''' Module that has code to count number of words in hot titles on Reddit '''
import requests


def createDict(word_list, titles):
    ''' Creates a dictionary to count the number of words in title '''
    word_dict = {}
    for word in word_list:
        word_dict[word] = 0

    for t in titles:
        t = t.split()
        for w in t:
            if w in word_dict:
                word_dict[w] += 1

    for key, value in word_dict.items():
        if value > 0:
            print('{}: {}'.format(key, value))
    return


def count_words(subreddit, word_list, titles=[], after_val='amillionbux'):
    ''' Counts words in titles of subreddits '''

    if not after_val:
        createDict(word_list, titles)
        return

    URL = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    USERAGENT = {'User-Agent':
                 'Unix:com.holberton.interview:task (by /u/_marc_marc_)'}
    params = {'limit': 100}
    params['after'] = after_val

    req = requests.get(URL,
                       headers=USERAGENT,
                       params=params)
    if req.status_code is not 200:
        return (None)
    jreq = req.json()
    data = jreq['data']
    data_path = jreq['data']['children']
    if data:
        for t in data_path:
            titles.append(t['data']['title'])
        return (count_words(subreddit,
                            word_list,
                            titles,
                            data['after']))
    else:
        return (None)
