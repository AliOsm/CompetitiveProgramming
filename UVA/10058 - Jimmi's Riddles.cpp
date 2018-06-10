/*
	Idea:
		- Deconstruct the statement in actions and check
			if each action is a correct action.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
char in[N];
int len, noun_size, verb_size, article_size;
string cur;
string noun[] = { "tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse" };
string verb[] = { "hate", "love", "know", "like", "hates", "loves", "knows", "likes" };
string article[] = { "a", "the" };
vector<string> action;

bool check() {
	action.clear();

	string tmp = "";
	for(int i = 0; i < cur.length(); ++i) {
		if(cur[i] == ' ' || i == cur.size() - 1) {
			if(tmp.empty()) {
				tmp.clear();
				continue;
			}

			if(i == cur.size() - 1 && isalpha(cur[i]))
				tmp += cur[i];

			if(!binary_search(noun, noun + noun_size, tmp) &&
				 !binary_search(verb, verb + verb_size, tmp) &&
				 !binary_search(article, article + article_size, tmp) &&
				 tmp != "and")
				return false;
			action.push_back(tmp);
			tmp.clear();
		} else
			tmp += cur[i];
	}
	// there is no weird words

	int verb_index = -1;
	for(int i = 0; i < action.size(); ++i)
		if(binary_search(verb, verb + verb_size, action[i])) {
			if(verb_index != -1)
				return false;
			verb_index = i;
		}
	if(verb_index == -1)
		return false;
	// it is an action

	if(verb_index == 0)
		return false;
	// there is a left hand size

	if(verb_index == action.size() - 1)
		return false;
	// there is a right hand size

	bool what;

	what = true;
	for(int i = 0; i < verb_index; ++i) {
		if(what) {
			if(binary_search(article, article + article_size, action[i]))
				++i;
			if(!binary_search(noun, noun + noun_size, action[i]))
				return false;
			what = !what;
		} else {
			if(action[i] != "and")
				return false;
			what = !what;
		}
	}
	// the left hand side is an active list

	what = true;
	for(int i = verb_index + 1; i < action.size(); ++i) {
		if(what) {
			if(binary_search(article, article + article_size, action[i]))
				++i;
			if(!binary_search(noun, noun + noun_size, action[i]))
				return false;
			what = !what;
		} else {
			if(action[i] != "and")
				return false;
			what = !what;
		}
	}
	// the right hand side is an active list

	return true;
	// it is a statement
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	noun_size = sizeof(noun) / sizeof(noun[0]);
	verb_size = sizeof(verb) / sizeof(verb[0]);
	article_size = sizeof(article) / sizeof(article[0]);

	sort(noun, noun + noun_size);
	sort(verb, verb + verb_size);
	sort(article, article + article_size);

	while(fgets(in, sizeof in, stdin)) {
		len = strlen(in);
		in[len] = '\0';

		bool ok = true;
		for(int i = 0; i < len; ++i) {
			cur.clear();
			while(i < len && in[i] != ',')
				cur += in[i], ++i;
			if(!check()) {
				ok = false;
				break;
			}
		}

		if(ok)
			puts("YES I WILL");
		else
			puts("NO I WON'T");
	}

	return 0;
}
