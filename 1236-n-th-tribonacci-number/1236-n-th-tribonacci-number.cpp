class Solution {
public:
    int tribonacci(int n) {
        int fib[40];
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        
        int T_fib[40];
        T_fib[0]=0;
        T_fib[1]=1;
        T_fib[2]=1;
        for(int i=3;i<=n;i++){
            fib[i] = fib[i-1]+fib[i-2]; //fib
            T_fib[i] = T_fib[i-1]+T_fib[i-2]+T_fib[i-3];
            //cout <<  "i "<< i << " " << T_fib[i] << endl;
            if(i==n){
                //cout << T_fib[i-1] << " "<< T_fib[i-2] << " " << T_fib[i-3] << endl;
                //cout << "i = "<< i << " "<< T_fib[i] << endl ;
                return T_fib[i-1]+T_fib[i-2]+T_fib[i-3];
                
            }
        }
        
        //for(int i=0;i<=n;i++)
            //cout << " t_Fib[" << i <<"] = " << T_fib[i];
    
        
        return 0;
    }
};