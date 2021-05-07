#!/usr/bin/python3
"""0-count.py"""
import requests


def count_words(subreddit, word_list, after='', words_dict={}):
    """
    Recursive function that queries the Reddit API, parses
    the title of all hot articles, and prints a sorted count
    of given keywords (case-insensitive, delimited by spaces
    """
    if words_dict == {}:
        words_dict = dict.fromkeys(word_list, 0)
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after}
    headers = {'User-Agent': 'santiagopemo'}
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)
    if response.status_code != 200:
        return
    response_json = response.json()
    data = response_json.get('data')
    if data is None:
        return
    hot_list = data.get('children')
    if hot_list is None:
        return
    for post in hot_list:
        title = post.get('data').get('title').lower().split()
        for word in word_list:
            words_dict[word] += title.count(word.lower())
    after = response_json.get('data').get('after')
    if after is None:
        sort_value = sorted(words_dict.items(), key=lambda i: i[::-1])
        sort_alpha = sorted(sort_value, key=lambda i: i[1], reverse=True)
        for word, value in sort_alpha:
            if value != 0:
                print(f'{word}: {value}')
        return
    count_words(subreddit, word_list, after, words_dict)
