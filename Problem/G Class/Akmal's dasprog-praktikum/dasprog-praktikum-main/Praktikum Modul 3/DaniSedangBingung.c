#include <stdio.h>
#define ull unsigned long long
 
ull modex(ull x, ull y, ull z, ull n){
	ull res = 1;
 
	if(z > 1) x = modex(x, y, z - 1, n);
	
	while(y)
	{
		if(y & 1)
			res = (x * res) % n;
		x = (x * x) % n;
		y >>= 1;
	}
	return res;
}
 
void solve(ull x, ull y, ull z, ull n){
	if(x == 1 || y == 0) printf("1\n");
	else if(x == 0) printf("0\n");
	else if(y == 1 || z == 0) printf("%llu\n", (x % n) + 1);
	else printf("%llu\n", modex(x, y, z, n) + 1);
}
 
int main(){
	ull x, y, z, n;
	scanf("%llu %llu %llu %llu", &x, &y, &z, &n);
 
	solve(x, y, z, n);
	return 0;
}
