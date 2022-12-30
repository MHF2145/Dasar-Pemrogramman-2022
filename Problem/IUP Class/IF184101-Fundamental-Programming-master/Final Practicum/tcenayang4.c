#include <stdio.h>

struct data {
    char name[10000];
    int age;
    int phone;
    char bestie[10000];
};

struct area {
    char name[10000];
    int population;
    int area;
};

/*
sample input:
2
Surabaya 2
Brel
20
081212341234
Bob
19
081778787878
Surabaya 1
Ariel
25
081354781212 2
Brel Bob
Bob Ariel

sample output:
Surabaya
Name: Brel
Age: 20
Phone Number:081212341234
His/Her bestie is: Bob
His/Her contact info is as follows
Name: Bob
Age: 19
Phone Number:081778787878
Name: Bob
Age: 19
Phone Number:081778787878
His/Her bestie is: Ariel
His/Her contact info is as follows
Name: Ariel
Age: 25
Phone Number:081354781212
Surabaya
Name: Ariel
Age: 25
Phone Number:081354781212
His/Her bestie is: No one

make it
*/

int main() {
    int n;
    scanf("%d", &n);
    struct data data[n];
    struct area area[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", area[i].name);
        scanf("%d", &area[i].population);
        for (int j = 0; j < area[i].population; j++) {
            scanf("%s", data[j].name);
            scanf("%d", &data[j].age);
            scanf("%d", &data[j].phone);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", data[i].bestie);
    }
    return 0;
}

/*
int main() {
    int n;
    scanf("%d", &n);
    struct data arr[n];

    char area[10000];
    int population[10000];
    // input the city name and population
    for (int i = 0; i < n; i++) {
        scanf("%s", area[i]);
        scanf("%d", &population[i]);
        // input the name, age, phone number, and best friend of each person
        for (int i = 0; i < population[i]; i++) {
            scanf("%s", arr[i].name);
            scanf("%d", &arr[i].age);
            scanf("%d", &arr[i].phone);
        }
    }
    // input the relationships between the people
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i].bestie);
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", area[i]);
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Phone Number: %d\n", arr[i].phone);
        printf("His/Her contact is as follows\n");
        printf("%s\n", arr[i].bestie);
    }

    return 0;
}
*/

/*
The number of areas that Brel will data
The name of the area
The amount of people living in said area
Name, age and phone number of each person
The amount of friends(n)
n amount of FriendA and FriendB

2			    =>	The number of areas that Brel will data
    Surabaya		=> 	The name of the area
    2			    =>	The amount of people living in area
        Brel			=>	Name
        20			    =>	Age
        081212341234	=>	Phone
        Bob			    =>	Name
        19			    =>	Age
        081778787878	=>	Phone
    Surabaya		=> 	The name of the area
    1			    =>	The amount of people living in area
        Ariel			=>	Name
        25			    =>	Age
        081354781212	=> 	Phone
    2			    =>	Amount of friends
        Brel Bob		=>	FriendA and FriendB
        Bob Ariel		=>	FriendA and FriendB
*/