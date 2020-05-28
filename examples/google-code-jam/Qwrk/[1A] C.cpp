#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

struct POINT
{
	ll x, y;
	POINT(ll _x = 0, ll _y = 0) 
		: x(_x), y(_y) {}

	bool operator==(POINT const &a)
	{
		return a.x == x && a.y == y;
	}
};

#define Det(a,b,c) (ll(b.x - a.x) * ll(c.y - a.y) - ll(b.y - a.y) * ll(c.x - a.x))

#define XCAL {  }

#define PointInRect(p1, p2, p3) (std::min(p1.x, p2.x) <= p3.x && std::min(p1.y, p2.y) <= p3.y && std::max(p1.x, p2.x) >= p3.x && std::max(p1.y, p2.y) >= p3.y)
#define PointInSegment(p1, p2, l) (Det(p1, p2, l) == 0 && PointInRect(p1, p2, l))


std::vector<POINT*> ConvexHull(std::vector<POINT> &p)
{
	std::vector<POINT*> s, w;
	for (auto &pp : p) {
		s.push_back(&pp);
	}
	if (p.size() <= 3) {
		return s;
	}
	std::sort(s.begin(), s.end(), [](POINT *a, POINT *b) {
		return a->x == b->x ? a->y < b->y : a->x < b->x;
	});
	int m = 1;
	for (int x = 0; x < s.size(); ++x) {
		while (w.size() > m && Det((*w[w.size()-2]), (*w[w.size()-1]), (*s[x])) <= 0) {
			w.pop_back();
		}
		w.push_back(s[x]);
	}
	m = w.size();
	for (int x = s.size() - 2; x >= 0; --x) {
		while (w.size() > m && Det((*w[w.size()-2]), (*w[w.size()-1]), (*s[x])) <= 0) {
			w.pop_back();
		}
		w.push_back(s[x]);
	}
	w.pop_back();
	return w;
}

ll dist2(POINT *a, POINT *b)
{
	return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

int closest_to_edge(POINT *p, std::vector<POINT*> &conv)
{
	ll min = 1000000 * 1000000 * 200000;
	int idx = 0;
	for (int i = 0; i < conv.size(); ++i) {
		ll d = dist2(conv[i], p);
		if (min > d) {
			min = d;
			idx = i;
		}
	}
	return idx;
}

bool in_vector(std::vector<POINT*> &vec, POINT *p) 
{
	for (auto &it : vec) {
		if (*it == *p) return true;
	}
	return false;
}

bool on_edge(std::vector<POINT*> &vec, POINT *p)
{
	for (int i = 0; i < vec.size(); ++i) {
		if (PointInSegment((*vec[i]), (*vec[(i+1)%vec.size()]), (*p))) return true;
	}
	return false;
}


int solve(std::vector<POINT> points, int it) 
{
	POINT m = points[it];
	int res = 0;
	std::vector<POINT*> conv = ConvexHull(points);
	while (!(in_vector(conv, &m) || on_edge(conv, &m))) {
		int idx = closest_to_edge(&m, conv);
		for (int i = 0; i < points.size(); ++i) {
			if (points[i] == *conv[idx]) {
				points.erase(points.begin() + i);
				break;
			}
		}
		conv = ConvexHull(points);
		++res;
	}
	return res;
}


int main()
{
	int T;
	std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		int N;
		std::cin >> N;
		std::vector<POINT> points(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> points[i].x >> points[i].y;
		}
		std::cout << "Case #" << c << ":\n";
		std::cout.flush();
		for (int i = 0; i < N; ++i) {
			std::cout << solve(points, i) << '\n';
		}
	}

	
	return 0;
}