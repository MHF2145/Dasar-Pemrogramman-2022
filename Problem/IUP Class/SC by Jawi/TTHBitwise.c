// Function to print order of movement
// of N disks across three rods to place
// all disks on the third rod from the
// first-rod using binary representation

int FungsiPenggaris(long long int g){
    long long int counter=0;
        for(long long int j=0;pow(2, j)<=g;j++){
            if(g%(long long int)pow(2, j)!=0){
                break;
            }
            else{
                counter++;
            }
        }

        return counter;
}

long long int GanjilGenap1(long long int x){
    int outfut;
    if(((x & x - 1) % 3 + 1)==2){
        return 3;
    }
    else if(((x & x - 1) % 3 + 1)==3){
        return 2;
    }
    else if(((x & x - 1) % 3 + 1)==1){
        return 1;
    }
}

long long int GanjilGenap2(long long int x){
    int outfut;
    if((((x | x - 1) + 1) % 3 + 1)==2){
        return 3;
    }
    else if((((x | x - 1) + 1) % 3 + 1)==3){
        return 2;
    }
    else if ((((x | x - 1) + 1) % 3 + 1)==1){
        return 1;
    }
}


void TowerOfHanoi(long long int N, long long int K)
{
    // Iterate over the range [0, 2^N - 1]
    long long int x = K;
        {

        // Print the movement
        // of the current rod
        if(N%2!=0){
        printf("%lld : %lld => %lld", FungsiPenggaris(K), ((x & x - 1) % 3 + 1) , (((x | x - 1) + 1) % 3 + 1));
        }
        else{
        printf("%lld : %lld => %lld", FungsiPenggaris(K), GanjilGenap1(x) , GanjilGenap2(x));
        }
    }
}

// Driver Code
int main()
{
    int T;
    long long int N;
    long long int K;

    scanf("%d", &T);

    for(int i=0;i<T; i++){
        scanf("%lld %lld", &N, &K);
        TowerOfHanoi(N, K);
        printf("\n");
    }

    return 0;
}
