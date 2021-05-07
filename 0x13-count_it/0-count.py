#!/usr/bin/python3
"""Count it module"""
import requests
from sys import argv


def count_words(subreddit, word_list, after="", words_dict={}):
    """
    Recursive function that queries the Reddit API, parses
    the title of all hot articles, and prints a sorted count
    of given keywords (case-insensitive, delimited by spaces
    """
    if words_dict == {}:
        words_dict = dict.fromkeys(word_list, 0)
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                 after)
    headers = {"User-Agent": "santiagopemo"}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        return
    response = response.json()
    hot_list = response.get('data', {}).get('children', None)
    for post in hot_list:
        title = post.get('data').get('title').lower().split()
        for word in word_list:
            words_dict[word] += title.count(word.lower())
    after = response.get('data').get('after')
    if after is None:
        sort_value = sorted(words_dict.items(), key=lambda i: i[::-1])
        sort_alpha = sorted(sort_value, key=lambda i: i[1], reverse=True)
        for word, value in sort_alpha:
            if value != 0:
                print('{}: {}'.format(word.lower(), value))
        return
    return count_words(subreddit, word_list, after, words_dict)
