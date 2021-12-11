#!/usr/bin/python3
"""this module contains count_words for 0x13-count_words"""

import requests
import operator
from collections import Counter


def count_words(subreddit, word_list, flag=0, display=[]):
    """counts words that match in word_list in titles from hot subreddits"""
    if flag != 0:
        if len(display) > 0:
            print("{:s}: {:d}".format(display[0][0], display[0][1]))
            display.pop(0)
            count_words(subreddit, word_list, 1, display)
            return
        else:
            return
    target = "https://reddit.com/r/{:s}/hot.json".format(subreddit)
    headers = {'user-agent': 'Malicious Bot'}
    raw = requests.get(target, headers=headers, params={'limit': '100'})
    temp = [x['data']['title'].split() for x in raw.json()['data']['children']]
    words = [a.lower() for b in temp for a in b]
    counts = Counter(words)
    out = {key: counts[key] for key in word_list}
    s = sorted(sorted(out.items()), key=operator.itemgetter(1), reverse=True)
    count_words(subreddit, word_list, 1, s)
