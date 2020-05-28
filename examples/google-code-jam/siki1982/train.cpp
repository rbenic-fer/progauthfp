#include <stdio.h>
#include <fstream>
#include <map>


using namespace std;

struct Time
{
  int h;
  int m;
  int a;

  Time() : h(0), m(0), a(0) {}

  Time(string time, int arr)
  {
    h = atoi(time.substr(0,2).c_str());
    m = atoi(time.substr(3,2).c_str());
    a = arr;
  }

  Time operator+(int m)
  {
    Time res;

    res.m = (this->m + m)%60;
    res.h = this->h + (this->m + m - (this->m + m)%60)/60;
    res.a = 0;

    return res;
  }
};

struct CmpTime
{
  bool operator()(Time a, Time b)
  {
    if (a.h < b.h) return true;
    else if (a.h == b.h && a.m < b.m) return true;
    else if (a.h == b.h && a.m == b.m && a.a < b.a) return true;
    else return false;
  }
};


uint32_t NumTrains(uint32_t num_trip, map<Time, uint32_t, CmpTime> &sch)
{
  uint32_t res = 0;
  uint32_t trip = 0;
  uint32_t num_trains = 0;
  
  for (map<Time, uint32_t, CmpTime>::iterator it = sch.begin(); it != sch.end() && trip < num_trip; it++)
  {
    if (it->first.a == 1)
    {
      if (num_trains >= it->second) num_trains -= it->second;
      else
      {
	res += it->second - num_trains;
	num_trains = 0;
      }
      trip += it->second;
    }
    else
    {
      num_trains += it->second;
    }
    //fprintf(stdout, "%d, %d, %d, %d, %d, %d\n", it->first.h, it->first.m, it->first.a, it->second, num_trains, res);
  }

  return res;
}


int main()
{
  ifstream input("B-large.in");
  //ifstream input("input.txt");
  if (input.fail())
  {
    fprintf(stderr, "Cannot open input file\n");
    exit(1);
  }

  uint32_t num_cases;
  input >> num_cases;

  for(uint32_t i = 1; i <= num_cases; i++)
  {
    map<Time, uint32_t, CmpTime> sch_a, sch_b;
    map<Time, uint32_t, CmpTime>::iterator it;
    sch_a.clear();
    sch_b.clear();


    uint32_t turntime;
    input >> turntime;

    uint32_t trip_a;
    uint32_t trip_b;

    input >> trip_a;
    input >> trip_b;

    for(uint32_t j = 0; j < trip_a; j++)
    {
      string time;
      input >> time;
      Time t_a(time, 1);
      if ((it = sch_a.find(t_a)) == sch_a.end())
	sch_a[t_a] = 1;
      else
	it->second++;

      input >> time;
      Time t_btmp(time, 0);
      Time t_b = t_btmp + turntime;
      if ((it = sch_b.find(t_b)) == sch_b.end())
	sch_b[t_b] = 1;
      else
	it->second++;
    }

    for(uint32_t j = 0; j < trip_b; j++)
    {
      string time;
      input >> time;
      Time t_b(time, 1);
      if ((it = sch_b.find(t_b)) == sch_b.end())
	sch_b[t_b] = 1;
      else
	it->second++;

      input >> time;
      Time t_atmp(time, 0);
      Time t_a = t_atmp + turntime;
      if ((it = sch_a.find(t_a)) == sch_a.end())
	sch_a[t_a] = 1;
      else
	it->second++;

    }
    
    fprintf(stdout, "Case #%u: %u %u\n", i, NumTrains(trip_a, sch_a), NumTrains(trip_b, sch_b)); 
  }

}
