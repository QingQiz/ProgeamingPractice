#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <ctime>
using namespace std ;

const int MAXN = 109 ;
const int MAXM = 5009 ;
const double inf_r = 500.00 ;

int N , M , First[MAXN] , tot ;
struct {
	int next ;
	int node ;
	int capc ;
	double cost ;
	int oppo ;
} E[MAXM * 4 + MAXN * 4] ;

void AddEdge( int u , int v , int capcity , double cost ) {
	E[tot].next = First[u] ;
	First[u] = tot ;
	E[tot].node = v ;
	E[tot].capc = capcity ;
	E[tot].cost = cost ;
	E[tot].oppo = tot+1 ;
	tot ++ ;
	E[tot].next = First[v] ;
	First[v] = tot ;
	E[tot].node = u ;
	E[tot].capc = 0 ;
	E[tot].cost = 0.0 - cost ;
	E[tot].oppo = tot-1 ;
	tot ++ ;
}

void Init() {
	cin >> N >> M ;
	for ( int i = 0 ; i <= N + 1 ; i ++ ) First[i] = -1 ;
	tot = 0 ;

	for ( int i = 1 ; i <= N ; i ++ ) {
		int s , b ; cin >> s >> b ;
		AddEdge( 0 , i , s , 0.0 ) ;
		AddEdge( i , N+1 , b , 0.0 ) ;
	}
	for ( int i = 1 ; i <= M ; i ++ ) {
		int u , v , c ; double p ;
		cin >> u >> v >> c >> p ;
		if (c >= 2) {
			AddEdge(u, v, 2, 0);
			AddEdge(u, v, c-2, -1.0 * log(1.0-p));
		} else if ( c == 1 ) {
			AddEdge(u, v, 1, 0);
			AddEdge(u, v, 0, -1.0 * log(1.0-p));
		} else if ( c == 0 ) {
			AddEdge(u, v, 0, 0);
			AddEdge(u, v, 0, -1.0 * log(1.0-p));
		}
	}
}

double SPFA_ret ;
bool inQ[MAXN] ;
double sp[MAXN] ;
int lastE[MAXN] ;

bool SPFA( int S , int T ) {
	for ( int i = 0 ; i <= N+1 ; i ++ ) {
		inQ[i] = false ;
		sp[i] = inf_r ;
	}
	sp[S] = 0.0 ; inQ[S] = true ;
	queue<int> Q ; Q.push(S) ;
	while (!Q.empty()) {
		int x = Q.front() ; Q.pop() ; inQ[x] = false ;
		for ( int e = First[x] ; e != -1 ; e = E[e].next ) {
			int y = E[e].node ;
			if ( E[e].capc > 0 && sp[x] + E[e].cost <= sp[y] - 1e-15 ) {
				sp[y] = sp[x] + E[e].cost ;
				lastE[y] = e ;
				if ( !inQ[y] ) {
					inQ[y] = true ;
					Q.push(y) ;
				}
			}
		}
	}
	if ( sp[T] == inf_r ) return false ;
	SPFA_ret = sp[T] ;
	//cerr << "True!  sp[T] = " << sp[T] << "\n" ;
	for ( int now = T ; now != S ; ) {
		//cerr << now << "<-" ;
		int last = E[E[lastE[now]].oppo].node ;
		E[lastE[now]].capc -- ;
		E[E[lastE[now]].oppo].capc ++ ;
		now = last ;
	}
	//cerr << S << "\n" ;
	return true ;
}

void Solve() {
	double ans = 0.0 ;
	for (;;) {
		if (SPFA(0 , N+1)) ans += SPFA_ret ;
		else break ;
	}
	cout.precision(2) ;
	cout << fixed << 1.0 - exp(-1.0 * ans) << "\n" ;
}

int main() {
    freopen("D_in.txt","r",stdin);
    freopen("D_out.txt","w",stdout);
	int Test ; cin >> Test ;
	int kase=0;
	while ( Test -- ) {
		Init() ;
		cout<<"Case #"<<++kase<<": ";
		Solve() ;
	}
	//fprintf(stderr,"%.2f s\n",clock()*1.0/CLOCKS_PER_SEC);
}
