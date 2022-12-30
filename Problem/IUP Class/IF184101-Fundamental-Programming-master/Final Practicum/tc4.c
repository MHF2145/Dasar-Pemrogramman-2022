/*
Brel is an officer working for China, he wants to data every 
resident in the area, The data will contain the name of the area 
and the person who is living in said area.
Brel also needs to data the identity of the person, which 
includes the name, age, phone number and closest friend of that 
person.
Here's the catch Brel needs to access the closest friend as he 
is not the only one doing this job and doesn't jeopardize his 
position if somebody has the same name. Help Brel make program 
to do this!
Look at the sample testcase below for clarification

INPUT FORMAT
The number of areas that Brel will data
The name of the area
The amount of people living in said area
Name, age and phone number of each person
The amount of friends(n)
n amount of FriendA and FriendB

CONSTRAINTS
1 <= number of areas <= 10
1 <= name of the area <= 50 without space
1 <= The amount of people living in said area <= 10
1 <= name <= 50 without space
1 <= age <= 100
1 <= phone number <= 50 without space

OUTPUT FORMAT
Name of the area
all the residents and friends in the area
if the residents have a bestfriend, print his/her information based on the 
sample output below if not, output "His/Her bestie is: No one"

Sample input 1
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

Sample output 1
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
*/
#include <stdio.h>
#include <string.h>

struct data {
    char name[10000];
    int age;
    int phone;
    char bestie[10000];
};

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
        printf("%s", area[i]);
        printf("Name: %s", arr[i].name);
        printf("Age: %d", arr[i].age);
        printf("Phone Number: %d", arr[i].phone);
        printf("His/Her contact is as follows");
        printf("%s", arr[i].bestie);
    }
    return 0;

}