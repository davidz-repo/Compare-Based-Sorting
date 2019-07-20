#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

double cacuprob(int n, int ni){
	double ans = 1;
	for(double a=n; a>n-ni+1; a--) ans/=a;
	return ans;
}
double iter_factorial(unsigned int n)
{
    double ret = 1;
    for(double i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

double binomial(int a, int b){
	if(b==0) return 1;
	double ans = 1;
	for(double n=a; n>a-b; n--) ans*=n;
	for(double n=1; n<=b; n++) ans/=n;
	return ans;
}

double nprob(int a, int b, double p){
	return binomial(a,b)*pow(p,b);
}

int main() {

	const int n = 10000;
	const int k = 40;

	int firstk = 0;
    for(int i=1; i<=k; i++){

    	int mid = (k+1)/2;
    	int c = ceil(log2(k));
    	int ith_comp = 0;
    	while(c > 0){
    		if(i > mid){
    			ith_comp = c;
    			break;
    		}
    		mid = (mid+1)/2;
    		c--;
    	}

    	//cout << "i = " << i << ", comp = " << ith_comp << endl;
    	firstk += ith_comp;
    }

    int after = (ceil(log2(k)) + 1 )*(n-k);
    int test = (ceil(log2(k)) + 1 )*(n);

    cout << "total comp for first k element = " << firstk << endl;
    cout << "total comp after kth = " << after << endl;
    cout << "total comp = " << firstk + after << endl;
    cout << "approx comp = " << test << endl;

    cout << "----------------------------------------------" << endl;

    const int times = 1000;
    double ans = 0;

    for(int ni=1; ni<=n; ni++){
		double comp = (ceil(log2(k)) + 1 )*(ni) + (n-ni);
    	double prob = cacuprob(n, ni); //iter_factorial(n-ni+1)/iter_factorial(n);
    	double occur_once = 1 - pow((1-prob), times);
    	//cout << prob << endl;

    	ans += comp*occur_once;
    }

    cout << "avg WC = " << ans << endl;

    cout << "----------------------------------------------" << endl;

    double avg = 0;
    for(int numi=1; numi<=n; numi++){

     	double bi_comp = ceil(log2(k)) + 1;
     	double prob = 0;

     	for(int i=k+1; i<=n; i++){
     		double probi;
     		double avg_number_front = (double)(n-numi)/(n-1) * (i-1);

     		if(avg_number_front >= k) probi = 1;
     		else probi = avg_number_front/k;

     		prob += probi/n;
     	}

     	//cout << numi << ": " << prob << endl;
	    avg += bi_comp*(1-prob) + prob;

     }

    cout << "expected avg comp = " << avg << endl;

    return 0;
}
