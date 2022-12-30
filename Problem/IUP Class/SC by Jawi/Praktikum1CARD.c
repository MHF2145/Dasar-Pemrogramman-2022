#include <stdio.h>
#include <math.h>

int main(){
    //we must first declare the values to hold the values inputted by the problem
    long long int kartu, c1, c2, T1, T2;

    //Scan the value given by the problem
    scanf("%lli %lli %lli", &kartu, &c1, &c2);

    // Karena kita mau mengambil value yang diminta dari index, bukan keseluruhan dari angkanya,
    // contoh (c1=3 dan c2=4 dari urutan kartu 12345678;
    // c1 membawa index 3 yang artinya digit ke 3 dari belakang, yakni 6
    // dan c2 membawa index 4 yang artinya digit ke 4 dari belakang, yakni 5
    // kita gunakan T1 dan T2 untuk value yang di Tunjuk oleh c1 dan c2

    //satu cara yang terpikir adalah menghilangkan angka didepan dan dibelakang T1 dan T2
    // contoh c1=3 dan kartunya 12345678
    // bisa dipisah depan dan belakang digit ke 3 dari belakang yakni 6
    // 12345  6  78


    //cara yang akan kita gunakan menghilangkan digit didepan T adalah dengan mudahnya mencari sisa angka kartu dibagi 10^n
    //sebagai contoh jika 1234 dibagi 100 maka akan bersisa 34 dan jika dibagi 10 bersisa 4
    //tinggal menyesuaikan berapa angka yang akan dihilangkan dengan c1 dan c2


    T1 = kartu%(long long int)pow((double)10,(double)c1);
    T2 = kartu%(long long int)pow((double)10,(double)c2);
    //disini saya tambah "(long long int)" dan "(double)" yang bermaksud mengubah JENIS dari value c1 dan c2 agar bisa di operasikan "pow" (perpangkatan) karena membutuhkan variabel double
    //long long int untuk mengembalikan ke bilangan bulat agar bisa dengan dioperasikan dengan modulo (%)


    //untuk menghilangkan digit dibelakang T, kita bisa mengakali dengan menggunakan fakta bahwa angka dibelakang koma akan dihilangkan oleh bahasa C jika variablenya "int" (bilangan bulat)
    // untuk itu kita tinggal membagi sisa T tadi dengan 10^jumlah digit dibelakang (yakni c-1)


    T1 /= ((long long int)(pow((double)10, (double)c1-1)));
    T2 /= ((long long int)(pow((double)10, (double)c2-1)));
    //disini operasi X/=Y itu sama dengan X= X/Y

    // sekarang kita masukkan kondisi yang diingin soal, yakni



    // menang 100 jika 2 angka sama
    if(T1 == T2){
        printf("Win 100$!");
    }

    // menang 50 jika ganjil dan genap
    else if(T1%2==0 && T2%2!=0 || T1%2!=0 && T2%2==0){
        printf("Win 50$!");
    }
    //operasi && dibaca DAN; sedangkan opersasi || dibaca ATAU

    // kalah jika sama-sama ganjil maupun genap
    else{
        printf("Lose!");
    }

}
