#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	size_t tN;
	cin >> tN;

	while (tN--) {
	    size_t N, K;
	    cin >> N >> K;
	    int A[100];
	    for (size_t i = 0; i < N; ++i) {
	        cin >> A[i];
	    }
	    sort(&A[0], &A[N]);
	    bool found = false;
	    if (N >= 4) {
	        for (size_t i0 = 0; i0 < N-3; ++i0) {
	            if (i0 > 0 && A[i0] == A[i0-1]) continue;
	            for (size_t i1 = i0+1; i1 < N-2; ++i1) {
    	            if (i1 > i0+1 && A[i1] == A[i1-1]) continue;
   	                for (size_t i2 = i1+1; i2 < N-1; ++i2) {
        	            if (i2 > i1+1 && A[i2] == A[i2-1]) continue;
  	                    for (size_t i3 = i2+1; i3 < N; ++i3) {
            	            if (i3 > i2+1 && A[i3] == A[i3-1]) continue;
  	                        //cout << A[i0] << " " << A[i1] << " " << A[i2] << " " << A[i3] << " $";
  	                        if (A[i0]+A[i1]+A[i2]+A[i3] == K) {
  	                            cout << A[i0] << " " << A[i1] << " " << A[i2] << " " << A[i3] << " $";
  	                            found = true;
  	                        }
  	                    }
   	                }
	            }
	        }
	    }
	    if (!found)
	        cout << -1;
	    cout << endl;
	}

	return 0;
}
