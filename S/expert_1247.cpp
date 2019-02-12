#include <iostream>
#include <vector>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std; 

typedef struct point{
	int x;
	int y;
}point;


int point_num;
bool map[101][101];
vector<point> points;
point start_p;
point end_p;
int min_dis;
int x = 0;

int cal_distance(point p1, point p2){
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void solve(point p1, point p2, int count, int total_dis){
	int dis = total_dis + cal_distance(p1, p2);
	if(count == point_num){
		dis = dis + cal_distance(p2, end_p);
		if(dis <= min_dis){
			min_dis = dis;
		}
		return;
	}
	
	if(dis > min_dis){
		return;
	}
	
	for(int i = 0; i < point_num; i++){
		if(map[points[i].x][points[i].y] == true){
			continue;
		}	
		map[points[i].x][points[i].y] = true;
		solve(p2, points[i], count+1, dis);
		map[points[i].x][points[i].y] = false;
	}
	
	
}

int main(int argc, char** argv) {
	int test_cnt;
	cin >> test_cnt;
	for(int t = 0; t < test_cnt; t++){
		min_dis = 987654321;
		point tmp;
		points.clear();
		cin >> point_num >> start_p.x >> start_p.y >> end_p.x >> end_p.y;;
		
		for(int j = 0; j < point_num; j++){
			cin >> tmp.x >> tmp.y;
			points.push_back(tmp);
		}
		
		
		for(int j = 0; j < point_num; j++){
			map[points[j].x][points[j].y] = true;
			solve(start_p, points[j], 1, 0);
			map[points[j].x][points[j].y] = false;
		}
		
		cout << "#" << t+1 << " " << min_dis << endl;

	}
	return 0;
}
