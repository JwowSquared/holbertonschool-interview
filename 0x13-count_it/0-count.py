#!/usr/bin/python3
"""this module contains count_words for 0x13-count_words"""

from collections import Counter
import operator
import requests


def count_words(sub, matches, wlist=[], flag=0, display=[], after=""):
    """counts words that match in word_list in titles from hot subreddits"""
    if flag != 0:
        if len(display) > 0:
            print("{:s}: {:d}".format(display[0][0], display[0][1]))
            display.pop(0)
            count_words(sub, matches, flag=1, display=display)
        return
    target = "https://reddit.com/r/{:s}/hot.json".format(sub)
    headers = {'user-agent': 'Malicious Bot'}
    params = {'limit': '100', 'after': after}
    raw = requests.get(target, headers=headers, params=params)
    temp = [x['data']['title'].split() for x in raw.json()['data']['children']]
    words = [a.lower() for b in temp for a in b]
    wlist += words
    if len(raw.json()['data']['children']) < 100:
        counts = Counter(wlist)
        out = {key: counts[key] for key in matches}
        temp = sorted(out.items())
        s = sorted(temp, key=operator.itemgetter(1), reverse=True)
        count_words(sub, matches, flag=1, display=s)
    else:
        after = raw.json()['data']['after']
        count_words(sub, matches, wlist=wlist, after=after)
