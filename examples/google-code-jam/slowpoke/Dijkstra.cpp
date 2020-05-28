#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct D{
	char val;
	bool neg;

	D operator*(const D &rhs) const;
	bool operator==(const D &rhs) const{
		return val == rhs.val && neg == rhs.neg;
	};
};

const char ONE = 0;
const char I = 1;
const char J = 2;
const char K = 3;

const D kd = { K, false };
const D minOne = { ONE, true };
const D id = { I, false };

D table[4][4] = {
	{ { ONE, false }, { I, false }, { J, false }, { K, false } },
	{ { I, false }, { ONE, true }, { K, false }, { J, true } },
	{ { J, false }, { K, true }, { ONE, true }, { I, false } },
	{ { K, false }, { J, false }, { I, true }, { ONE, true } }
};

D D::operator*(const D &rhs) const{
	D ret = table[val][rhs.val];
	ret.neg ^= neg ^ rhs.neg;
	return ret;
}

bool comp(){
	int L, X, len;
	cin >> L >> X;
	len = L*X;
	string s, tmp;
	cin >> tmp;
	transform(tmp.begin(), tmp.end(), tmp.begin(), [](char c){return (char)(c - 'i' + 1); });
	s.reserve(len);
	for (int i = 0; i < X; ++i){
		s += tmp;
	}

	if (len < 3){
		return false;
	}

	D right = { ONE, false };

	int r = -1;
	for (int i = len - 1; i >= 0; --i){
		right = D{ s[i], false } * right;
		if (r == -1 && right == kd){
			r = i;
		}
	}

	if (!(right == minOne)){
		return false;
	}

	D left = { ONE, false };
	for (int i = 0; i < r-1; ++i){
		left = left * D{ s[i], false };
		if (left == id)
			return true;
	}

	return false;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		bool res = comp();
		cout << "Case #" << i << ": " << (res? "YES" : "NO") << endl;
	}
}