#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int t;
int n, m;

struct TreeNode {

	TreeNode(const char* name, int len) {
		memcpy(this->name, name, len);
		this->name[len] = 0;
		next.clear();
	}

	char name[104];
	vector<TreeNode> next;
};

TreeNode root("/", 1);

int GetFilename(const char* filename) {
	int cnt = 0;
	while (*(filename + cnt) != '/' && *(filename + cnt) != 0) {
		cnt++;
	}
	return cnt;
}

int ProcessFile(const char* filename) {
	int res = 0;
	TreeNode* curr = &root;
	const char* curr_pos = filename;
	while (*curr_pos != 0) {
		curr_pos++;
		int len = GetFilename(curr_pos);
		bool found = false;
		for (size_t i = 0; i < curr->next.size(); i++) {
			if (strlen(curr->next[i].name) == len && memcmp(curr_pos, curr->next[i].name, len) == 0) {
				curr = &(curr->next[i]);
				found = true;
				break;
			}
		}
		if (!found) {
			curr->next.push_back(TreeNode(curr_pos, len));
			curr = &(curr->next.back());
			res++;
		}
		curr_pos += len;
	}

	return res;
}

int main() {

	freopen("A-large.in", "r", stdin);
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);

	char filename[104];

	for (int gi = 1; gi <= t; gi++) {
		root.next.clear();
		int ans = 0;
		scanf("%d %d\n", &n, &m);
		for (int i = 0; i < n; i++) {
			fgets(filename, 104, stdin);
			if (filename[strlen(filename) - 1] == '\n') {
				filename[strlen(filename) - 1] = 0;
			}
			ProcessFile(filename);
		}

		for (int i = 0; i < m; i++) {
			fgets(filename, 104, stdin);
			if (filename[strlen(filename) - 1] == '\n') {
				filename[strlen(filename) - 1] = 0;
			}
			ans += ProcessFile(filename);
		}

		printf("Case #%d: %d\n", gi, ans);
	}

	return 0;
}
