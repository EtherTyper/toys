#include "trie.h"

TrieNode* trie_next(TrieNode* node, const char letter) {
	for (size_t i = 0; i < node->n; i++) {
		if (node->chars[i] == letter) {
			if (i == 0) {
				return node->next[0];
			}

			const int prev = i-1;
			char	  c0 = node->chars[prev];
			TrieNode* n0 = node->next[prev];

			node->chars[prev] = letter;
			node->next[prev]  = node->next[i];

			node->chars[i] = c0;
			node->next[i]  = n0;

			return node->next[prev];
		}
	}

	return NULL;
}


void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
	node->n += 1;
	node->chars = (char*)realloc(node->chars, node->n);
	node->next  = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

	node->chars[node->n - 1] = letter;
	node->next [node->n - 1] = newnode;
}

